C=0   # No. Of Customers
L = []  # List of list conating likes of each customer
D = []  # List of list conating dislikes of each customer
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
inpu("e_elaborate.txt")
s = 0;
for i in L+D:
    s+=len(i)
print(s)