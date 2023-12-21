
from collections import deque


def get_neighbours(coord, data):
    pipe = data[coord[0]][coord[1]]
    m, n = len(data), len(data[0])
    all_neighs = {
        'up': (coord[0] - 1, coord[1]) if coord[0] > 0 else None,
        'down': (coord[0] + 1, coord[1]) if coord[0] < m - 1 else None,
        'left': (coord[0], coord[1] - 1) if coord[1] > 0 else None,
        'right': (coord[0], coord[1] + 1) if coord[1] < n - 1 else None,
    }
    neighbours = set()
    if pipe == 'L':
        neighbours.add(all_neighs['up'])
        neighbours.add(all_neighs['right'])
    if pipe == 'J':
        neighbours.add(all_neighs['up'])
        neighbours.add(all_neighs['left'])
    if pipe == '7':
        neighbours.add(all_neighs['down'])
        neighbours.add(all_neighs['left'])
    if pipe == 'F':
        neighbours.add(all_neighs['down'])
        neighbours.add(all_neighs['right'])
    if pipe == '|':
        neighbours.add(all_neighs['up'])
        neighbours.add(all_neighs['down'])
    if pipe == '-':
        neighbours.add(all_neighs['left'])
        neighbours.add(all_neighs['right'])
    invalid_removed = {neigh for neigh in neighbours if neigh is not None}
    ground_removed = {
        neigh for neigh in invalid_removed if data[neigh[0]][neigh[1]] != '.'}
    return ground_removed


def get_dot_neighbours(coord, data):
    m, n = len(data), len(data[0])
    all_neighs = {
        'up': (coord[0] - 1, coord[1]) if coord[0] > 0 else None,
        'down': (coord[0] + 1, coord[1]) if coord[0] < m - 1 else None,
        'left': (coord[0], coord[1] - 1) if coord[1] > 0 else None,
        'right': (coord[0], coord[1] + 1) if coord[1] < n - 1 else None,
    }
    neighbours = set()
    for neigh in all_neighs.values():
        if neigh is not None and data[neigh[0]][neigh[1]] == '.':
            neighbours.add(neigh)
    return neighbours


def common(coord1, coord2, data):
    if coord1 is None or coord2 is None:
        return set()
    n1 = get_neighbours(coord1, data)
    n2 = get_neighbours(coord2, data)
    return n1.intersection(n2)


def modify_start(data, start):
    m, n = len(data), len(data[0])
    all_neighs = {
        'up': (start[0] - 1, start[1]) if start[0] > 0 else None,
        'down': (start[0] + 1, start[1]) if start[0] < m - 1 else None,
        'left': (start[0], start[1] - 1) if start[1] > 0 else None,
        'right': (start[0], start[1] + 1) if start[1] < n - 1 else None,
    }
    if common(all_neighs['up'], all_neighs['down'], data):
        data[start[0]][start[1]] = '|'
    elif common(all_neighs['left'], all_neighs['right'], data):
        data[start[0]][start[1]] = '-'
    elif common(all_neighs['up'], all_neighs['right'], data):
        data[start[0]][start[1]] = 'L'
    elif common(all_neighs['up'], all_neighs['left'], data):
        data[start[0]][start[1]] = 'J'
    elif common(all_neighs['down'], all_neighs['left'], data):
        data[start[0]][start[1]] = '7'
    elif common(all_neighs['down'], all_neighs['right'], data):
        data[start[0]][start[1]] = 'F'


data = []

with open("./inputs/input10", "r", encoding="utf-8") as f:
    for line in f:
        neighs = []
        data.append(list(line.strip()))

start = (0, 0)
for i, row in enumerate(data):
    for j, col in enumerate(row):
        if col == 'S':
            start = (i, j)
            break

modify_start(data, start)

inside, outside = set(), set()
for i, row in enumerate(data):
    for j, col in enumerate(row):
        if col == '.':
            is_outside = False
            temp_collect = set()
            queue = deque()
            queue.append((i, j))
            while queue:
                curr = queue.popleft()
                temp_collect.add(curr)
                if curr[0] == 0 or curr[0] == len(data) - 1 or curr[1] == 0 or curr[1] == len(data[0]) - 1:
                    is_outside = True
                for neigh in get_dot_neighbours(curr, data):
                    if neigh not in temp_collect:
                        queue.append(neigh)
            if is_outside:
                outside = outside.union(temp_collect)
            else:
                inside = inside.union(temp_collect)

print("Total:", len(inside))
