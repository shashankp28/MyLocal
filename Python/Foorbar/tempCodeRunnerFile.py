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
    ret = []
    for i in preds:
        lr = ['', '']
        for j in range(len(i)):
            lr[j%2]+=i[j]
        lr = [int(k, 2) for k in lr]
        ret.append(lr)
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

def join(initial, new_list):
    temp = dict()
    ret = []
    for i in initial:
        if temp.get(i[-1]):  
            temp[i[-1]].append(i[:-1])
        else:
            temp[i[-1]] = [i[:-1]]
    for i in new_list:
        val = temp.get(i[0])
        if val: ret += [j+[i[-1]] for j in val]
    return ret

def solution(g):
    initial = generate_pre_col(g, 0)
    for i in range(1, len(g[0])):
        new_list = generate_pre_col(g, i)
        initial = join(initial, new_list)
    return len(initial)