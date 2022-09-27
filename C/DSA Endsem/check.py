def sort(sub_li, n):
    sub_li.sort(key=lambda x: x[n])
    return sub_li
arr = []
print("File name: ")
s = input()
f = open(s, "r")
v = 0
for i in f:
    arr.append([int(j) for j in i.split()])
    v+=1
f.close()
arr = sort(arr, 0)
f = open("m"+s, "w+")
for i in range(v):
    f.write(str(arr[i][0]) + " " + str(arr[i][1]) + "\n")
f.close()
