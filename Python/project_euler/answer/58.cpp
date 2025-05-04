#include <iostream>
#include <bits/stdc++.h>
#include <common.h>
#include <BigInt.hpp>

using namespace std;

int main()
{
    int sideLength = 3, primeCount = 0;
    while (true)
    {
        int n = sideLength / 2;
        int diag1 = 4 * n * n - 2 * n + 1;
        int diag2 = (2 * n + 1) * (2 * n + 1);
        int diag3 = 4 * n * n + 1;
        int diag4 = 4 * n * n + 2 * n + 1;
        if (isPrime(diag1))
            primeCount++;
        if (isPrime(diag2))
            primeCount++;
        if (isPrime(diag3))
            primeCount++;
        if (isPrime(diag4))
            primeCount++;
        int total = 4 * n + 1;
        double percentage = (double)primeCount / total;
        cout << "Side Length: " << sideLength << " Percentage Primes: " << percentage << "\n";
        if (percentage < 0.1)
        {
            break;
        }
        sideLength += 2;
    }
    return 0;
}
