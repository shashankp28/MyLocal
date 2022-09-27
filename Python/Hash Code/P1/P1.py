import H1
C=0
L = []
D = []
ingredients = {}
def inpu(filename):
    global C
    f = open(filename, "r+")
    C = int(f.readline())
    for i in range(C):
        string  = f.readline().split()
        string.pop(0)
        L.append(string)
        string = f.readline().split()
        string.pop(0)
        D.append(string)
    f.close()
def score(ingredients):
    heur = 0
    for i in range(C):
        val = True
        for j in L[i]:
            if ingredients[j] == False:
                val = False
        for j in D[i]:
            if ingredients[j] == True:
                val = False
        if val: heur+=1
    return heur
def heuristic(ingredients):
    heur = 0
    for i in range(C):
        for j in L[i]:
            if ingredients[j] != False:
                heur+=1
        for j in D[i]:
            if ingredients[j] != True:
                heur+=1
    return heur
def hill_climb(ingredients):
    max_node = ingredients
    maximum = heuristic(max_node)
    while True:
        con = True
        for key in ingredients:
            temp = ingredients.copy()
            temp[key] = not temp[key]
            h = score(temp)
            print("score:", h)
            if h>maximum:
                con = False
                max_node = temp.copy()
                maximum = h
                print("New_score:", h)
                break
        if con: break
    return max_node
s = "e_elaborate.txt"
inpu(s)
l = H1.greedy(s)
for i in L+D:
    for j in i:
        ingredients[j] = (j in l)
print(score(ingredients))
ingredients = hill_climb(ingredients)
ans = []
for key in ingredients:
    if ingredients[key]:
        ans.append(key)
f = open(s.split('.')[0]+"_out.txt", "w+")
f.write(str(len(ans)) + " ")
for i in ans:
    f.write(i+" ")
f.close()
print(score(ingredients))