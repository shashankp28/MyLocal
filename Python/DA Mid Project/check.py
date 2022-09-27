import numpy as np
import math
import random
with open('test.txt') as f:
    l = [float(i) for i in f.read().splitlines()]
mu = np.mean(l[0:1000])                   # Mean of entries from 1-1000
sigma_sq = round(np.var(l[0:1000]), 1)    # Variance of entries from 1-1000
data_mean = np.mean(l[1000:10000])        # Mean of entries from 10001-10000
p = round((data_mean-mu)/5, 1)            # Bias of the coin
mu = round(mu, 1)
print("Mean of noise=", mu, "Variance of noise=", sigma_sq, "Bias=", p)