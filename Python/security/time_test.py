import requests
from tqdm import tqdm
from time import time
import string
import json

import random

def pass_gen(n):
    p_list = []
    for i in range(n):
        length = random.randint(8, 15)
        letters = string.ascii_lowercase+string.digits
        if random.randint(0, 1)==0: letters += string.punctuation
        result_str = ''.join(random.choice(letters) for i in range(length))
        p_list.append(result_str)
    return p_list

s_list = [8, 16, 32, 64, 256, 512, 1024]
rounds = [2, 4, 8, 16, 32]
sizes = [2, 4, 8, 16, 32]
para = [2, 4, 8, 16]

N = 1

pb = tqdm(total=7*5*5*4*N)
result = {}

for s in s_list:
    for r in rounds:
        for b in sizes:
            for p in para:
                hash_avg = 0
                verify_avg = 0
                for password in pass_gen(N):
                    pb.update(n=1)
                    param = {"s":s, "r": r, "b": b, "p": p, "password": password}
                    st = time()
                    res = requests.get("http://localhost:8000/hash", params=param).json()
                    en = time()
                    hash_avg += en-st
                    param = {"password": password, "hash": res["result"]}
                    st = time()
                    res = requests.get("http://localhost:8000/verify", params=param).json()
                    en = time()
                    assert res["result"]=="True"
                    verify_avg += en-st
                temp_res = {"hash": hash_avg/30, "verify": verify_avg/30, "memory": s*r*b*p}
                result[f'{s}-{r}-{b}-{p}'] = temp_res.copy()
                
print(result)
with open('result.json', 'w+') as fp:
    json.dump(result, fp)
