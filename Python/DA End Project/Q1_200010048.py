import numpy as np
import math as m
import matplotlib.pyplot as plt

################################################################################
def generate():
    data = np.random.uniform(0, 1, 500)
    X = sum(data)
    E = 500*(1/2)
    S = m.sqrt(500)*(1/m.sqrt(12))
    return (X-E)/S
################################################################################

################################################################################
# Question 1 a
f = open("Q1_a.txt", "w+")
f.close()
Q1 = []
f = open("Q1_a.txt", "a+")
for i in range(10000):
    x = generate()
    Q1.append(x)
    f.write(str(round(x, 4))+"\n")
print("Q1_a.txt GENERATED! with 10000 data points.")
print()
f.close()
norm = np.random.normal(size=10000)
# Question 1 a Plot
fig, ax = plt.subplots(1, 2, figsize=(16, 9))
fig.suptitle('Comparision', fontsize=16)
ax[0].hist(Q1, color="blue", bins=200, rwidth=0.5)
ax[1].hist(norm, color="red", bins=200, rwidth=0.5)
ax[0].title.set_text('Uniform Random Central Limit Theorem')
ax[1].title.set_text('In-built Random normal')
ax[0].set_xlabel('Data')
ax[0].set_ylabel('Frequency')
ax[1].set_ylabel('Frequency')
ax[1].set_xlabel('Data')
plt.savefig('Q1_a.jpg')
print("Unform Random CLT: mean =", round(np.mean(Q1), 2), "variance =", round(np.var(Q1), 2))
print("In-built Random Normal: mean =", round(np.mean(norm), 2), "variance =", round(np.var(norm), 2))
print()
print()
################################################################################

################################################################################
# Question 1 b
f = open("Q1_b.txt", "w+")
f.close()
Q1 = []
f = open("Q1_b.txt", "a+")
for i in range(10000):
    x = 0
    for j in range(4): x += generate()**2
    Q1.append(x)
    f.write(str(round(x, 4))+"\n")
print("Q1_b.txt GENERATED! with 10000 data points.")
print()
f.close()
chi = np.random.chisquare(4, 10000)
# Question 1 b Plot
fig, ax = plt.subplots(1, 2, figsize=(16, 9))
fig.suptitle('Comparision', fontsize=16)
ax[0].hist(Q1, color="blue", bins=200, rwidth=0.5)
ax[1].hist(chi, color="red", bins=200, rwidth=0.5)
ax[0].title.set_text('Chi-Square using part A')
ax[1].title.set_text('In-built Chi-Square')
ax[0].set_xlabel('Data')
ax[0].set_ylabel('Frequency')
ax[1].set_ylabel('Frequency')
ax[1].set_xlabel('Data')
plt.savefig('Q1_b.jpg')
print("Chi-Square using part A: mean =", round(np.mean(Q1), 2), "variance =", round(np.var(Q1), 2))
print("In-built Chi-Square: mean =", round(np.mean(chi), 2), "variance =", round(np.var(chi), 2))
plt.show()
################################################################################