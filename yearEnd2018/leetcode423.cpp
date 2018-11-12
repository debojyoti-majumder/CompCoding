// Problem URL: https://leetcode.com/problems/reconstruct-original-digits-from-english/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Solution {
private:
	list<string> _numberString;
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

	bool isDigitThere(string s, int index) {
		return true;
	}

	string originalDigits(string s) {
		return "";
	}
};

int main() {
	Solution s;
	cout << s.originalDigits("oentwoterhe") << endl;

	return 0;
}
