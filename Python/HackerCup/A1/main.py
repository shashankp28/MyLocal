def mode(l):
	c = 0
	for i in l:
		if l.count(i)>c:
			y = i
			c = l.count(i)
	return y
def fw(count, min):
	f2.write('Case #'+str(count)+': '+str(min)+'\n')
	return
f1 = open("test.txt", "r")
f2 = open('output.txt', 'w')
i=0
for x in f1:
	if i==0:
		i+=1
		continue
	s = list(x.lower())
	s = [x for x in s if x!='\n']
	if (len(set(s))==1):
		fw(i, 0)
		i+=1
		continue
	v, c= [[], []]
	for j in range(len(s)):
		if s[j]=='a' or s[j]=='e' or s[j]=='i' or s[j]=='o' or s[j]=='u':
			v.append(s[j])
		else:
			c.append(s[j])
	if (len(v)==0 or len(c)==0):
		fw(i, len(s))
		i+=1
		continue
	k = min(len(v)+2*(len(c)-c.count(mode(c))), len(c)+2*(len(v)-v.count(mode(v))))
	fw(i, k)
	i+=1
f1.close()
f2.close()