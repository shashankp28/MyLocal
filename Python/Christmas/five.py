from tqdm import tqdm

seed = []
all_maps = []

with open('./inputs/input5', 'r', encoding='utf-8') as f:
    lines = [x.strip() for x in f.readlines() if x != '\n']

seeds = [x.strip().split() for x in lines[0].split(':')][1]
seeds = list(map(int, seeds))
maps_count = sum(not line[0].isdigit() for line in lines[1:])


index = 1
for i in range(maps_count):
    one_map = []
    index += 1
    while index < len(lines) and lines[index][0].isdigit():
        values = lines[index].split()
        one_map.append(tuple(int(x) for x in values))
        index += 1
    all_maps.append(one_map)


def find_next_map(value, mapping):
    for m in mapping:
        dest, source, length = m
        if source <= value < source+length:
            return dest + value - source
    return value


seed_ranges = [(seeds[i], seeds[i]+seeds[i+1])
               for i in range(0, len(seeds), 2)]

result = []
for seed_start, seed_end in seed_ranges:
    minimum_value = float('inf')
    for seed in tqdm(range(seed_start, seed_end)):
        value = seed
        for one_map in all_maps:
            value = find_next_map(value, one_map)
        minimum_value = min(minimum_value, value)
    result.append(minimum_value)

print("Minimum values for each seed range:", result)
print("All Minimum:", min(result))
