import time
class Node():
    def __init__(self, coordinate, par, br):
        self.x = coordinate[0]
        self.y = coordinate[1]
        self.parent = par
        self.broke = br
    
    def verify(self, dir, X, Y):
        if dir[0]<0 or dir[0]>=X: return False
        if dir[1]<0 or dir[1]>=Y: return False
        return True
    
    def check(self, dir, oc, curr_br):
        for node in oc:
            if dir==(node.x, node.y) and node.broke==curr_br: return False
        return True
    
    def goal_test(self, maze):
        X, Y = len(maze), len(maze[0])
        return self.x==X-1 and self.y==Y-1

    def neigh_gen(self, maze, open_closed):
        prev = self.parent
        neighbours = []
        X, Y = len(maze), len(maze[0])
        up_down_left_right = [(self.x-1, self.y), (self.x+1, self.y), (self.x, self.y-1), (self.x, self.y+1)]
        for dir in up_down_left_right:
            curr_br = self.broke
            if not self.verify(dir, X, Y):
                continue
            if self.broke:
                if maze[dir[0]][dir[1]]==1: continue
                else: curr_br = True
            else:
                curr_br = bool(maze[dir[0]][dir[1]])
            if not self.check(dir, open_closed, curr_br):
                continue
            else:
                neighbours.append(Node(dir, self, curr_br))
        return neighbours

def solution(maze):
    open = [Node((0, 0), -1, False)]
    closed = []
    curr_node = -1
    while len(open)!=0:
        curr_node = open[0]
        del open[0]
        closed.append(curr_node)
        if curr_node.goal_test(maze): break
        open += curr_node.neigh_gen(maze, open+closed)
    path_length = 0
    path = []
    while curr_node!=-1:
        path_length += 1
        path.append((curr_node.x, curr_node.y))
        curr_node = curr_node.parent
    return path_length

s = time.time()
maze1 = [[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
         [1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
         [1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
         [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
         [0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1],
         [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

maze2 = [[0,0,1,1],
         [1,0,0,0],
         [0,0,1,1],
         [0,1,1,1],
         [0,1,1,1],
         [0,1,0,0]]

print(solution(maze1))
for i in maze1:
    for j in i:
        print(j, end='')
    print()

e = time.time()
print(e-s, "sec")