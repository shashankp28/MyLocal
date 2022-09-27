from heapq import heapify, heappush, heappop
def correctStr(s):
    lis = list(s)
    for i in range(len(lis)): 
        if lis[i]==' ': lis[i] = "' '"
    s = ''
    for i in lis: s+=i
    return s
def update(root):
    if root.right==None and root.left==None: 
        root.enc+=''
        return
    root.right.enc = root.enc + '1'
    update(root.right)
    root.left.enc = root.enc + '0'
    update(root.left)
    return
class Node:
    def __init__(self, s, f):
        self.val = s
        self.freq = f
        self.right = None
        self.left = None
        self.parent = None
        self.enc = ''
    def __lt__(self, other):
        if self.freq!=other.freq: return self.freq<other.freq
        elif self.freq==other.freq: return self.val<other.val
line_no = 0
all_leaf = []
nodes = []
order_merge = []
heapify(nodes)
roll = input("Type your roll no. :")
f = open(roll+"-hc-data.txt", "r+")
for line in f:
    if line_no==0:
        code = line.strip('\n')
        line_no+=1
    else:
        temp = line.strip('\n').split(':')
        if temp[0]=="' '":
            temp = Node(' ', int(temp[1]))
            heappush(nodes, temp)
            all_leaf.append(temp)
        else:
            temp = Node(temp[0], int(temp[1]))
            heappush(nodes, temp)
            all_leaf.append(temp)
f.close()
while len(nodes)!=1:
    n1 = heappop(nodes)
    n2 = heappop(nodes)
    temp_node = Node(n1.val+n2.val, n1.freq+n2.freq)
    n1.parent = temp_node
    n2.parent = temp_node
    temp_node.left = n1
    temp_node.right = n2
    order_merge.append(temp_node)
    heappush(nodes, temp_node)
root = heappop(nodes)
update(root)
dec = dict()
for i in all_leaf:
    dec[i.enc] = i.val
f = open(roll+"-hc-answer.txt", "w+")
for i in order_merge:
    f.write(correctStr(i.val) + ":" + str(i.freq)+'\n')
ans = ''
temp_str = ''
for i in range(len(code)):
    temp_str+=code[i]
    if temp_str not in dec: continue
    ans += dec[temp_str]
    temp_str = ''
f.write(ans+'\n')
f.close()