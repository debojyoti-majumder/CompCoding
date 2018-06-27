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
	int getMultiple(int num,int x) {
		if (x == 1) {
			return num;
		}

		for (int i = 2; i < x; i++) {
			if (x * i == num) {
				return i;
			}
		}

		return 0;
	}

public:
	int numSquares(int n) {
		// Handling base case
		int sq = (int)sqrt(n);
		if (sq * sq == n)
			return 1;

		// Memorization
		auto cacheLookup = _cache.find(n);
		if (cacheLookup != _cache.end()) {
			return cacheLookup->second;
		}

		vector<int> distanceValues;
		for (int count = 1; count * count < n; count++) {
			int x = count * count;
			int v = 0;
			int mul = getMultiple(n, x);
			
			if (mul == 0)
				v = 1 + numSquares(n - x);
			else
				v = mul;

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
	
	// Fixed 55
	cout << "Test case 3:" << s.numSquares(55) << endl;

	// Fixed TLE 6554
	cout << "Test case 4:" << s.numSquares(6554) << endl;

	// TLE with 7691
	cout << "Test case 5:" << s.numSquares(7691) << endl;

	return 0;
}
