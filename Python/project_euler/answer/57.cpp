#include <iostream>
#include <bits/stdc++.h>
#include <common.h>
#include <numeric>

using namespace std;

pair<int, int> getNext(int n, int d) {
    int N = n + 2 * d;
    int D = n + d;
    N /= gcd(N, D);
    D /= gcd(N, D);
    return {N, D};
}

int main()
{
    int N = 1, D = 1, count = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto nextFrac = getNext(N, D);
        N = nextFrac.first;
        D = nextFrac.second;
        cout << "Expansion(" << i + 1 << ") = " << N << " / " << D << "\n";
        count += to_string(N).size() > to_string(D).size();
    }
        cout << "Count = " << count;
    return 0;
}
