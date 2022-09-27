import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression
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
plt.title("Linear Regression vs Logistic Regression")
plt.xlabel("Marks obtained")
plt.ylabel("Selection")
plt.style.use('ggplot')
p1 = plt.scatter(xp, yp, color="green", label="Selected")
p2 = plt.scatter(xf, yf, color="red", label="Not Selected")
plt.legend((p1, p2), ('Selected', 'Not Selected'), loc="lower right")
x = np.array(xp+xf).reshape(-1, 1)
y = np.array(yp+yf).reshape(-1, 1)
reg = LinearRegression()
reg.fit(x, y)
a = reg.intercept_[0]
b = reg.coef_[0][0]
print(a, b)
l1 = a+b*0
l2 = a+b*250
plt.plot([0, 250], [l1, l2], '--', linewidth=2, color="black")
plt.plot([0, 92.88], [0.42592925720780717, 0.42592925720780717], '--', color="purple", linewidth=1.5)
plt.plot([92.88, 92.88, 0, 92.88], [0.42592925720780717, 0, 0.42592925720780717, 1], 'H', color="black", linewidth=2)
plt.vlines(x=92.88, ls='--', color="purple", ymin=0, ymax=1)
plt.savefig("image4.jpg")
plt.show()
