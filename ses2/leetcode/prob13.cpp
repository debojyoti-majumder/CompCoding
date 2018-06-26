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
	map<int, int> _cache;

public:
	int numSquares(int n) {
		// Handling base case
		int sq = (int)sqrt(n);
		if (sq * sq == n)
			return 1;

		auto cacheLookup = _cache.find(n);
		if (cacheLookup != _cache.end()) {
			return cacheLookup->second;
		}

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
			_cache.insert(make_pair(n, *it));
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

	// Time limit with 6554
	cout << "Test case 4:" << s.numSquares(6554) << endl;

	return 0;
}
