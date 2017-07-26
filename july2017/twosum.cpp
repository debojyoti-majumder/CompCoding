// pr1.cpp : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			vector<int> indexes(2);
			size_t sz = numbers.size();
			size_t start_point = numbers.size();

			if (sz == 0)
				return indexes;

			for (size_t i = sz; i > 0; i--) {
				if (numbers[i] < target) {
					start_point = i;
					break;
				}
			}

			while (start_point != 0) {
				// Looking for possible pairs
				for (size_t m = start_point - 1; m >= 0; m--) {
					// Checking for the sum and updating the index
					if (numbers[m] + numbers[start_point] == target) {
						indexes[0] = m + 1;
						indexes[1] = start_point;
						return indexes;
					}
				}

				// Going for the next big item
				start_point--;
			}

			return indexes;
		}
};


int main()
{
	Solution s;
	
	// Test case 1: Should output 1,2 i.e the indexes
	auto rets = s.twoSum(vector<int>{ 2, 7, 11, 15 }, 9);
	for (auto value : rets)
		cout << value << " ";
	
	// Test case 2: Should return 2,5
	rets = s.twoSum(vector<int>{8,9,14,16,21,29}, 30);
	for (auto value : rets)
		cout << value << " ";

	cout << endl;
    return 0;
}

