"""
Christmas Day 3
"""


def is_symbol(row, col, data):
    """
    Check if the symbol is valid
    """
    if row < 0 or row >= len(data):
        return False
    if col < 0 or col >= len(data[row]):
        return False
    if data[row][col] == "." or data[row][col].isdigit():
        return False
    return True


def check_valid(row, start, end, data):
    """
    Check if the number is valid
    """
    is_valid = False
    for i in range(start-1, end+1):
        is_valid = is_valid or is_symbol(row-1, i, data)
    for i in range(start-1, end+1):
        is_valid = is_valid or is_symbol(row+1, i, data)
    is_valid = is_valid or is_symbol(row, start-1, data)
    is_valid = is_valid or is_symbol(row, end, data)
    return is_valid


with open("./inputs/input3", "r", encoding="utf-8") as f:
    data = []
    for line in f.readlines():
        line = line.strip()
        data.append(list(line))

print(data)
pinch = []
for line in data:
    n = len(line)
    start, end = 0, 0
    temp_pinch = []
    while end < n:
        if line[end].isdigit():
            end += 1
        else:
            if start != end:
                temp_pinch.append((start, end))
            end += 1
            start = end
    if end == n and start != end:
        temp_pinch.append((start, end))
    pinch.append(temp_pinch)


def does_overlap(row, start, end, x, y):
    return row == x and (start <= y < end)


def get_power(adjs, pinch, data):
    """
    Get the power of the pinch
    """
    overlaps = set()
    for i, row in enumerate(pinch):
        for j, (start, end) in enumerate(row):
            for adj in adjs:
                if does_overlap(i, start, end, *adj):
                    overlaps.add((i, start, end))
    if len(overlaps) != 2:
        return 0
    total = 1
    for i, start, end in overlaps:
        total *= int(''.join(data[i][start:end]))
    return total


total = 0
for i, row in enumerate(data):
    for j, value in enumerate(row):
        if value == '*':
            adj_indices = [(i-1, j-1), (i-1, j), (i-1, j+1),
                           (i, j-1), (i, j+1),
                           (i+1, j-1), (i+1, j), (i+1, j+1)]
            total += get_power(adj_indices, pinch, data)
print("Total: ", total)
