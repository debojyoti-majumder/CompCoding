// Sess1.cpp: Defines the entry point for the console application.
// Problem https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
private:
	string trim(const std::string& str,
		const std::string& whitespace = " ")
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
			return ""; // no content

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	string revStr(const string& p) {
		ostringstream outString;

		for (auto it = p.rbegin(); it != p.rend(); it++)
			outString << *it;

		return outString.str();
	}

public:
	string reverseWords(string s) {
		istringstream str(s);
		string tokenlizedString;
		string outputString;

		while (getline(str, tokenlizedString, ' ')) {
			outputString += revStr(tokenlizedString) + " ";
		}

		return trim(outputString);
	}
};

int testmain() {
	// Test case 1: "Let's take LeetCode contest"
	// Output: "s'teL ekat edoCteeL tsetnoc"
	Solution s;
	cout << s.reverseWords("Let's take LeetCode contest") << endl;

	return 0;
}

