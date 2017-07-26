// pr1.cpp : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			vector<int> indexes(2);

			return indexes;
		}
};


int main()
{
	Solution s;
	auto rets = s.twoSum(vector<int>{ 2, 7, 11, 15 }, 9);

	// Should output 1,2 i.e the indexes
	for (auto value : rets)
		cout << value << " ";
		
	cout << endl;
    return 0;
}

