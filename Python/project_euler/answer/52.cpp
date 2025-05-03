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
    for (int i = 1; i < 1000000; i++)
    {
        int target = i * 2;
        bool isValid = true;
        for (int j = 3; j <= 6; j++)
        {
            if (!isSameDigits(target, i * j))
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
        {
            cout << "Answer: " << i << "\n";
            for (int j = 2; j <= 6; j++)
            {
                cout << i * j << " ";
            }
            cout << "\n";
        }
    }
}
