def get_diff_list(history):
    diff_list = []
    for i in range(1, len(history)):
        diff_list.append(history[i] - history[i-1])
    return diff_list


def extrapolate(history):
    start_values = [history[0]]
    curr_history = history.copy()
    while sum(abs(x) for x in curr_history) > 0:
        curr_history = get_diff_list(curr_history)
        start_values.append(curr_history[0])
    alt = [1, -1]
    return sum(val*alt[i % 2] for i, val in enumerate(start_values))


histories = []

with open("./inputs/input9", "r", encoding="utf-8") as f:
    for line in f:
        history = list(map(int, line.strip().split()))
        if history == []:
            break
        histories.append(history)

count = 0
for history in histories:
    ext = extrapolate(history)
    print(history, ext)
    count += ext

print("Total:", count)
