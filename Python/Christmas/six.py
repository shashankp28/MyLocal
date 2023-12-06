time, distance = 0, 0

with open("input6", "r", encoding='utf-8') as f:
    lines = f.readlines()
    lines = [line.strip() for line in lines]
    lines = [line.split(':')[1].strip() for line in lines]
    data = [int(''.join([x for x in line.split(' ') if x != '']))
            for line in lines]
    time, distance = data
print(time, distance)


count = 0
for t in range(time+1):
    if t * (time - t) > distance:
        count += 1
print("Count:", count)
