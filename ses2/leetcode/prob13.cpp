// Problem URL: https://leetcode.com/problems/perfect-squares/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Solution {
private:
	bool isPerfectSqrt(int num) {
		int p = (int) sqrt(num);
		if (p * p == num)
			return true;
		else
			return false;
	}
public:
	int numSquares(int number) {
		vector<int> addedNumbers(number, 0);
		if (number < 4)
			return number;

		addedNumbers[0] = 1;
		addedNumbers[1] = 2;
		addedNumbers[2] = 3;
		addedNumbers[3] = 1;
		int ps = 4;
		for (size_t i = 4; i < addedNumbers.size(); i++) {
			int v = i + 1;
			
			if (isPerfectSqrt(v)) {
				addedNumbers[v - 1] = 1;
				ps = v;
			}
			else {
				vector<int> values;
				for (int i = 1; i <= min(v/2,700); i++) {
					int x = i;
					int y = v - i;

					values.push_back(addedNumbers[x - 1] + addedNumbers[y - 1]);
				}

				addedNumbers[i] = *min_element(values.begin(), values.end());
			}
		}

		return addedNumbers[number - 1];
	}
};

int main() {
	Solution s;

	// 12 = 4 + 4 + 4
	cout << "Test case 1:" << s.numSquares(12) << endl;

	// 13 = 4 + 9
	cout << "Test case 2:" << s.numSquares(13) << endl;
	
	// Fixed 55 Should output 4
	cout << "Test case 3:" << s.numSquares(55) << endl;

	// Fixed TLE 6554 Output 2
	cout << "Test case 4:" << s.numSquares(6554) << endl;

	// TLE with 7691 Output 3
	cout << "Test case 5:" << s.numSquares(7691) << endl;

	return 0;
}
