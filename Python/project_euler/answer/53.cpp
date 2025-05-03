#include <iostream>
#include <bits/stdc++.h>
#include <common.h>

using namespace std;

bool isSameDigits(int num1, int num2)
{
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main()
{
    int lessResult = 0;
    for (int n = 1; n <= 100; n++)
    {
        int exceedR = -1;
        for (int r = 0; r <= n / 2; r++)
        {
            if (combinations(n, r) > 1000000)
            {
                cout << n << "C" << r << "=" << combinations(n, r) << "\n";
                exceedR = r;
                break;
            }
        }
        if (exceedR == -1)
            lessResult += n + 1;
        else
            lessResult += 2 * exceedR;
    }
    cout << "Less than Million: " << lessResult << "\n";
    cout << "Answer: " << (101 * 102 / 2 - 1) - lessResult << "\n";
}
