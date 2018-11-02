// Problem URL: https://leetcode.com/problems/gray-code/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		if (n == 0)
			return vector<int>{0};
		else if (n == 1)
			return vector<int>{1, 0};

		auto codes{ grayCode(n - 1) };
		vector<int> retValues;

		return retValues;
	}
};

template<typename T>
void printIteratbale(T items) {
	for (const auto& ref : items)
		cout << ref << " ";
}

int main() {
	Solution s;
	
	printIteratbale(s.grayCode(3));
	cout << endl;

	return 0;
}
