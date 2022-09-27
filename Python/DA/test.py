import numpy as np
import statistics as sa
import scipy.stats as sb
while True:
    print("1. Mean, Variance and Standard Deviation")
    print("2. Phi table")
    print("3. t CDF")
    print("4. chi CDF")
    print("5. z_a/2")
    print("6. t_a/2")
    print("7. chi2_a/2, chi2_1-a/2")
    print("8. Phi inverse")
    print("9. T inverse")
    print("10. Chi2 Inverse")
    n = int(input())
    if n==1:
        print("Values with spaces")
        l = [float(i) for i in input().split()]
        print("n = ", len(l))
        print("Sum: ", round(sum(l), 6))
        print("Mean: ", round(sa.fmean(l), 6))
        print("Variance 1/(n-1): ", round(sa.variance(l), 6))
        print("Standard Deviation: ", round(sa.stdev(l), 6))
        print()
    elif n==2:
        print("z")
        l = float(input())
        print("P(Z<z): ", round(sb.norm.cdf(l), 6))
        print()
    elif n==3:
        print("Value <space> DoF: ")
        l = input().split()
        print("P(T<t): ", round(sb.t.cdf(float(l[0]), int(l[1])), 6))
        print()
    elif n==4:
        print("Value <space> DoF: ")
        l = input().split()
        print("P(CHI2<chi2): ", round(sb.chi2.cdf(float(l[0]), int(l[1])), 6))
        print()
    elif n==5:
        print("Alpha(a)")
        l = input()
        if float(l)>=1 or float(l)<=0:
            print("Invalid")
            continue
        print("z_a/2: ", round(sb.norm.ppf(1-float(l)/2), 6))
        print()
    elif n==6:
        print("Alpha(a) <space> DoF: ")
        l = input().split()
        if float(l[0]) >= 1 or float(l[0]) <= 0:
            print("Invalid")
        print("t_a/2_DoF: ", round(sb.t.ppf(1-float(l[0])/2, int(l[1])), 6))
        print()
    elif n==7:
        print("Alpha(a) <space> DoF: ")
        l = input().split()
        if float(l[0]) >= 1 or float(l[0]) <= 0:
            print("Invalid")
        print("Chi2_a/2_DoF: ", round(sb.chi2.ppf(1-float(l[0])/2, int(l[1])), 6))
        print("Chi2_(1-a/2)_DoF: ", round(sb.chi2.ppf(float(l[0])/2, int(l[1])), 6))
        print()
    elif n==8:
        print("Probability: ")
        l = input()
        if float(l) >= 1 or float(l) <= 0:
            print("Invalid")
        print("Phi inverse ", round(sb.norm.ppf(float(l)), 6))
        print()
    elif n==9:
        print("Probability <space> DoF: ")
        l = input().split()
        if float(l[0]) >= 1 or float(l[0]) <= 0:
            print("Invalid")
        print("T Inverse: ", round(sb.t.ppf(float(l[0]), int(l[1])), 6))
        print()
    elif n==10:
        print("Probability <space> DoF: ")
        l = input().split()
        if float(l[0]) >= 1 or float(l[0]) <= 0:
            print("Invalid")
        print("Chi2 Inverse: ", round(sb.chi2.ppf(float(l[0]), int(l[1])), 6))
        print()
    else:
        continue
