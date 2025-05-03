#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <stdexcept>
#include <common.h>
#include <bits/stdc++.h>

using namespace std;

enum class Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank
{
    HighCard = 1,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,
};

std::ostream &operator<<(std::ostream &os, Rank rank)
{
    switch (rank)
    {
    case Rank::HighCard:
        os << "HighCard";
        break;
    case Rank::OnePair:
        os << "OnePair";
        break;
    case Rank::TwoPair:
        os << "TwoPair";
        break;
    case Rank::ThreeOfAKind:
        os << "ThreeOfAKind";
        break;
    case Rank::Straight:
        os << "Straight";
        break;
    case Rank::Flush:
        os << "Flush";
        break;
    case Rank::FullHouse:
        os << "FullHouse";
        break;
    case Rank::FourOfAKind:
        os << "FourOfAKind";
        break;
    case Rank::StraightFlush:
        os << "StraightFlush";
        break;
    case Rank::RoyalFlush:
        os << "RoyalFlush";
        break;
    default:
        os << "Unknown Rank";
        break;
    }
    return os;
}

enum class Value
{
    None = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class Hand
{
public:
    vector<Suit> suites;
    vector<Value> values;
    Value rankScore;

    Hand(const string &input)
    {
        istringstream iss(input);
        string card;
        while (iss >> card)
        {
            if (card.length() < 2 || card.length() > 3)
                throw invalid_argument("Invalid card format: " + card);

            string valueStr = card.substr(0, card.length() - 1);
            char suitChar = card.back();

            values.push_back(parseValue(valueStr));
            suites.push_back(parseSuit(suitChar));
        }
        sort(values.begin(), values.end());
        sort(suites.begin(), suites.end());
    }

    pair<Rank, Value> getHandRank() const
    {
        if (this->isRoyalFlush() != Value::None)
        {
            return {Rank::RoyalFlush, this->isRoyalFlush()};
        }
        else if (this->isStraightFlush() != Value::None)
        {
            return {Rank::StraightFlush, this->isStraightFlush()};
        }
        else if (this->isFourOfAKind() != Value::None)
        {
            return {Rank::FourOfAKind, this->isFourOfAKind()};
        }
        else if (this->isFullHouse() != Value::None)
        {
            return {Rank::FullHouse, this->isFullHouse()};
        }
        else if (this->isFlush() != Value::None)
        {
            return {Rank::Flush, this->isFlush()};
        }
        else if (this->isStraight() != Value::None)
        {
            return {Rank::Straight, this->isStraight()};
        }
        else if (this->isThreeOfAKind() != Value::None)
        {
            return {Rank::ThreeOfAKind, this->isThreeOfAKind()};
        }
        else if (this->isTwoPair() != Value::None)
        {
            return {Rank::TwoPair, this->isTwoPair()};
        }
        else if (this->isOnePair() != Value::None)
        {
            return {Rank::OnePair, this->isOnePair()};
        }
        else
        {
            return {Rank::HighCard, values[4]};
        }
    }

    bool operator<(const Hand &other) const
    {
        auto rank1 = getHandRank();
        auto rank2 = other.getHandRank();

        if (rank1.first != rank2.first)
            return static_cast<int>(rank1.first) < static_cast<int>(rank2.first);
        else if(rank1.second != rank2.second)
        {
            return static_cast<int>(rank1.second) < static_cast<int>(rank2.second);
        }

        for (int i = 4; i >= 0; i--)
        {
            if (values[i] < other.values[i])
            {
                return true;
            }
        }
        return false;
    }

private:
    Value isRoyalFlush() const
    {
        if (set(suites.begin(), suites.end()).size() == 1)
        {
            if (values[0] == Value::Ten && values[1] == Value::Jack && values[2] == Value::Queen &&
                values[3] == Value::King && values[4] == Value::Ace)
            {
                return Value::Ace;
            }
        }
        return Value::None;
    }

    Value isStraightFlush() const
    {
        if (set(suites.begin(), suites.end()).size() == 1)
        {
            for (int i = 1; i < 5; i++)
            {
                if (static_cast<int>(values[i]) != static_cast<int>(values[i - 1]) + 1)
                {
                    return Value::None;
                }
            }
            return values[4];
        }
        return Value::None;
    }

    Value isFourOfAKind() const
    {
        if (values[0] == values[3])
        {
            return values[3];
        }
        else if (values[1] == values[4])
        {
            return values[4];
        }
        return Value::None;
    }

    Value isFullHouse() const
    {
        if (set(values.begin(), values.end()).size() == 2)
        {
            if (isFourOfAKind() == Value::None)
            {
                return values[4];
            }
        }
        return Value::None;
    }

    Value isFlush() const
    {
        if (set(suites.begin(), suites.end()).size() == 1)
        {
            return values[4];
        }
        return Value::None;
    }

    Value isStraight() const
    {
        for (int i = 1; i < 5; i++)
        {
            if (static_cast<int>(values[i]) != static_cast<int>(values[i - 1]) + 1)
            {
                return Value::None;
            }
        }
        return values[4];
    }

    Value isThreeOfAKind() const
    {
        for (auto num : set(values.begin(), values.end()))
        {
            if (count(values.begin(), values.end(), num) == 3)
            {
                return num;
            }
        }
        return Value::None;
    }

    Value isTwoPair() const
    {
        int numPairs = 0;
        Value maxVal = Value::None;
        for (auto num : set(values.begin(), values.end()))
        {
            if (count(values.begin(), values.end(), num) == 2)
            {
                numPairs++;
                maxVal = max(maxVal, num);
            }
        }
        return numPairs == 2 ? maxVal : Value::None;
    }

    Value isOnePair() const
    {
        for (auto num : set(values.begin(), values.end()))
        {
            if (count(values.begin(), values.end(), num) == 2)
            {
                return num;
            }
        }
        return Value::None;
    }

    Value parseValue(const string &val)
    {
        static unordered_map<string, Value> valueMap = {
            {"2", Value::Two}, {"3", Value::Three}, {"4", Value::Four}, {"5", Value::Five}, {"6", Value::Six}, {"7", Value::Seven}, {"8", Value::Eight}, {"9", Value::Nine}, {"T", Value::Ten}, {"J", Value::Jack}, {"Q", Value::Queen}, {"K", Value::King}, {"A", Value::Ace}};

        auto it = valueMap.find(val);
        if (it == valueMap.end())
            throw invalid_argument("Invalid value: " + val);
        return it->second;
    }

    Suit parseSuit(char suit)
    {
        switch (suit)
        {
        case 'H':
            return Suit::Hearts;
        case 'D':
            return Suit::Diamonds;
        case 'C':
            return Suit::Clubs;
        case 'S':
            return Suit::Spades;
        default:
            throw invalid_argument(string("Invalid suit: ") + suit);
        }
    }
};

int main()
{
    ifstream file("./files/poker.txt");
    if (!file)
    {
        cerr << "Failed to open file.\n";
        return 1;
    }

    string line;
    int playerOneWins = 0;
    while (getline(file, line))
    {
        istringstream iss(line);
        vector<string> cards;
        string card;

        while (iss >> card)
        {
            cards.push_back(card);
        }

        if (cards.size() != 10)
        {
            cerr << "Invalid line: " << line << "\n";
            continue;
        }

        ostringstream oss1;
        for (int i = 0; i < 5; ++i)
            oss1 << cards[i] << " ";
        string player1Str = oss1.str();
        player1Str.pop_back();

        ostringstream oss2;
        for (int i = 5; i < 10; ++i)
            oss2 << cards[i] << " ";
        string player2Str = oss2.str();
        player2Str.pop_back();

        auto hand1 = Hand(player1Str);
        auto hand2 = Hand(player2Str);
        string sign = " == ";
        if (!(hand1 < hand2))
        {
            sign = " > ";
            playerOneWins++;
        }
        else
        {
            sign = " < ";
        }
        cout << player1Str << ": " << hand1.getHandRank().first << sign;
        cout << player2Str << ": " << hand2.getHandRank().first << "\n";
    }

    cout << "Player 1 wins: " << playerOneWins << endl;
    return 0;
}