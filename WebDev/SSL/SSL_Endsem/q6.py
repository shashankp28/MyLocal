import matplotlib.pyplot as plt
data = []
f = open("pincode_dataset.txt", "r")
c = 0
for i in f:
    if c==0:
        c+=1
        continue
    temp = i.split(", ")
    data.append([int(temp[0]), temp[1], temp[2]])
f.close()
dist = []
cd = []
for i in range(len(data)):
    if data[i][1] in dist:
        cd[dist.index(data[i][1])]+=1
    else:
        dist.append(data[i][1])
        cd.append(1)
mx = max(cd)
md = dist[cd.index(mx)]
for i in range(len(data)):
    if(data[i][1]==md):
        print("District with maximum pincodes is", md, "in the state", data[i][2], "count:", max(cd))
        break
state = []
count = []
sum = len(data)
for i in range(len(data)):
    if data[i][2] in state:
        count[state.index(data[i][2])]+=1
    else:
        state.append(data[i][2])
        count.append(1)
for i in range(len(state)):
    state[i] = state[i]+" - "+str(round(100*count[i]/sum,2))+"%"
fig1, ax1 = plt.subplots(figsize=(16, 9))
ax1.title.set_text('Pincode Distribution of States')
patches, texts = plt.pie(count, startangle=90)
plt.legend(patches, state, loc="center left", fontsize=8, bbox_to_anchor=(-0.7, 0.5), ncol=2)
plt.savefig('pincode.jpg')
plt.show()