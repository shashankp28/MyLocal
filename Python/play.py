import json
import sys
import math
import socketio
import numpy as np
import random

n = 5



troop_name = ["Gamora", "StarLord", "Drax", "Groot", "Rocket"]
max_h = [150, 200, 100, 75, 125,]
d = {"Health": 150, "Attack": 70, "Vision": 1, "Speed": 1}
gr = {"Health": 200, "Attack": 25, "Vision": 2, "Speed": 1}
s = {"Health": 100, "Attack": 35, "Vision": 5, "Speed": 2}
r = {"Health": 75, "Attack": 35, "Vision": 4, "Speed": 3}
g = {"Health": 125, "Attack": 50, "Vision": 2, "Speed": 2}
troop_list = [g, s, d, gr, r]
troop_data = dict()
estimated_enemy_health = dict()
path = dict()
do_we_have = None
IS_predict = []
forbidden = []
stagnent = dict()
for i in range(n): 
    for j in range(n): IS_predict.append((i, j))
for i in range(5):
    path[troop_name[i]] = []
    stagnent[troop_name[i]] = 0
    troop_data[troop_name[i]] = troop_list[i] 
    estimated_enemy_health[troop_name[i]] = max_h[i]
action_list = ["move", "special", "attack"]
maze = [[0 for i in range(n)] for i in range(n)]
o = None

def exp_w(n):
    return math.exp(n)
        
def s_to_t(coord):
    coord = coord.split(', ')
    x = int(coord[0][1:])
    y = int(coord[1][0:-1])
    return (x, y)
    
def average(lis):
    x, y = [0, 0]
    m = len(lis)
    for i in range(m): x, y = [x+lis[i][0], y+lis[i][1]]
    return (x//m, y//m)

def has_IS(cell):
    return len(IS_predict)==1 and (IS_predict[0]==cell.parent.parent.present)

def is_enemy_present(cell):
    temp = cell.guardians_present
    dic = dict()
    for i in temp:
        if(i["belongs_to"] == "opponent"): dic[i["guardian_name"]] = cell.coordinate
    return dic if len(dic)!=0 else None

def can_attack(c1, c2):
    if c1.present[0]!=c2.coordinate[0] and c1.present[1]!=c2.coordinate[1]: return 0
    elif distance(c1.present, c2.coordinate) > troop_data[c1.name]["Vision"]: return 0
    else: 
        our_troop = c2.parent.parent
        return (troop_data[c1.name]["Attack"] - o["movegen"][our_troop.name]["health"])
def compare(coordinate1, coordinate2, s):
    dist = abs(coordinate1[1] - coordinate2[1]) + abs(coordinate1[0] - coordinate2[0])
    return dist<=s

def distance(c1, c2):
    return abs(c1[1] - c2[1]) + abs(c1[0] - c2[0])
    
def is_feedback(code_word):
    yes = 0
    temp = o["feedback"]
    for i in temp:
        if(i["code"] == code_word):
            yes = 1
            return i["data"]
    if(yes == 0): return False

def update(lis):
    global IS_predict, maze
    x = is_feedback("CLUE")
    if x:
        guard_coord = s_to_t(o["movegen"][x["guardian"]]["current_cell"]["coordinates"])
        if x["clue_type"] == "get_direction_to_infinity_stone":
            i=0
            while i<len(IS_predict):
                n = x["direction"]
                if n!=slope(guard_coord, IS_predict[i]):
                    print("wrong slope:", slope(guard_coord, IS_predict[i]), guard_coord, IS_predict[i], n)
                    IS_predict.remove(IS_predict[i])
                    i-=1
                i+=1
    print(is_feedback("GUARDIAN_PICKED_UP_INFINITY_STONE"))
    for i in lis:
        x, y = i.coordinate
        if i.cell_type=="Normal": maze[x][y]='n'
        if i.cell_type=="HealPoint": maze[x][y]='p'
        if i.cell_type=="Beast": maze[x][y]='b'
        if i.cell_type=="Teleporter": maze[x][y]='t'
        if i.cell_type=="Clue": maze[x][y]='c'
    for i in lis:
        if (i.coordinate in IS_predict):
            if i.is_powerStone_present == "False":
                print("no power stone at:", i.coordinate)
                print(o)
                IS_predict.remove(i.coordinate)
            else: 
                print("Power stone present", i.is_powerStone_present)
                print(o)
                IS_predict = [i.coordinate]
                break
def slope(c1, c2):
    if c1[0]==c2[0]:
        if c1[1]<c2[1]: return 'inf'
        if c1[1]>c2[1]: return '-inf'
    elif c1[1]==c2[1]:
        if c1[0]<c2[0]: return '0.0'
        if c1[0]>c2[0]: return '-0.0'
    else: return str(round((c2[1]-c1[1])/(c2[0]-c1[0]), 2))
class Root:
    def __init__(self):
        self.troops = []
class Troop:
    def __init__(self, n, pre):
        self.name = n
        self.present = pre
        self.actions = []
        self.parent = None 
class Action:
    def __init__(self, a):
        self.type = a
        self.cells = []
        self.child = None
        self.parent = None
class Cell:
    def __init__(self, coord, ct, isp, gp):
        self.coordinate = coord
        self.cell_type = ct
        self.parent = None
        self.is_powerStone_present = isp
        self.guardians_present = gp
        self.heur = 0
    def heuristic(self):
        troop = self.parent.parent
        action = self.parent
        if action.type=="move":
            if o["movegen"][troop.name]["health"]==0: self.heur = -float('inf')
            if not compare(self.coordinate, troop.present.coordinate, troop_data[troop.name]["Speed"]): self.heur = -float('inf')
            if self.cell_type=="Normal": 
                self.heur += 5*exp_w(stagnent[troop.name]) + 1000*(maze[self.coordinate[0]][self.coordinate[1]]==0)  + 100*(self.coordinate in IS_predict)
            if self.cell_type=="HealPoint":
                for l in action.cells: l.heur += 50*(troop_data[troop.name]["Health"] - o["movegen"][troop.name]["health"])/(30*distance(self.coordinate, l.coordinate) + 1)
            if self.cell_type=="Teleporter":
                for l in action.cells: l.heur += 50/(3*distance(self.coordinate, l.coordinate) + 1)
            if self.cell_type=="Clue":
                for l in action.cells: l.heur += 80/(3*distance(self.coordinate, l.coordinate) + 1)
            if self.cell_type=="Beast":
                for l in action.cells: l.heur += 1/(distance(self.coordinate, l.coordinate) - 0.0001)
            lis = is_enemy_present(self)
            if lis:
                for m in lis:
                    for l in action.cells: l.heur += 20*can_attack(Troop(m, lis[m]), l)
            for l in action.cells:
                if len(IS_predict)==1:
                    if not troop.present==IS_predict[0]: l.heur += 300/(distance(IS_predict[0], l.coordinate)+0.1)
                    else: l.heur += 200*int((l.coordinate in path[troop.name])) + 100/(distance(base, l.coordinate) + 1)
            if troop.present.cell_type=="HealPoint": self.heur -= exp_w((troop_data[troop.name]["Health"] - o["movegen"][troop.name]["health"])/10) 
        if action.type=="attack":
            if o["movegen"][troop.name]["health"]==0: self.heur = -float('inf')
            lis = is_enemy_present(self)
            if lis and len(lis) != 0:
                    self.heur += 1000
            if self.cell_type=="Beast":
                self.heur += 2500
            # Using starlord's special powers
            if(troop_data[troop.name] == "StarLord"):
                neighbours_starlord = troop_data[troop.name]["neighbour_cells"]
                for direction in neighbours_starlord:
                    for i in direction:
                        if(is_enemy_present(i)):
                            self.heur += 750
            
        if action.type=="special":
            if o["movegen"][troop.name]["health"]==0: self.heur = -float('inf')
            lis = is_enemy_present(self)
            if lis and len(lis) != 0:
                if(troop_data[troop.name] == "Rocket"):
                        self.heur += float('inf')
            if troop_data[troop.name] == "Drax":
                self.heur += 20
        return self.heur
    
    
base = None





if len(sys.argv) != 2:
    print("Usage: python3 temp_client.py <player_id>")
    exit(1)

sio = socketio.Client()

if sys.argv[1] == "1":
    PLAYER_ID = 'player1'
    PLAYER_PASSWORD = 'player1'
else:
    PLAYER_ID = 'player2'
    PLAYER_PASSWORD = 'player2'
PLAYER_ROOM = 'gameRoom'


@sio.event
def connect():
    print("I'm connected!")


@sio.event
def action(state):
    global o, base
    o = state
    if state['round_no']==0:
        base = s_to_t(o["movegen"]["Gamora"]["current_cell"]["coordinates"])
    root = Root()
    valid_cells = []
    for i in troop_name:
        temp_dict = o["movegen"][i]["current_cell"]
        temp_cell1 = Cell(s_to_t(temp_dict["coordinates"]), temp_dict["cell_type"], temp_dict["is_powerStone_present"], temp_dict["guardians_present"])
        temp_troop = Troop(i, temp_cell1)
        root.troops.append(temp_troop)
        temp_cell1.parent = temp_troop
        valid_cells.append(temp_cell1)
        for j in action_list:
            temp_action = Action(j)
            temp_troop.actions.append(temp_action)
            for k in o["movegen"][i]["neighbour_cells"]:
                for l2 in k:
                    temp_cell2 = Cell(s_to_t(l2["coordinates"]), l2["cell_type"], l2["is_powerStone_present"], l2["guardians_present"])
                    valid_cells.append(temp_cell2)
                    temp_action.cells.append(temp_cell2)
                    temp_cell2.parent = temp_action
            temp_action.parent = temp_troop
        temp_troop.parent = Root
    max_heu = -float('inf')
    for i in root.troops:
        for j in i.actions:
            for k in j.cells:
                if k.heuristic()>max_heu:
                    max_heu = k.heur
                    ans = k
    
    action1 = {
      "action_type": ans.parent.type.upper(),
      "troop": ans.parent.parent.name,
      "target": str(ans.coordinate),
      "player_id": "player"+sys.argv[1],
      "round_no": state['round_no']
    }

    loc = []
    current = s_to_t(o["movegen"]["Gamora"]["current_cell"]["coordinates"])
    for i in range(1,6):
        if(current[0] + i < n) : loc.append((current[0] + i, current[1]))
        if(current[1] + i < n):  loc.append((current[0] , current[1] + i))
        if(current[0] - i >= 0): loc.append((current[0] - i, current[1]))
        if(current[1] - i >= 0): loc.append((current[0], current[1] - i))
    min_x = min([j[0] for j in loc])
    for i in loc:
        if(i[0] == min_x):
            min_y = i[1]

    if(len(IS_predict)==1 and o["movegen"]["Gamora"]["health"]>0 ):
        coord_action_2 = min_x, min_y
    else:
        coord_action_2 = random.choice(loc)

    action2 = {
      "action_type": "SPECIAL",
      "troop": "Gamora",
      "target": str(coord_action_2),
      "player_id": "player"+sys.argv[1],
      "round_no": state['round_no']
    }

    if(o["movegen"]["Gamora"]["health"]>0 and o["movegen"]["Gamora"]["cooldown"] == 0 and random.random() < 0.1):
        final_action = action2
        print(o)
    else:
        final_action = action1
    
    path[ans.parent.parent.name].append(ans.coordinate)
    for i in range(5): 
        if troop_name[i]!=ans.parent.parent.name: stagnent[troop_name[i]] +=1
        else: stagnent[troop_name[i]] = 0
    update(valid_cells)
    print(len(IS_predict))

    print("action:", final_action)
    for i in range(n):
        for j in range(n):
            print(maze[i][j], end='')
        print()
    sio.emit('action', final_action)


@sio.event
def connected(data):
    print("Response:", data)


sio.connect('http://127.0.0.1:8000',
            {"auth": json.dumps({'player_id': PLAYER_ID, 'password': PLAYER_PASSWORD, 'room': PLAYER_ROOM})})
