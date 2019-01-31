// Problem URL: https://leetcode.com/problems/minimum-genetic-mutation/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
	string _end;
	vector<string> _bank;
	vector<char> _validChars;

	set<string> getPossibleMoves(string data, int pos) {
		set<string> validMutations;

		for (auto mods : _validChars) {
			if (mods == data[pos])
				continue;

			for (auto rule : _bank) {
				auto ch = rule[pos];
				if (ch == mods) {
					auto val = data;
					val[pos] = ch;
					validMutations.insert(val);
				}
			}
		}

		return validMutations;
	}

	int recurseHelper(const string start, int pos=0 ) {
		if (pos - 1 == start.size())
			return 0;

		if (start[pos] != _end[pos]) {	
			auto possiblities = getPossibleMoves(start, pos);
			vector<int> possibleOutcomes;

			for (auto poss : possiblities) {
				possibleOutcomes.push_back(recurseHelper(poss, ++pos));
			}

			auto it = min_element(possibleOutcomes.begin(), possibleOutcomes.end());
			auto v = it == possibleOutcomes.end() ? 0 : *it;
			return v + 1;
		}
		else {
			return recurseHelper(start,++pos);
		}
	}

public:
	Solution() {
		_validChars.push_back('A');
		_validChars.push_back('C');
		_validChars.push_back('G');
		_validChars.push_back('T');
	}

	int minMutation(const string start, 
					const string end, 
					const vector<string>& bank) {
		// Initilize memebers
		_end = end;
		_bank = bank;

		// Calling the helper function
		return recurseHelper(start);
	}
};

int main() {
	Solution s;
	
	// Test case 1: Output 1
	vector<string> validNorms1{ "AACCGGTA" };
	cout << s.minMutation("AACCGGTT", "AACCGGTA", validNorms1) << endl;

	// Test case 2: Output 2
	vector<string> validNorms2{ "AACCGGTA", "AACCGCTA", "AAACGGTA" };
	cout << s.minMutation("AACCGGTT", "AAACGGTA", validNorms2) << endl;

	// Test case 3: Output 3
	vector<string> validNorms3{ "AAAACCCC", "AAACCCCC", "AACCCCCC" };
	cout << s.minMutation("AAAAACCC", "AACCCCCC", validNorms3) << endl;

	return 0;
}

