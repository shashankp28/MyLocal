
import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(s):
    l = s.split(" ")
    l = [i.capitalize() for i in l]
    return ' '.join(l)
    
if __name__ == '__main__':

    s = input()

    result = solve(s)

    print(result)
