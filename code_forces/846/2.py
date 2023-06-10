import math
t = int(input())

for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    # cum_sum = arr[:]
    # for i in range(n-1):
    #     cum_sum[n-i-1] += cum_sum[n-i-2]
    ans = arr[:]
    for i in range(1, n):
        ans[i] = -float('inf')
        temp_sum = arr[i]
        for j in range(i, 0, -1):
            ans[i] = max(ans[i], math.gcd(temp_sum, ans[j-1]))
            if(i!=n-1):
                ans[i] = max(ans[i], ) 
            temp_sum += arr[j-1]
    print(ans)