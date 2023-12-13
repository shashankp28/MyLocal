from math import gcd

pattern = ""
data = {}

with open("./inputs/input8", "r", encoding='utf-8') as f:
    for line_no, line in enumerate(f.readlines()):
        match line_no:
            case 0:
                pattern = line.strip()
            case 1:
                continue
            case _:
                line = line.strip()
                key, value = [x.strip() for x in line.split("=")]
                value = value.replace('(', '').replace(')', '')
                L, R = [x.strip() for x in value.split(",")]
                data[key] = {
                    'L': L,
                    'R': R
                }


def lcm(a, b):
    return abs(a*b) // gcd(a, b)


def get_count(node, data, pattern):
    count = 0
    while not node.endswith('Z'):
        node = data[node][pattern[count % len(pattern)]]
        count += 1
    return count


start_nodes = [key for key in data if data if key.endswith('A')]
counts = [get_count(node, data, pattern) for node in start_nodes]

print("Total:", counts)
for i in range(1, len(counts)):
    counts[i] = lcm(counts[i-1], counts[i])
print("LCM:", counts[-1])
