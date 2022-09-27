import copy
def fw(a, b, c):
	f2.write('Case #'+str(a+1)+': '+str(b)+' '+str(c)+'\n')
	return
f1 = open("test.txt", "r")
f2 = open('output.txt', 'w')
i=0
G = int(f1.readline())
for g in range(G):
	n = int(f1.readline())
	r = []
	won = []
	min = 100
	for i in range(n):
		z = [x for x in list(f1.readline()) if x != '\n']
		r.append(z)
	for i in range(n):
		t =copy.deepcopy(r)
		if t[i].count('O')!=0:
			continue
		if t[i].count('.')<min:
			min = t[i].count('.')
			won = []
		if t[i].count('.')>min:
			continue
		t[i] = ['X' for j in range(n)]
		won.append(t)
	for i in range(n):
		t = []
		m=0
		for j in range(n):
			if r[j][i]=='O':
				m=1
				break
			t.append(r[j][i])
		if m==1: continue
		if t.count('.')>min:
			continue
		if t.count('.') < min:
			min = t.count('.')
			won = []
		t =copy.deepcopy(r)
		for j in range(n): t[j][i] = 'X'
		won.append(t)
	u = []
	for x in won:
		if u.count(x)==0: u.append(x)
	fw(g, str(min), len(u)) if len(u)!=0 else f2.write('Case #'+str(g+1)+': '+'Impossible'+'\n')
f1.close()
f2.close()