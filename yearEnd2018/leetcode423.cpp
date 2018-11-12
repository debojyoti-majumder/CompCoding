// Problem URL: https://leetcode.com/problems/reconstruct-original-digits-from-english/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	vector<string> _numberString;
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

	vector<int> isDigitThere(const string& s, int index) {
		vector<int> indexes;

		for (const auto& ch : _numberString[index]) {
			auto it = s.find(ch, 0);
			if (it == -1)
				return vector<int>{};
			else
				indexes.push_back((int)it);
		}

		return indexes;
	}

	string originalDigits(string s) {
		string accString("");

		while (s.length()) {
			for (int i = 0; i < 10; i++) {
				auto ind(isDigitThere(s, i));

				if (ind.size()) {
					accString += i;
					for (auto i : ind)
						s.erase(i, 1);
					break;
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
