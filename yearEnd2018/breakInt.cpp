// Problem url: https://leetcode.com/problems/integer-break/description/

#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class BreakInteger {
private:
	// DP memorization table
	unordered_map<int, int>	_computeCache;

	// Helper function to get max item from an array
	int getMax(const vector<int>& items) {
		auto it = items.begin();
		auto max = *it;

		while (it != items.end()) {
			if (*it > max)
				max = *it;
			it++;
		}

		return max;
	}

public:
	BreakInteger() {
		// Adding code for base case
		_computeCache.insert({ 2,1 });
	}

	int integerBreak(int n) {
		int retValue(n);
		auto cached_item = _computeCache.find(n);

		if (cached_item == _computeCache.end()) {
			vector<int> results;
			for (auto i = 1; i <= n / 2; i++) {
				auto item_1 = i;
				auto item_2 = integerBreak(n - item_1);
				auto item_3 = item_1 * (n - item_1);

				results.push_back(item_2 * item_1);
				results.push_back(item_3);
			}

			retValue = getMax(results);
			_computeCache.insert({ n,retValue });
		}
		else {
			retValue = cached_item->second;
		}

		return retValue;
	}
};


void testBreakInt() {
	BreakInteger s;

	cout << s.integerBreak(3) << endl;		// Should return 1 
	cout << s.integerBreak(5) << endl;		// Should retrun 6
	cout << s.integerBreak(10) << endl;		// Should return 36
}
