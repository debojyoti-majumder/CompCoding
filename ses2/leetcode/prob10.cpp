// Problem URL: https://leetcode.com/problems/minimum-genetic-mutation/description/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
	string _start;
	string _end;
	vector<string> _bank;

	int recurseHelper(int pos=0) {
		if (pos == _start.size())
			return 0;

		if (_start[pos] != _end[pos]) {	
			return 1;
		}
		else {
			return recurseHelper(pos++);
		}
	}

public:
	int minMutation(const string start, 
					const string end, 
					const vector<string>& bank) {
		// Initilize memebers
		_start = start;
		_end = end;
		_bank = bank;

		// Calling the helper function
		return recurseHelper();
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
