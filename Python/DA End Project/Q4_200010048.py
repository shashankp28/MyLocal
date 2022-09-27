import numpy as np
import math
from scipy.stats import f_oneway
from scipy.stats import spearmanr
################################################################################
q4a= [[], [], []]
q4b = [[], []]
f = open("Q4_a.txt", "w+")
for i in range(10):
    for j in range(3):
        temp = np.random.normal(1)
        q4a[j].append(temp)
        f.write(str(temp))
        f.write(" ")
    f.write("\n")
f.close()
f = open("Q4_b.txt", "w+")
for i in range(20):
    for j in range(2):
        temp = np.random.normal(1)
        q4b[j].append(temp)
        f.write(str(temp))
        f.write(" ")
    f.write("\n")
f.close()
z = f_oneway(q4a[0], q4a[1], q4a[2])
print("F-ratio for the test =", round(z.statistic, 3), "and p-value is =", round(z.pvalue, 3))
y = spearmanr(q4b[0], q4b[1])
print("Correlation =", round(y.correlation, 3), "and p-value is =", round(y.pvalue, 3))
################################################################################