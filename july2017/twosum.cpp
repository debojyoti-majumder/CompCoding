// pr1.cpp : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
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
};


int main()
{
	Solution s;
	
	// Test case 1: Should output 1,2 i.e the indexes
	auto rets = s.twoSum(vector<int>{ 2, 7, 11, 15 }, 9);
	for (auto value : rets)
		cout << value << " ";
	cout << endl;

	// Test case 2: Should return 2,5
	rets = s.twoSum(vector<int>{8,9,14,16,21,29}, 30);
	for (auto value : rets)
		cout << value << " ";

	cout << endl;
    return 0;
}

