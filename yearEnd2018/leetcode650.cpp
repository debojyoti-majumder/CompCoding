// Problem URL: https://leetcode.com/problems/2-keys-keyboard/

#include "stdafx.h"

#include <iostream>

using namespace std;

class Solution {
public:
	int minSteps(int n) {
		if (n <= 1)
			return 0;

		if (n == 2)
			return 2;

		int subInt;
		if (n % 2 == 0) {
			subInt = n / 2;
			return minSteps(subInt) + 2;
		}
		else {
			subInt = n - 1;
			return minSteps(subInt) + 1;
		}

		return 0;
	}
};

int main() {
	Solution s;

	cout << s.minSteps(3) << endl;	// Should output 3
	cout << s.minSteps(9) << endl;	// Should output 6

	return 0;
}
