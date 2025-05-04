#include <iostream>
#include <bits/stdc++.h>
#include <common.h>
#include <numeric>
#include <BigInt.hpp>

using namespace std;

pair<BigInt, BigInt> getNext(BigInt n, BigInt d) {
    BigInt N = n + 2 * d;
    BigInt D = n + d;
    N /= gcd(N, D);
    D /= gcd(N, D);
    return {N, D};
}

int main()
{
    BigInt N = 1, D = 1;
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto nextFrac = getNext(N, D);
        N = nextFrac.first;
        D = nextFrac.second;
        cout << "Expansion(" << i + 1 << ") = " << N << " / " << D << "\n";
        count += N.to_string().size() > D.to_string().size();
    }
    cout << "Count = " << count << "\n";
    return 0;
}
