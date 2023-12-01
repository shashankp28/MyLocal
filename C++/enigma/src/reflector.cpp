#include <iostream>
#include <stdexcept>
#include "reflector.h"

Reflector::Reflector(pair<int, int> reflectorConfig[13])
{
    for (int i = 0; i < 26; i++)
    {
        this->reflectorConfig[i] = -1;
    }
    for (int i = 0; i < 13; i++)
    {
        if (reflectorConfig[i].first < 0 || reflectorConfig[i].first > 25 ||
            reflectorConfig[i].second < 0 || reflectorConfig[i].second > 25)
        {
            throw invalid_argument("Reflector configuration is invalid");
        }
        if (this->reflectorConfig[reflectorConfig[i].first] != -1 ||
            this->reflectorConfig[reflectorConfig[i].second] != -1)
        {
            throw invalid_argument("Reflector configuration is invalid");
        }
        this->reflectorConfig[reflectorConfig[i].first] = reflectorConfig[i].second;
        this->reflectorConfig[reflectorConfig[i].second] = reflectorConfig[i].first;
    }
}

int Reflector::getReflection(int index)
{
    if (index < 0 || index > 25)
    {
        throw invalid_argument("Invalid index");
    }
    return this->reflectorConfig[index];
}

void Reflector::printReflector()
{
    cout << "Reflector configuration:" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << (char)('A' + i) << " -> " << (char)('A' + this->reflectorConfig[i]) << endl;
    }
    cout << endl;
}