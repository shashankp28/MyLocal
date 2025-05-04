#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int num);
vector<bool> createPrimeTable(int n);
int combinations(int n, int r);
bool isPalindrome(string str);
int digitSum(string num);
template <typename T>
void printVector(const vector<T> &vec)
{
    for (const auto &val : vec)
    {
        cout << val << ", ";
    }
    cout << "\n";
}

#endif // COMMON_H
