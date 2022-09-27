C=0   # No. Of Customers
L = []  # List of list conating likes of each customer
D = []  # List of list conating dislikes of each customer
s = set()
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


def score(ingredients, filename):
    output = open(filename, "r+")
    output_string  = output.readline().split()
    output_string.pop(0)
    for item in output_string:
        ingredients[item] = True
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

# ----------MAIN------------
s = set()
ingredients = dict()

inpu("e_elaborate.txt")
for i in range(C):
    for j in L[i]:
        s.add(j)
    for k in D[i]:
        s.add(k)
    
for i in s:
    ingredients[i] = False

print(score(ingredients, "output_E.txt"))
