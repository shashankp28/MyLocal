#include <iostream>
#include <bits/stdc++.h>
#include <common.h>
#include <BigInt.hpp>

using namespace std;

int main()
{
    int limit = 10000, count = 0;
    for (int i = 0; i < limit; i++)
    {
        int N = 49; // Less than 50 iterations
        BigInt num = BigInt(i);
        bool isLychrel = true;
        for (int j = 0; j < N; j++)
        {
            string temp = num.to_string();
            reverse(temp.begin(), temp.end());
            num += BigInt(temp);
            if (isPalindrome(num.to_string()))
            {
                isLychrel = false;
                break;
            }
        }
        if (isLychrel)
        {
            count++;
            cout << i << " is Lychrel" << "\n";
        }
    }
    cout << "Lychrel Count: " << count << "\n";
    return 0;
}
