import numpy as np
from scipy.stats import halfnorm
k = 2
l = 2.8
f = open("test.txt", "w+")
for i in range(50000):
    temp = np.random.uniform(-3, 3)
    for j in range(k):
        x = np.random.uniform(0, 40)
        temp += 10*halfnorm.rvs(scale = l,  size = 1)[0]
    f.write(str(round(temp, 7))+'\n')
f.close()