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
		vector<char> symbolStack;

		for (const auto& ch : expr) {
			if (ch == '(') {
				symbolStack.emplace_back(ch);
			}
			else if (ch == ')') {
				if (symbolStack.size() == 0)
					return false;

				symbolStack.pop_back();
			}
		}
		
		auto bRet = symbolStack.size() == 0 ? true : false;
		return bRet;
	}

public:
	int scoreOfParentheses(string S) {
		int score = 0;

		if (S == "()")
			return 1;

		auto inputLength = S.length();
		auto firstChar = S[0];
		auto lastChar = S[inputLength - 1];

		if (firstChar == '(' && lastChar == ')') {
			auto str = S.substr(1, inputLength - 2);

			// If not balanced then break into multiple component
			if ( !isBalanced(str) ) {
				vector<string> subComponents;
				string accumulator{ "" };
				int balance = 0;

				for (const auto& ch : S) {
					if (ch == '(')
						balance += 1;
					else if (ch == ')')
						balance -= 1;

					accumulator += ch;

					if (balance == 0) {
						subComponents.emplace_back(accumulator);
						accumulator = "";
					}
				}

				for (auto& component : subComponents) {
					score += scoreOfParentheses(component);
				}
			}
			else {
				score = 2 * scoreOfParentheses(str);
			}
		}

		return score;
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
