// Problem URL: https://leetcode.com/problems/reconstruct-original-digits-from-english/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
private:
	vector<string> _numberString;

	bool processDigit(string& s, int index) {
		string copyString(s);

		for (const auto& ch : _numberString[index]) {
			auto it = copyString.find(ch, 0);
			if (it == -1)
				return false;
			else {
				auto in = copyString.find(ch);
				copyString.erase(copyString.begin() + in);
			}
		}

		s = copyString;
		return true;
	}

public:
	Solution() {
		_numberString.emplace_back("zero");
		_numberString.emplace_back("one");
		_numberString.emplace_back("two");
		_numberString.emplace_back("three");
		_numberString.emplace_back("four");
		_numberString.emplace_back("five");
		_numberString.emplace_back("six");
		_numberString.emplace_back("seven");
		_numberString.emplace_back("eight");
		_numberString.emplace_back("nine");
	}

	string originalDigits(string s) {
		string accString("");

		while (s.length()) {
			for (int i = 0; i < 10; i++) {
				if (processDigit(s, i)) {
					stringstream ss;
					ss << i;
					accString += ss.str();
				}
			}
		}

		return accString;
	}
};

int main() {
	Solution s;
	cout << s.originalDigits("oentwoterhe") << endl;

	return 0;
}
