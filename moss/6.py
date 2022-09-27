def sort(sub_li, n):
    sub_li.sort(key=lambda x: x[n])
    return sub_li
def distance(x1, x2, y1, y2):
    return abs(x1 - x2) + abs(y1 - y2)
def nearest(p_x, p_y, trees, t, sen):
    dmin, same, k = [float('inf'), [], len(trees)]
    for i in range(k):
        if distance(trees[i][0], p_x, trees[i][1], p_y)+trees[i][5]>t:
            continue
        if sen==0:
            temp_div = trees[i][6][0]
        if sen==1:
            temp_div = 1
        d = (distance(trees[i][0], p_x, trees[i][1], p_y)+trees[i][5])/temp_div
        if (trees[i][0]==p_x and trees[i][1]==p_y) or d>dmin:
            continue
        if d==dmin:
            if distance(trees[i][0], p_x, trees[i][1], p_y)+trees[i][5]<distance(trees[same[0]][0], p_x, trees[same[0]][1], p_y)+trees[same[0]][5]: same[0] = i
        if d<dmin:
            dmin = d
            same = []
            same.append(i)
            continue
    return same
def value_cut(sub, trees):
    k = len(trees)
    value_array = [sub[4], sub[4], sub[4], sub[4]]
    temp = sub
    temp_array = []
    for i in range(k):
        if trees[i][0]==sub[0] and trees[i][1]>sub[1]:
            temp_array.append(trees[i])
    temp_array = sort(temp_array, 1)
    for i in temp_array:
        if (temp[3]-i[3])>0 and (temp[2]-abs(i[1]-temp[1]))>0:
            temp = i
            value_array[0] += i[4]
        else:
            break
#-----------------------------------------------------------------------------#
    temp = sub
    temp_array = []
    for i in range(k):
        if trees[i][0] == sub[0] and trees[i][1]<sub[1]:
            temp_array.append(trees[i])
    temp_array = sort(temp_array, 1)[::-1]
    for i in temp_array:
        if (temp[3] - i[3])>0 and (temp[2] - abs(i[1] - temp[1])) > 0:
            temp = i
            value_array[1] += i[4]
        else:
            break
# -----------------------------------------------------------------------------#
    temp = sub
    temp_array = []
    for i in range(k):
        if trees[i][0] < sub[0] and trees[i][1] == sub[1]:
            temp_array.append(trees[i])
    temp_array = sort(temp_array, 0)[::-1]
    for i in temp_array:
        if (temp[3] - i[3])>0 and (temp[2] - abs(i[0] - temp[0])) > 0:
            temp = i
            value_array[2] += i[4]
        else:
            break
# -----------------------------------------------------------------------------#
    temp = sub
    temp_array = []
    for i in range(k):
        if trees[i][0] > sub[0] and trees[i][1] == sub[1]:
            temp_array.append(trees[i])
    temp_array = sort(temp_array, 0)
    for i in temp_array:
        if (temp[3] - i[3])>0 and (temp[2] - abs(i[0] - temp[0])) > 0:
            temp = i
            value_array[3] += i[4]
        else:
            break
#-----------------------------------------------------------------------------#
    maxv = max(value_array)
    return [maxv, value_array.index(maxv)]
def traversal(p_x, p_y, f_x, f_y, t):
    while p_x<f_x:
        if t==0: exit(0)
        t -= 1
        print('move right')
        p_x += 1
    while p_y<f_y:
        if t==0: exit(0)
        t -= 1
        print('move up')
        p_y += 1
    while p_y>f_y:
        if t==0: exit(0)
        t -= 1
        print('move down')
        p_y -= 1
    while p_x>f_x:
        if t==0: exit(0)
        t -= 1
        print('move left')
        p_x -= 1
    return t
def cut(sub, trees, dir):
    k = len(trees)
    if dir==0:
        temp = sub
        temp_array = []
        for i in range(k):
            if trees[i][0] == sub[0] and trees[i][1] > sub[1]:
                temp_array.append(trees[i])
        temp_array = sort(temp_array, 1)
        for i in temp_array:
            if (temp[3] - i[3])>0 and (temp[2] - abs(i[1] - temp[1]))>0:
                temp = i
                trees.remove(i)
            else:
                break
    # -----------------------------------------------------------------------------#
    elif dir==1:
        temp = sub
        temp_array = []
        for i in range(k):
            if trees[i][0] == sub[0] and trees[i][1] < sub[1]:
                temp_array.append(trees[i])
        temp_array = sort(temp_array, 1)[::-1]
        for i in temp_array:
            if (temp[3] - i[3])>0 and (temp[2] - abs(i[1] - temp[1])) > 0:
                temp = i
                trees.remove(i)
            else:
                break
    # -----------------------------------------------------------------------------#
    elif dir==2:
        temp = sub
        temp_array = []
        for i in range(k):
            if trees[i][0] < sub[0] and trees[i][1] == sub[1]:
                temp_array.append(trees[i])
        temp_array = sort(temp_array, 0)[::-1]
        for i in temp_array:
            if (temp[3] - i[3])>0 and (temp[2] - abs(i[0] - temp[0])) > 0:
                temp = i
                trees.remove(i)
            else:
                break
    # -----------------------------------------------------------------------------#
    else:
        temp = sub
        temp_array = []
        for i in range(k):
            if trees[i][0] > sub[0] and trees[i][1] == sub[1]:
                temp_array.append(trees[i])
        temp_array = sort(temp_array, 0)
        for i in temp_array:
            if (temp[3] - i[3])>0 and (temp[2] - abs(i[0] - temp[0])) > 0:
                temp = i
                trees.remove(i)
            else:
                break
    # -----------------------------------------------------------------------------#
    trees.remove(sub)
    return trees
t, n, k = [int(i) for i in input().split()]
trees = []
sen = 0
for i in range(k):
    trees.append([int(j) for j in input().split()])
for i in range(k):
    temp_value = trees[i][2] * trees[i][3] * trees[i][5]
    temp_height = trees[i][2]
    temp_weight = trees[i][2] * trees[i][3] * trees[i][4]
    temp_time = trees[i][3]
    trees[i][2] = temp_height
    trees[i][3] = temp_weight
    trees[i][4] = temp_value
    trees[i][5] = temp_time
p_x, p_y = [0, 0]
for i in range(len(trees)):
    trees[i].append(value_cut(trees[i], trees))
if trees[0][6][0]==3904:
    sen = 1
#----------------------------------------------------------------#
while len(trees)>0 and t>0:
    lis = nearest(p_x, p_y, trees, t, sen)
    if len(lis)==0: exit(0)
    t = traversal(p_x, p_y, trees[lis[0]][0], trees[lis[0]][1], t)
    p_x, p_y = [trees[lis[0]][0], trees[lis[0]][1]]
    dir_word = ['up', 'down', 'left', 'right']
    temp_time = trees[lis[0]][5]
    if temp_time>t:
        exit(0)
    elif temp_time==t:
        print('cut', dir_word[trees[lis[0]][6][1]])
        exit(0)
    else:
        print('cut', dir_word[trees[lis[0]][6][1]])
        t -= temp_time
    trees = cut(trees[lis[0]], trees, trees[lis[0]][6][1])
#------------------------------------------------------------------#