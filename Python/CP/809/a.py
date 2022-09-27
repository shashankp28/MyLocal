T = int(input())

for t in range(T):
    n = int(input())
    colors = [int(i) for i in input().split()]
    counts = {}
    for id, c in enumerate(colors):
        if counts.get(c)==None:
            temp = {"curr":1, "max": 1, "prev": id}
            counts[c] = temp
        else:
            if (id - counts[c]["prev"])%2!=0:
                counts[c]["curr"]+=1
                counts[c]["max"] = max(counts[c]["curr"], counts[c]["max"])
            else:
                counts[c]["curr"]=1
            counts[c]["prev"] = id
    ans = ['0' for i in range(n)]
    for key in counts: ans[key-1]=str(counts[key]["max"])
    print(' '.join(ans))