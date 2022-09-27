import math
def solution(s):
    N = int(s)
    ans = 0
    root_2 = math.sqrt(2)
    for i in range(1, N+1): ans += math.floor(i*root_2)
    return ans



print(solution('5'))