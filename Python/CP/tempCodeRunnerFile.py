import itertools
from math import gcd
def lcm(a,b):
  return a*b/(gcd(a,b))

def lcm_sum(l1, l2):
    sum = 0
    for a, b in zip(l1, l2):
        sum += lcm(a, b)
    return sum

t = int(input())
for i in range(t):
    n = int(input())
    arr = list(range(1, n+1))
    max_sum = -float('inf')
    max_arr = []
    for lis in itertools.permutations(arr):
        l_sum = lcm_sum(arr, lis)
        if l_sum>max_sum:
            max_arr = lis[:]
            max_sum = l_sum
    print(' '.join(max_arr))