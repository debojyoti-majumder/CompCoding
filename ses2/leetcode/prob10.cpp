// Problem URL: https://leetcode.com/problems/minimum-genetic-mutation/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
	string _end;
	vector<string> _bank;

	vector<char> getPossibleMoves(string data, int pos) {
		vector<char> validMutations;

		for (auto rule : _bank) {

		}

		return validMutations;
	}

	int recurseHelper(const string start, int pos=0 ) {
		if (pos == start.size())
			return 0;

		if (start[pos] != _end[pos]) {	
			auto possiblities = getPossibleMoves(start, pos);
			vector<int> possibleOutcomes;

			for (auto poss : possiblities) {
				auto modString = start;
				modString[pos] = poss;

				possibleOutcomes.push_back(recurseHelper(modString, end, ++pos));
			}

			auto it = min_element(possibleOutcomes.begin(), possibleOutcomes.end());
			auto v = it == possibleOutcomes.end() ? 0 : *it;

			return v + 1;
		}
		else {
			return recurseHelper(start,pos++);
		}
	}

public:
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
	s.minMutation("AACCGGTT", "AACCGGTA", validNorms1);

	// Test case 2: Output 2
	vector<string> validNorms2{ "AACCGGTA", "AACCGCTA", "AAACGGTA" };
	s.minMutation("AACCGGTT", "AAACGGTA", validNorms2);

	// Test case 3: Output 3
	vector<string> validNorms3{ "AAAACCCC", "AAACCCCC", "AACCCCCC" };
	s.minMutation("AAAAACCC", "AACCCCCC", validNorms3);

	return 0;
}

