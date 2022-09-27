import numpy as np
import math
from scipy.stats import t
from scipy.stats import norm
from scipy.stats import chi2
from scipy.stats import f_oneway
################################################################################
# Question 3 a
f = open("DA_P3_data_Pop_200010048.txt", "r")
Q3_P1 = []
Q3_P2 = []
Q3_S = []
for i in f:
    j = [float(k) for k in i.split(", ")]
    Q3_P1.append(j[0])
    Q3_P2.append(j[1])
f.close()
f = open("DA_P3_data_Samp_200010048.txt", "r")
for i in f:
    Q3_S.append(float(i))
f.close()
m1 = round(np.mean(Q3_P1), 3)
v1 = round(np.var(Q3_P1), 3)
m2 = round(np.mean(Q3_P2), 3)
v2 = round(np.var(Q3_P2), 3)
ms = round(np.mean(Q3_S), 3)
vs = round(np.var(Q3_S)*(50/49), 3)
print("Population 1: mean =", m1, "variance =", v1)
print("Population 2: mean =", m2, "variance =", v2) 
print("Sample: mean =", ms, "variance =", vs)
print()
print("Question 3 a:")
int_m = norm.ppf(1-0.01/2)*math.sqrt(vs/50)
low_v = 49*vs/chi2.ppf(1-0.01/2, 49)
high_v = 49*vs/chi2.ppf(0.01/2, 49)
print("Confidence interval for mean: [", round(ms-int_m, 3), ",", round(ms+int_m, 3), "]")
print("Confidence interval for variance: [", round(low_v, 3), ",", round(high_v, 3), "]")
print("Sample belongs to Population 2")
#Question 3 b
print()
print("Question 3 b:")
print("mean_p =", m2, "mean_s =", ms) # in my case it is m2
sta = (ms-m2)/math.sqrt(vs/50)
t_a = t.ppf(1-0.05/2, 49)
print("statistic =", round(sta, 3), "t-value =", round(t_a, 3))
if(abs(sta)<abs(t_a)):
    print("Mean are equal")
else:
    print("Mean are not equal")
#Question 3 c:
print()
print("QUestion 3 c")
test =[]
print("F-ratio test holds for 'm': ")
st = 0
en = 0
for i in range(4, 47):
    str = f_oneway(Q3_S[0:i], Q3_S[i:50]).pvalue
    p = float(str)
    if p<0.6:
        test.append(i)
        st = 1
    else:
        en = 1
    if st==1 and en==1:
        break
print(min(test), "-", max(test))
################################################################################