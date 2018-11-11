// Problem URL: https://www.hackerrank.com/challenges/funny-string/problem

#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
	string reverseString(s);
	reverse(reverseString.begin(), reverseString.end());

	auto sz = s.size();
	if (sz < 2)
		return "Funny";

	vector<int> diffArr1(sz, 0);
	vector<int> diffArr2(sz, 0);

	for (size_t i = 0; i < sz - 1; i++) {
		diffArr1[i] = abs(s[i] - s[i + 1]);
		diffArr2[i] = abs(reverseString[i] - reverseString[i + 1]);
	}

	for (size_t i = 0; i < sz - 1; i++) {
		if (diffArr1[i] != diffArr2[i])
			return "Not Funny";
	}

	return "Funny";
}


int main() {
	cout << funnyString("acxz") << endl;
	cout << funnyString("bcxz") << endl;

	return 0;
}
