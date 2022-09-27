T = int(input())
for t in range(T):
    n, m = [int(i) for i in input().split()]
    if n==1 and m==1: print(0)
    elif n==1: print(m)
    elif m==1: print(n)
    else: print(n+m+-2 + min(n, m))