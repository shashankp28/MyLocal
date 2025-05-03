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
string stringNumAdd(string s1, string s2);
string stringNumExponent(int a, int b);
string stringNumMultiply(string s1, string s2);
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
