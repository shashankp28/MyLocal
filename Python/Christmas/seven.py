class Hand:

    card_values = {"A": 13, "K": 12, "Q": 11, "T": 10}
    card_values.update({str(i): i for i in range(2, 10)})
    card_values["J"] = 1

    def __init__(self, hand: str):
        assert len(hand) == 5
        self.hand = hand

    def get_type(self):
        count_map = {}
        for c in self.hand:
            count_map[c] = count_map.get(c, 0) + 1
        counts = [count for key, count in count_map.items() if key != "J"]
        counts.sort()
        if len(counts) == 0 or len(counts) == 1:
            return 6
        counts[-1] += count_map.get("J", 0)
        if counts == [1, 4]:
            return 5
        if counts == [2, 3]:
            return 4
        if counts == [1, 1, 3]:
            return 3
        if counts == [1, 2, 2]:
            return 2
        if counts == [1, 1, 1, 2]:
            return 1
        return 0

    def get_hand_values(self):
        return [self.card_values[c] for c in self.hand]

    def __lt__(self, hand2):
        type1 = self.get_type()
        type2 = hand2.get_type()
        if type1 != type2:
            return type1 < type2
        hand1_val = self.get_hand_values()
        hand2_val = hand2.get_hand_values()
        for i in range(5):
            if hand1_val[i] != hand2_val[i]:
                return hand1_val[i] < hand2_val[i]
        return False

    def __repr__(self):
        return self.hand


hands = []

with open("./inputs/input7", "r", encoding='utf-8') as f:
    lines = f.readlines()
    for line in lines:
        hand, bid = line.strip().split()
        hands.append((Hand(hand), int(bid)))

hands.sort(key=lambda x: x[0])
total = 0
for i, (hand, bid) in enumerate(hands):
    total += bid * (i + 1)

print("Total: ", total)
