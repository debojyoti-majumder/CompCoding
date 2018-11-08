// Problem URL: https://leetcode.com/problems/short-encoding-of-words/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		string minimizedString;
		
		sort(words.begin(), words.end(), [](const string& r1, const string& r2) -> bool {
			return r1.length() > r2.length();
		});

		for (const auto& word : words) {
			auto pos = minimizedString.find(word);

			if (pos == string::npos) {
				minimizedString += word;
				minimizedString += "#";
			}
			else if (minimizedString[pos + word.length()] != '#') {
				minimizedString += word;
				minimizedString += "#";
			}
		}

		return minimizedString.length();
	}
};

int main() {
	Solution s;
	vector<string> input{"time", "me", "bell"};
	vector<string> input2{ "abcd", "bcd", "abc", "efg", "fg" };

	// Should output 10
	cout << s.minimumLengthEncoding(input) << endl;

	cout << s.minimumLengthEncoding(input2) << endl;
	return 0;
}
