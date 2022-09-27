nodes = dict()
line_no = 0
vertex_no = 0
edges = []
def val_to_key(val):
    for k in nodes:
        if nodes[k]==val: return k
def path_flow(Gf, path):
    max_flow = float('inf')
    for i in range(len(path)-1):
        max_flow = min(max_flow, Gf[path[i]][path[i+1]])
    return max_flow
def Residual(flow, capacity):
    v = len(flow)
    Gf = [[0 for i in range(v)] for j in range(v)]
    for i in range(v):
        for j in range(v):
            Gf[i][j] = capacity[i][j]-flow[i][j] if (i, j) in edges else flow[j][j]
    return Gf
def path(Gf):
    parent = dict()
    op = [nodes['s']]
    closed = []
    v = len(Gf)
    got_t = False
    temp = None
    while len(op)!=0:
        node = op.pop(0)
        closed.append(node)
        for j in range(v):
            if Gf[node][j]!=0 and (j not in closed) and (j not in op):
                op.append(j)
                parent[j] = node
                if j == nodes['t']:
                    got_t = True
                    break
        if got_t: break
    if got_t:
        final_path = []
        temp = nodes['t']
        while temp in parent:
            final_path = [temp] + final_path
            temp = parent[temp]
        return [nodes['s']] + final_path
    return None
inp = input("Type your roll no. :")
f = open(inp+"-mf-data.txt", "r+")
for line in f:
    if line_no==0:
        v, e = [int(i) for i in line.strip("\n").split()]
        capacity = [[0 for i in range(v)] for j in range(v)]
        flow = [[0 for i in range(v)] for j in range(v)]
        line_no+=1
    else:
        if line=='\n': continue
        a, b, c = line.strip("\n").split()
        if a not in nodes:
            nodes[a] = vertex_no
            vertex_no+=1
        if b not in nodes:
            nodes[b] = vertex_no
            vertex_no+=1
        edges.append((nodes[a], nodes[b]))
        capacity[nodes[a]][nodes[b]] = int(c)
f.close()
Gf = Residual(flow, capacity)
g = open(inp+"-mf-answer.txt", "w+")
while path(Gf):
    augmenting_path = path(Gf)
    f = path_flow(Gf, augmenting_path)
    augmenting_flow = [[0 for i in range(v)] for j in range(v)]
    for i in augmenting_path:
        g.write(val_to_key(i) + " ")
    g.write(str(f)+"\n")
    for i in range(len(augmenting_path)-1): 
        augmenting_flow[augmenting_path[i]][augmenting_path[i+1]] = f
    for i in range(v):
        for j in range(v):
            if (i, j) in edges: flow[i][j] += augmenting_flow[i][j] - augmenting_flow[j][i]
    Gf = Residual(flow, capacity)
g.close()