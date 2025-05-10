#include <iostream>
#include <bits/stdc++.h>
#include <common.h>
#include <BigInt.hpp>

int main() {
    int N = 2077;
    int a_low = 1, a_high = N-2;
    int b_low = 2, b_high = N-2;

    while (a_low <= a_high && b_low <= b_high)
    {
        int a_mid = (a_low + a_high) / 2;
        int b_mid = (b_low + b_high) / 2;

        int Z = (1 + a_mid) * (1 + b_mid) - a_mid * N;

        if (Z == 0)
        {
            // Solution found
            cout << "a = " << a_mid << ", b = " << b_mid << endl;
            break;
        }
        else if (Z < 0)
        {
            // Need smaller a
            a_high = a_mid - 1;
        }
        else
        {
            // Need smaller b
            b_high = b_mid - 1;
        }
    }
    return 0;
}
