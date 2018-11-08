// Problem URL: https://leetcode.com/problems/gray-code/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		// These are base cases
		if (n == 0)
			return vector<int>{0};
		else if (n == 1)
			return vector<int>{0, 1};

		auto codes{ grayCode(n - 1) };
		vector<int> retValues;

		// Appending zeros
		for (auto it = codes.cbegin(); it != codes.cend(); ++it) {
			bitset<32> bitrepresentedNumber(*it);
			bitrepresentedNumber.reset(n-1);
			retValues.push_back(bitrepresentedNumber.to_ulong());
		}

		// Appending one but in reverse order
		for (auto it = codes.crbegin(); it != codes.crend(); ++it) {
			bitset<32> bitrepresentedNumber(*it);
			bitrepresentedNumber.set(n-1);
			retValues.push_back(bitrepresentedNumber.to_ulong());
		}

		return retValues;
	}
};

template<typename T>
void printIteratbale(const T& items) {
	for (const auto& ref : items)
		cout << ref << " ";
}

int main() {
	Solution s;
	
	printIteratbale(s.grayCode(3));
	cout << endl;

	return 0;
}
