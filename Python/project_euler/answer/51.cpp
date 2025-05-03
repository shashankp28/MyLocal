#include <iostream>
#include <bits/stdc++.h>
#include <common.h>

using namespace std;

void getPermutations(int digits, string curr, vector<string> &result,
					 vector<char> & possibilities)
{
	if((int)curr.size() == digits) {
		result.push_back(curr);
		return;
	}
	for(auto ch : possibilities) {
		getPermutations(digits, curr + ch, result, possibilities);
	}
}

string replaceChar(const string &input, char toReplace, char replaceWith)
{
	std::string modifiedString = input;

	for (char &ch : modifiedString)
	{
		if (ch == toReplace)
		{
			ch = replaceWith;
		}
	}
	return modifiedString;
}

int main() {
	vector<bool> primeTable = createPrimeTable(1000000);
	vector<char> possibilites = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*'};
	int minNum = INT_MAX, targetPrimes = 8;
	string minFamily = "";
	for (int digits = 2; digits <= 6; digits++)
	{
		vector<string> perms;
		getPermutations(digits, "", perms, possibilites);
		for(auto family : perms) {
			int numPrimes = 0;
			for (int rep = 0; rep < 10; rep++) {
				if(rep == 0 && family[0]=='*')
					continue;
				int target = stoi(replaceChar(family, '*', '0' + rep));
				numPrimes += primeTable[target];
			}
			if(numPrimes == targetPrimes) {
				char rep = family[0] == '*' ? '1' : '0';
				minNum = min(minNum, stoi(replaceChar(family, '*', rep)));
				minFamily = family;
			}
		}
		if (minNum != INT_MAX)
		{
			cout << "Answer: " << minNum << "\n";
			cout << "Family: " << minFamily << "\n";
			break;
		}
	}
	return 0;
}
