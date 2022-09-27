import random
get_bin = lambda x, n: format(x, 'b').zfill(n)

map = dict()
gas_there = {1: 1, 2: 1, 4: 1, 8: 1}
map[True] = [get_bin(i, 4) for i in gas_there]
map[False] = [get_bin(i, 4) for i in range(16) if i not in gas_there]

def generate_next_row(last_two, boolean):
    ret = []
    for i in map[boolean]:
        if last_two==i[:2]:
            ret.append(i[-2:])
    return list(set(ret))

def generate_nodes(preds):
    ret = dict()
    for i in preds:
        lr = ['', '']
        for j in range(len(i)):
            lr[j%2]+=i[j]
        lr = [int(k, 2) for k in lr]
        if not ret.get(lr[1]):
            ret[lr[1]] = [lr[0]]
        else:
            ret[lr[1]].append(lr[0])
    return ret

def generate_pre_col(nebula, i):
    col = [j[i] for j in nebula]
    open = map[col[0]][:]
    while open and len(open[0])!=2*(len(col)+1):
        front = open[0]
        del open[0]
        neighbours = generate_next_row(front[-2:], col[len(front)//2-1])
        new_list = [front+neighbour for neighbour in neighbours]
        open += new_list
    return generate_nodes(open)

def solution(g):
    preds = generate_pre_col(g, 0)
    counts = {key: len(preds[key]) for key in preds}
    for i in range(1, len(g[0])):
        preds = generate_pre_col(g, i)
        new_count = dict()
        for key in preds:
            for j in preds[key]:
                val = counts.get(j)
                if not new_count.get(key):
                    if val: new_count[key]=val
                else:
                    if val: new_count[key]+=val
        counts=new_count
    return sum(list(counts.values()))


# state = [[random.uniform(0, 1)<0.1 for i in range(50)] for j in range(9)]
state1 = [[True, False, True], [False, True, False], [True, False, True]]

state2 = [[True, True, False, True, False, True, False, True, True, False], 
         [True, True, False, False, False, False, True, True, True, False], 
         [True, True, False, False, False, False, False, False, False, True], 
         [False, True, False, False, False, False, True, True, False, False]]

state3 = [[True, False, True, False, False, True, True, True], 
          [True, False, True, False, False, False, True, False], 
          [True, True, True, False, False, False, True, False], 
          [True, False, True, False, False, False, True, False], 
          [True, False, True, False, False, True, True, True]]

print(solution(state1))
print(solution(state2))
print(solution(state3))
