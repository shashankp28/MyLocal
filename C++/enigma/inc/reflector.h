#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <utility>
using namespace std;

class Reflector
{

private:
    int reflectorConfig[26];

public:
    Reflector(pair<int, int> reflectorConfig[13]);
    int getReflection(int index);
    void printReflector();
};

#endif