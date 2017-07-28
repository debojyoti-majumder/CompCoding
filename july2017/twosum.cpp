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

		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> original(nums);

			// Getting the result from the sorted item
			sort(nums.begin(), nums.end());
			auto indexes = twoSumSorted(nums, target);

			auto value_1 = nums[indexes[0] - 1];
			auto value_2 = nums[indexes[1] - 1];

			vector<int> ret_values(2);

			for (size_t index = 0; index < original.size(); index++) {
				if (original[index] == value_1)
					ret_values[0] = index + 1;

				if (original[index] == value_2)
					ret_values[1] = index + 1;
			}

			return ret_values;
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

