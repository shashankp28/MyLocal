from time import time

s = time()
N = 200

sum = 0
for i in range(N):
    for j in range(N):
        for k in range(N):
            sum += i+j+k

print(sum, "Time:", time()-s)