// Problem URL: https://leetcode.com/problems/count-numbers-with-unique-digits/

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <set>

using namespace std;

class Solution {
private:
	bool hasDuplicateDigit(int num) {
		stringstream oss;
		set<char> charSet;

		oss << num;
		string s(oss.str());

		for (const auto& ch : s) {
			auto ret = charSet.insert(ch);
			if (ret.second == false)
				return true;
		}

		return false;
	}
public:
	int countNumbersWithUniqueDigits(int n) {
		auto upperBound = pow(10, n);
		int count = 0;
		for (auto i = 0; i < upperBound; i++) {
			if (hasDuplicateDigit(i) == false)	count++;
		}

		return count;
	}
};
