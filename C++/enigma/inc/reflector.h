#include <utility>

using namespace std;

#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector
{

private:
    int reflectorConfig[26];

public:
    Reflector(pair<int, int> reflectorConfig[26]);
    int getReflection(int index);
    void printReflector();
};

#endif