T = int(input())
for t in range(T):
    n, k = [int(i) for i in input().split()]
    arr = [int(i) for i in input().split()]
    count = 0
    for i in range(k):
        if arr[i]>k: count+=1
    print(count)