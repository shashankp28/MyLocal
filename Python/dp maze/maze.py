from random import uniform
n = 10#int(input("Size of grid nxn (n): "))
field = []
for i in range(n):
    field.append([])
    for j in range(n):
        p = uniform(0, 1)
        if p<0.5 : field[i].append(1)
        else: field[i].append(0) 
for i in range(n):
    print(field[i])
print()
max_count = [[0 for i in range(n+1)]]
for i in range(n):
    max_count.append([0 for i in range(n+1)])
for i in range(1, n+1):
    for j in range(1, n+1):
        max_count[i][j] = max(max_count[i-1][j], max_count[i][j-1])+field[i-1][j-1]
for i in range(n+1):
    print(max_count[i])
print(max_count[n][n])