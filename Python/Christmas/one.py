"""
First question of Christmas Challenge
"""


def extract_digits(code: str):
    """
    Extracts the digits from a string
    """
    numbers = ["one", "two", "three", "four",
               "five", "six", "seven", "eight", "nine"]
    numbers_map = {number: index+1 for index, number in enumerate(numbers)}
    decoded = []
    for i in range(len(code)-1, -1, -1):
        if code[i].isdigit():
            decoded.append(int(code[i]))
            continue
        for j in range(i+1, i+6):
            if j > len(code):
                break
            if code[i:j] in numbers_map:
                decoded.append(numbers_map[code[i:j]])
                break
    decoded.reverse()
    assert len(decoded) != 0, "No digits found in string"
    return 10*decoded[0] + decoded[-1]


with open("input2", "r", encoding="utf-8") as file:
    TOTAL = 0
    for line in file:
        extracted = extract_digits(line)
        print(line, extracted)
        TOTAL += extracted

print("Total Answer:", TOTAL)
