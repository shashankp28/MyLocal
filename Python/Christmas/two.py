"""
Day 2 of Christmas Challenge
"""


RED, GREEN, BLUE = 12, 13, 14


def decouple_count(data):
    """
    Decouple the count and the color
    """
    data = data.strip().split(" ")
    return int(data[0]), data[1]


def power_set(games):
    """
    Verify if the colors are valid
    """
    split_games = [[decouple_count(y) for y in x.split(",")]
                   for x in games.split(";")]
    all_valid = True
    color_map = {
        "red": 0,
        "green": 0,
        "blue": 0
    }
    for game in split_games:
        for ind in game:
            color_map[ind[1]] = max(color_map[ind[1]], ind[0])
    return color_map["red"] * color_map["green"] * color_map["blue"]


color_map = {
    "red": RED,
    "green": GREEN,
    "blue": BLUE
}

with open("input2_0", "r", encoding="utf-8") as f:
    TOTAL = 0
    for line in f.readlines():
        line = line.strip()
        game, values = line.split(":")
        game_id = int(game.split(" ")[1])
        PS = power_set(values)
        print(PS)
        TOTAL += PS

    print()
    print("Total:", TOTAL)
