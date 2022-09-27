import itertools
import json

statements = [
    "Blonde Innocent",
    "White Innocent",
    "Old Innocent",
    "Brunette Innocent",
    "Blonde Spoke to Art",
    "Blonde didn't Speak to Art",
    "Brunette is killer",
    "The Men killed Art"
]


def permute(lis):
    return [list(i) for i in set(itertools.permutations(lis))]


def give_final(lis):
    Bdsa = lis[4]
    Bri = lis[3]
    Oi = lis[2]
    Wi = lis[1]
    return lis + [not Bdsa, not Bri, Wi ^ Oi]


def check(lis):
    return lis.count(True) == 4 and lis[:4].count(False) == 1


def set_dict(lis):
    final = dict()
    for i in range(len(lis)):
        final[statements[i]] = lis[i]
    return final


def generate(n):
    lt = [True for j in range(n)]
    lf = [False for j in range(5-n)]
    return lt+lf


solutions = []
cor_solutions = []

for i in range(1, 5):
    for lis in permute(generate(i)):
        solutions.append(lis)

for lis in solutions:
    if check(give_final(lis)):
        cor_solutions.append(give_final(lis))

final = []

for ans in cor_solutions:
    final.append(set_dict(ans))

json_object = json.dumps(final, indent=4)

with open("solution.json", "w") as outfile:
    outfile.write(json_object)
