time, distance = 0, 0

with open("./inputs/input6", "r", encoding='utf-8') as f:
    lines = f.readlines()
    lines = [line.strip() for line in lines]
    lines = [line.split(':')[1].strip() for line in lines]
    data = [int(''.join([x for x in line.split(' ') if x != '']))
            for line in lines]
    time, distance = data


def get_index(t, d):
    s, e = 0, t
    result = 0
    while s < e:
        mid = (s + e) // 2
        if mid * (2*t - mid) >= d:
            result = mid
            e = mid - 1
        else:
            s = mid + 1
    return result


i = get_index(time//2, distance)
print(time - 2*i + 1)
