// Problem URL: https://leetcode.com/problems/is-subsequence/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isSubsequence(string subSequence, string biggerString) {
		unsigned int seqCounter = 0;
		auto sz = subSequence.size();

		if (sz == 0)
			return true;

		for (size_t i = 0; i < biggerString.size(); i++) {
			auto ch = biggerString[i];

			if (subSequence[seqCounter] == ch)
				seqCounter++;

			if (seqCounter == subSequence.size())
				return true;
		}

		return false;
	}
};

int main() {
	Solution s;

	cout << s.isSubsequence("abc", "ahbgdc") << endl;  		// Should return true
	cout << s.isSubsequence("axc", "ahbgdc") << endl;		// Should return false
	cout << s.isSubsequence("b", "c") << endl;				// Should return false

	return 0;
}
