#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <common.h>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{
	if (num <= 1)
		return false;
	if (num == 2)
		return true;
	for (int i = 2; i <= (int)sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

vector<bool> createPrimeTable(int n)
{
	vector<bool> result(n + 1, true);
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

vector<int> createPrimeList(int n)
{
	vector<int> result;
	vector<bool> primes = createPrimeTable(n);
	for (int i = 0; i <= n; i++)
	{
		if(primes[i]) {
			result.push_back(i);
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

int digitSum(string num)
{
	int sum = 0;
	for (auto ch : num)
	{
		sum += ch - '0';
	}
	return sum;
}

vector<vector<int>> generateCombinations(vector<int> &elements, int r)
{
	vector<vector<int>> result;
	int n = elements.size();
	if (r > n || r < 0)
		return result;

	vector<bool> select(n, false);
	fill(select.end() - r, select.end(), true);

	do
	{
		vector<int> combination;
		for (int i = 0; i < n; ++i)
			if (select[i])
				combination.push_back(elements[i]);
		result.push_back(combination);
	} while (next_permutation(select.begin(), select.end()));

	return result;
}