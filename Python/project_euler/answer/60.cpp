#include <iostream>
#include <bits/stdc++.h>
#include <common.h>
#include <BigInt.hpp>

using namespace std;

int main()
{
    vector<int> primes = createPrimeList(673);
    // Remove 2: It won't be a part
    primes.erase(primes.begin());
    int lowestSum = INT_MAX;
    vector<int> lowestPrimes;
    int numCombs = 4;
    int total = combinations(primes.size(), numCombs);
    int index = 0;
    for (auto &comb : generateCombinations(primes, numCombs))
    {
        if (index % 500000 == 0)
        {
            cout << "Current progress: " << (double)100 * index / total << " %\n";
        }
        bool isValid = true;
        for (auto &primeCombs : generateCombinations(comb, 2))
        {
            string p1 = to_string(primeCombs[0]);
            string p2 = to_string(primeCombs[1]);
            if (!isPrime(stoi(p1 + p2)) || !isPrime(stoi(p2 + p1)))
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
        {
            int sum = accumulate(comb.begin(), comb.end(), 0);
            if (sum < lowestSum)
            {
                cout << "\n\n Primes are: ";
                printVector(lowestPrimes);
                lowestSum = sum;
                lowestPrimes = comb;
                cout << "Sum: " << lowestSum << "\n\n";
            }
        }
        index++;
    }
    if (lowestSum != INT_MAX)
    {
        cout << "Primes are: ";
        printVector(lowestPrimes);
        cout << "Sum: " << lowestSum << "\n\n";
    }
    return 0;
}