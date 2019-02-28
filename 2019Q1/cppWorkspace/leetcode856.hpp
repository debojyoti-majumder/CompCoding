// Problem URL: https://leetcode.com/problems/score-of-parentheses/
// Leetcode Id: 856
// Issue ID: 7

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	bool isBalanced(string expr) {
		return true;
	}

public:
	int scoreOfParentheses(string S) {
		if (S == "()")
			return 1;

		auto inputLength = S.length();
		auto firstChar = S[0];
		auto lastChar = S[inputLength - 1];

		if (firstChar == '(' && lastChar == ')') {
			auto str = S.substr(1, inputLength - 2);
			if (isBalanced(str))
				return 2 * scoreOfParentheses(str);
			else {
				cout << "This is to be looked later" << endl;
			}
		}

		return -1;
	}
};

int main() {
	auto inp1 = "()";
	auto inp2{ "(())" };
	auto inp3{ "()()" };
	auto inp4{ "(()(()))" };

	Solution s;

	cout << s.scoreOfParentheses(inp1) << endl;
	cout << s.scoreOfParentheses(inp2) << endl;
	cout << s.scoreOfParentheses(inp3) << endl;
	cout << s.scoreOfParentheses(inp4) << endl;

	return 0;
}
