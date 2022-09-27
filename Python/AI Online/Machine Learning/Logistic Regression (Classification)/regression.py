import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression
xp=[]
yp=[]
xf=[]
yf=[]
f = open("data.txt", "r+")
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
l1 = a+b*25
l2 = a+b*150
plt.plot([25, 150], [l1, l2], '--', linewidth=2, color="black")
plt.plot([0, 80], [0.42592925720780717, 0.42592925720780717], '--', color="purple", linewidth=1.5)
plt.plot([80, 80, 0, 80], [0.42592925720780717, 0, 0.42592925720780717, 1], 'H', color="black", linewidth=2)
plt.vlines(x=80, ls='--', color="purple", ymin=0, ymax=1)
plt.savefig("image2.jpg")
plt.show()
