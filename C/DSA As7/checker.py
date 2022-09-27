print("input file: ")
str = input()
f = open(str, "r")
k = 0
l = []
for x in f:
    if k==0:
        v, e = [int(i) for i in x.split()]
        k+=1
    l.append([int(i) for i in x.split()])
f.close()
f = open("ts.txt", "r")
a = []
k = 0
for x in f:
    a.append(int(x))
    k+=1
f.close()
if k!=v:
    print("All vertex: Wrong")
else:
    c = [1 for i in range(v)]
    for i in range(v):
        c[a[i]] -= 1
    if c.count(0)==v:
        print("All vertex: Correct")
    else:
        print("All vertex: Wrong")
sen = 0
for i in range(v-1):
    for j in range(i+1, v):
        if [a[j], a[i]] in l:
            sen = 1
            break
    if sen==1: break
if sen==0:
    print("Topological sort: Correct")
else:
    print("Topological sort: Wrong")
