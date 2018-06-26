// Problem URL: https://leetcode.com/problems/perfect-squares/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	int numSquares(int n) {
		// Handling base case
		int sq = sqrt(n);
		if (sq * sq == n)
			return 1;

		vector<int> distanceValues;
		for (int count = 1; count * count < n; count++) {
			int x = count * count;
			int v = 1 + numSquares(n - x);

			distanceValues.push_back(v);
		}

		if( distanceValues.empty() )
			return 0;
		else {
			auto it = min_element(distanceValues.begin(), distanceValues.end());
			return *it;
		}
	}
};

int main() {
	Solution s;

	// 12 = 4 + 4 + 4
	cout << "Test case 1:" << s.numSquares(12) << endl;

	// 13 = 4 + 9
	cout << "Test case 2:" << s.numSquares(13) << endl;
	
	// Time limit 55
	cout << "Test case 3:" << s.numSquares(55) << endl;

	return 0;
}
