from math import gcd

def coprime_ways(arr):
    n = len(arr)
    m = arr[0]
    M = arr[-1]
    count_m = 0
    count_M = 0
    for i in range(n):
        if gcd(m, arr[i]) == 1:
            count_m += 1
        if gcd(M, arr[i]) == 1:
            count_M += 1
    return (count_m * count_M) // (n-2)
 
n = int(input())
arr = [int(x) for x in input().split()]

print(coprime_ways(arr))