import numpy as np
import math as m
################################################################################
# Question 2 a
f = open("DA_P2_data_200010048.txt", "r")
Q2 = []
for i in f:
    Q2.append(float(i))
f.close()
n = len(Q2)
e = np.mean(Q2)
v = np.var(Q2)*(n/(n-1))
b = e + m.sqrt(3*(v-1))
a = e - m.sqrt(3*(v-1))
print("Q2 A: Estimate b =", round(b, 0), "Estimate a =", round(a, 0))
print()
################################################################################

################################################################################
# Question 2 b
mx = max(Q2)
mn = min(Q2)
print("**Assuming no Noise")
print("Q2 B: Estimate b =", round(mx*(n+1)/n, 0), "Estimate a =", round(mn*((n+1)/n), 0))

################################################################################
#Check Unbiased and Consistant:
b = 8
a = 2
print("Let b =", b, "a =", a)
print()
data2 = np.random.uniform(a, b, 10000)
print("For Estimate(b): (1+1/n)*max(X) = ", round((1001/1000)*max(data2), 0))
print("Unbiased")
print("Consistency: ")
for i in range(4):
    p = 10**(i+1)
    print("-- n =", p, "Error:", ((8-max(data2[0:p]))**2)/p)
print("Consistent as Error -> 0")
print()
print("For Estimate(a): (1+1/n)*min(X) = ", round((1001/1000)*min(data2), 0))
print("Unbiased")
print("Consistency: ")
for i in range(4):
    p = 10**(i+1)
    print("-- n =", p, "Error:", ((2-min(data2[0:p]))**2)/p)
print("Consistent as Error -> 0")
################################################################################
################################################################################

