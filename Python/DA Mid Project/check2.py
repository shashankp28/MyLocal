import numpy as np
import math
import random
with open('test.txt') as f:
    d = f.read().splitlines()
z = [float(d[i]) for i in range(50000)]
z_x = []
for i in range(50000):
    z_x.append(z[i] - random.uniform(-3, 3))
pi = math.pi
v = np.var(z_x)
e = np.mean(z)
r = (e**2)/v
p = [1, (4-pi)/pi, (pi-2)/2]
temp = float('inf')
for i in range(3):
    for j in range(2, 5):
        if abs(j-p[i]*r)<temp:
            d = i
            k = j
            temp = abs(j-p[i]*r)
dist = ['Exponential', 'Rayleigh', 'Half-normal']
if d==0:
    const = round(e/(10*k))
    print('The distribution is', dist[d], 'with, Mean =', const, ', k =', k)
if d==1:
    const = round(((2/pi)**0.5)*e/(10*k))
    print('The distribution is', dist[d], 'with, Sigma =', const, ', k =', k)
if d==2:
    const = round(((pi/2)**0.5)*e/(10*k))
    print('The distribution is', dist[d], 'with, Sigma =', const, ', k =', k)