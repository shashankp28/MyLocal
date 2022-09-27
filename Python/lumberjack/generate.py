import random
t = random.randint(1, 5000)
n = random.randint(1, 1000)
k = random.randint(1, min(10000, (n**2)-1))
f = open("input.txt", "w+")
f.write(str(t)+' '+str(n)+' '+str(k)+'\n')
l = []
for i in range(0, n):
    for j in range(0, n):
        l.append([i, j])
l.remove([0, 0])
i=0
while(i<k):
    r = random.randint(0, len(l)-1)
    x, y = l[r]
    l.remove(l[r])
    h = random.randint(1, 20)
    d = random.randint(1, 20)
    c = random.randint(1, 500)
    p = random.randint(1, 500)
    f.write(str(x)+' '+str(y)+' '+str(h)+' '+str(d)+' '+str(c)+' '+str(p)+'\n')
    i+=1
f.close()