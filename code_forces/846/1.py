t = int(input())

for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    odd, even = [], []
    for x in range(n):
        if arr[x]%2: odd.append(x+1)
        else: even.append(x+1)
    
    if len(odd)==0 or (len(even)==1 and len(odd)==2):
        print("NO")
    elif len(odd)>=3:
        print("YES")
        print(f'{odd[0]} {odd[1]} {odd[2]}')
    elif len(odd)<=2:
        print("YES")
        print(f'{odd[0]} {even[0]} {even[1]}')