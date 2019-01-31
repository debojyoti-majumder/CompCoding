// Ptoblem URL: https://leetcode.com/problems/decode-string/description/
// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
	// Should retrun the ] position turn
	int getDecodedString(const string& str, string& decode, int index) {
		return -1;
	}

public:
	string decodeString(string s) {
		string ret ="";
		int index = 0;

		while (true) {
			char a = s[index];
			if (isdigit(a)) {
				int v = a - 48;
			}
			else
				ret += a;
		}

		return ret;
	}
};

int main() {
	Solution s;
	cout << s.decodeString("2[abc]3[cd]ef") << endl;
	return 0;
}
