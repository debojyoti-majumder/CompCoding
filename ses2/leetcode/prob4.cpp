// Problem URL: https://leetcode.com/problems/integer-replacement/description/

#include "stdafx.h"
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int integerReplacement(unsigned int n, int stepCount = 0) {
		if (n == 1)    return stepCount;

		if (n % 2 == 0) {
			return integerReplacement(n / 2, stepCount + 1);
		}
		else {
			auto d1 = integerReplacement(n - 1, stepCount + 1);
			auto d2 = integerReplacement(n + 1, stepCount + 1);

			return min(d1, d2);
		}
	}
};

int main() {
	Solution s;
	cout << s.integerReplacement(8) << endl;
	cout << s.integerReplacement(2147483647) << endl;

	return 0;
}

