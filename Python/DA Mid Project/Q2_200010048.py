import pandas as pd
import numpy as np
import math
import random
z = pd.read_excel('Proj_Comp2_data_200010048.csv', header=None)
z = [z[0][i] for i in range(50000)]    #Random variable Z
z_x = []
for i in range(50000):
    z_x.append(z[i] - random.uniform(-3, 3))      #Random variable (Z-X)
pi = math.pi
v = np.var(z_x)      #Variance of (Z-X)
e = np.mean(z)       #Expectation of Z
r = (e**2)/v
#Coeffecients while calculating k for different distributions
p = [1, (4-pi)/pi, (pi-2)/2]  
temp = float('inf')
for i in range(3):        #Code to get k value closest to {2, 3, 4}
    for j in range(2, 5):
        if abs(j-p[i]*r)<temp:
            d = i
            k = j
            temp = abs(j-p[i]*r)
dist = ['Exponential', 'Rayleigh', 'Half-normal']
if d==0:
    const = round(e/(10*k)) #Parameter value nearest integer
    print('The distribution is', dist[d], 'with, Mean =', const, ', k =', k)
if d==1:
    const = round(((2/pi)**0.5)*e/(10*k))   #Parameter value nearest integer
    print('The distribution is', dist[d], 'with, Sigma =', const, ', k =', k)
if d==2:
    const = round(((pi/2)**0.5)*e/(10*k))   #Parameter value nearest integer
    print('The distribution is', dist[d], 'with, Sigma =', const, ', k =', k)