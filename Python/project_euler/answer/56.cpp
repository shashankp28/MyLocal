#include <iostream>
#include <bits/stdc++.h>
#include <common.h>

using namespace std;

int main()
{
    int maxSum = 0, A = 0, B = 0;
    for (int a = 1; a < 100; a++)
    {
        for (int b = 1; b < 100; b++)
        {
            string exp = stringNumExponent(a, b);
            cout << a << " ^ " << b << " = " << exp << "\n";
            int currSum = digitSum(exp);
            if (currSum > maxSum)
            {
                maxSum = currSum;
                A = a;
                B = b;
            }
        }
    }
    cout << "Max Digit Sum ( " << A << " ^ " << B << " ): " << maxSum << "\n";
    return 0;
}
