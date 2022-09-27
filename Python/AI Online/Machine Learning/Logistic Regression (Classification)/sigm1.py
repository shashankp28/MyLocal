import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LogisticRegression
xp=[]
yp=[]
xf=[]
yf=[]
f = open("data1.txt", "r+")
for line in f:
    x1, y1 = line.split()
    if int(y1[0])==0:
        xf.append(float(x1))
        yf.append(0)
    else:
        xp.append(float(x1))
        yp.append(1)
f.close()
x = np.array(xp+xf).reshape(-1, 1)
y = np.array(yp+yf).reshape(-1, 1)
reg = LogisticRegression()
reg.fit(x, y)
x1 = np.array([0, 20, 40, 60, 70, 71, 72, 73, 74, 80, 100, 120, 140, 160, 200, 300]).reshape(-1, 1)
Y = reg.predict_proba(x1)
y1=[]
for l in Y:
    y1.append(l[1])
plt.title("Linear Regression vs Logistic Regression")
plt.xlabel("Marks obtained")
plt.ylabel("Selection")
plt.style.use('ggplot')
p1 = plt.scatter(xp, yp, color="green", label="Selected")
p2 = plt.scatter(xf, yf, color="red", label="Not Selected")
plt.legend((p1, p2), ('Selected', 'Not Selected'), loc="lower right")
print(x1)
print(y1)
demark = 85
plt.plot(x1.flatten(), y1, '--', linewidth=3, color="black")
plt.plot([0, demark], [0.5, 0.5], '--', color="purple", linewidth=1.5)
plt.plot([demark, demark, 0, demark], [0.5, 0, 0.5, 1], 'H', color="black", linewidth=2)
plt.vlines(x=demark, ls='--', color="purple", ymin=0, ymax=1)
plt.savefig("image6.jpg")
plt.show()
