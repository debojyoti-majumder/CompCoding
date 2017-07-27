// pr1.cpp : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
// Solves this also https://leetcode.com/problems/two-sum/#/description

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<int> twoSumSorted(vector<int>& numbers, int target) {
			auto high_index = numbers.size() - 1;
			auto low_index = 0;

			while (numbers[high_index] + numbers[low_index] != target) {
				if (numbers[high_index] + numbers[low_index] > target)
					high_index--;
				else
					low_index++;
			}

			return vector<int>{low_index + 1, (int)(high_index + 1)};
		}

		// Yet to be implemented
		vector<int> twoSum(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			return twoSumSorted(nums, target);
		}
};


int main()
{
	Solution s;
	
	// Test case 1: Should output 1,2 i.e the indexes
	auto rets = s.twoSum(vector<int>{ 2, 11, 15, 7}, 9);
	for (auto value : rets)
		cout << value << " ";
	cout << endl;

	// Test case 2: Should return 2,5
	rets = s.twoSum(vector<int>{8,9,14,21,29,16}, 30);
	for (auto value : rets)
		cout << value << " ";

	cout << endl;
    return 0;
}

