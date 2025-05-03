#include <iostream>
#include <bits/stdc++.h>
#include <common.h>

using namespace std;

string stringNumAdd(string s1, string s2)
{
    if (s1.size() == 0 && s2.size() == 0)
    {
        return "0";
    }
    string result = "";
    int carry = 0, p1 = s1.size() - 1, p2 = s2.size() - 1;
    while(p1 >= 0 || p2 >= 0 || carry > 0) {
        int sum = 0;
        if (p1 >= 0) sum += s1[p1--]-'0';
        if (p2 >= 0) sum += s2[p2--]-'0';
        if (carry) sum += carry;
        result = to_string(sum%10) + result;
        carry = sum / 10;
    }
    return result;
}

int main()
{
    int limit = 10000, count = 0;
    for (int i = 0; i < limit; i++)
    {
        int N = 49; // Less than 50 iterations
        string num = to_string(i);
        bool isLychrel = true;
        for (int j = 0; j < N; j++)
        {
            string temp = num;
            reverse(temp.begin(), temp.end());
            num = stringNumAdd(num, temp);
            if (isPalindrome(num))
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
