match_data = []

with open("input4", "r", encoding="utf-8") as f:
    total = 0
    for line in f.readlines():
        count = 0
        data = line.strip().split(":")[1].strip().split("|")
        data = [x.strip() for x in data]
        win, have = set(int(x) for x in data[0].split()), [int(x)
                                                           for x in data[1].split()]
        for num in win:
            if num in have:
                count += 1
        match_data.append(count)

individual = [1]*len(match_data)
for i in range(len(match_data)):
    for j in range(1, match_data[i]+1):
        individual[i+j] += individual[i]

print("Total:", sum(individual))
