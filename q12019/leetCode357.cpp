// CMakeProject1.cpp : Defines the entry point for the application.
// Problem URL: https://leetcode.com/problems/count-numbers-with-unique-digits/

#include "pch.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <set>

using namespace std;

class SolutionOld {
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

class Solution {
private:
	vector<string> _baseStrings;

	vector<string> getDuplicateStrings(int n) {
		if (n <= 2)
			return _baseStrings;
		
		vector<string> retItems;
		auto previousStep = getDuplicateStrings(n - 1);

		for (auto str : previousStep) {
			// Adding in zeros
			for (auto it = str.begin() + 1; it != str.end(); it++) {
				for( int i=0; i<=9; i++) {
					auto tmp(str);
					str.insert(it, '0' + i);
					retItems.emplace_back(str);
					str = tmp;
				}
			}


		}

		return retItems;
	}

public:
	Solution() {
		_baseStrings.emplace_back("11");
		_baseStrings.emplace_back("22");
		_baseStrings.emplace_back("33");
		_baseStrings.emplace_back("44");
		_baseStrings.emplace_back("55");
		_baseStrings.emplace_back("66");
		_baseStrings.emplace_back("77");
		_baseStrings.emplace_back("88");
		_baseStrings.emplace_back("99");
	}

	int countNumbersWithUniqueDigits(int n) {
		// Base case
		if (n == 1) return 10;

		auto vecStr = getDuplicateStrings(n);
		auto len = pow(10, n);
		return len - vecStr.size();
	}
};

int main() {
	Solution s;

	// Should output 739
	cout << s.countNumbersWithUniqueDigits(3) << endl;

	return 0;
}

