T = int(input())

for t in range(T):
    n, m = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    ans = ['B' for i in range(m)]
    for id in a:
        if id<=m//2:
            if ans[id-1]=='B': ans[id-1]='A'
            else: ans[m-id] = 'A'
        else:
            if ans[m-id]=='B': ans[m-id]='A'
            else: ans[id-1] = 'A'
    print(''.join(ans))