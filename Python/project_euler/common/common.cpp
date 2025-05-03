#include <iostream>
#include <cmath>
#include "common.h"

using namespace std;

bool isPrime(int num)
{
	if (num <= 1)
		return false;
	if (num == 2)
		return true;
	for (int i = 2; i <= (int)std::sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

std::vector<bool> createPrimeTable(int n)
{
	std::vector<bool> result(n + 1, true);
	result[0] = result[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (!result[i])
			continue;
		for (int j = 2; i * j <= n; j++)
		{
			result[i * j] = false;
		}
	}
	return result;
}

int combinations(int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	return (n - r + 1) * combinations(n, r - 1) / r;
}

bool isPalindrome(string str)
{
	for (int i = 0; i < (int)str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}

string stringNumAdd(string s1, string s2)
{
	if (s1.size() == 0 && s2.size() == 0)
	{
		return "0";
	}
	string result = "";
	int carry = 0, p1 = s1.size() - 1, p2 = s2.size() - 1;
	while (p1 >= 0 || p2 >= 0 || carry > 0)
	{
		int sum = 0;
		if (p1 >= 0)
			sum += s1[p1--] - '0';
		if (p2 >= 0)
			sum += s2[p2--] - '0';
		if (carry)
			sum += carry;
		result = to_string(sum % 10) + result;
		carry = sum / 10;
	}
	return result;
}

string stringNumMultiply(string s1, string s2)
{
	if (s1.size() == 0 || s2.size() == 0)
	{
		return "0";
	}
	if (s1.size() == 1 && stoi(s1) == 0)
	{
		return "0";
	}
	if (s2.size() == 1 && stoi(s2) == 0)
	{
		return "0";
	}
	string result = "";
	int carry = 0;
	for (int p2 = s2.size() - 1; p2 >= 0; p2--)
	{
		int p1 = s1.size() - 1;
		string tempRes = "";
		while (p1 >= 0 || carry > 0)
		{
			int sum = 0;
			if (p1 >= 0)
				sum += (s1[p1--] - '0') * (s2[p2] - '0');
			if (carry)
				sum += carry;
			tempRes = to_string(sum % 10) + tempRes;
			carry = sum / 10;
		}
		int itNo = s2.size() - 1 - p2;
		tempRes += string(itNo, '0');
		result = stringNumAdd(result, tempRes);
	}
	return result;
}

string stringNumExponent(int a, int b)
{
	if (b == 0)
		return "1";
	if (b == 1)
		return to_string(a);
	string result;
	string halfMult = stringNumExponent(a, b / 2);
	if (b % 2 == 0)
	{
		result = stringNumMultiply(halfMult, halfMult);
	}
	else
	{
		string tempRes = stringNumMultiply(halfMult, to_string(a));
		result = stringNumMultiply(halfMult, tempRes);
	}
	return result;
}

int digitSum(string num)
{
	int sum = 0;
	for (auto ch : num)
	{
		sum += ch - '0';
	}
	return sum;
}
