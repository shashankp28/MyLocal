sum = 0
for i in range(31):
    k = list(input())
    k = [i for i in k if i!=',']
    sum += float(''.join(k))
print(round(sum))