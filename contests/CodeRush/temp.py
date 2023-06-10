def check_cond(x, y, com):
    if com == 'A': return x > 0 and y > 0
    if com == 'B': return x > 0 and y < 0
    if com == 'C': return x < 0 and y > 0
    if com == 'D': return x < 0 and y < 0

n, m = [int(x) for x in input().split()]

commands = list(input())

coordinates = []

for _ in range(n):
  x, y = [int(x) for x in input().split()]
  coordinates.append((x, y))

cur = coordinates[0]
coordinate_set = set(coordinates[1:])

for command in commands:
    min_dist = float('inf')
    min_coordinate = None
    for cor in coordinate_set:
        diff = (cor[0] - cur[0], cor[1] - cur[1])
        diff_x, diff_y = diff
        if abs(diff_x) == abs(diff_y) and diff_x != 0:
            if check_cond(diff_x, diff_y, command):
                dist = diff_x**2 + diff_y**2
                if dist < min_dist:
                    min_dist = dist
                    min_coordinate = cor

    if min_coordinate:
        cur = min_coordinate
        coordinate_set.remove(cur)
        
print(cur[0], cur[1])