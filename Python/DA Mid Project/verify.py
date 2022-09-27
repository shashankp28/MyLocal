import numpy as np
import random
p = 0.1
mu = 6
sigma_sq = 0.1
f = open("test.txt", "w+")
for i in range(1000):
    f.write(str(round(np.random.normal(mu, sigma_sq**0.5, 1)[0]))+'\n')
for i in range(1000, 10000):
    temp = random.uniform(0, 1)
    x = 5 if temp<p else 0
    f.write(str(round(x+np.random.normal(mu, sigma_sq**0.5, 1)[0]))+'\n')
f.close()