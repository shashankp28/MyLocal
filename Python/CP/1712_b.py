t = int(input())
for i in range(t):
    n = int(input())
    arr = list(range(1, n+1))
    start = n%2
    point = start
    while point<n:
        arr[point] = arr[point]+arr[point+1]
        arr[point+1] = arr[point]-arr[point+1]
        arr[point] = arr[point]-arr[point+1]
        point += 2
    print(' '.join(str(i) for i in arr))