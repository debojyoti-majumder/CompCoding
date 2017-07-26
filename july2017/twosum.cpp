// pr1.cpp : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			vector<int> indexes(2);
			size_t sz = numbers.size();
			size_t start_point = sz - 1;

			if (sz == 0)
				return indexes;

			while (start_point != 0) {
				int reminder = target - numbers[start_point];
				auto item = find(numbers.begin(), numbers.end(), reminder);

				// If the item found then the sum is found
				if (item != numbers.end()) {
					// Setting the indexes
					indexes[0] = item - numbers.begin() + 1;
					indexes[1] = start_point + 1;

					return indexes;
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
	cout << endl;

	// Test case 2: Should return 2,5
	rets = s.twoSum(vector<int>{8,9,14,16,21,29}, 30);
	for (auto value : rets)
		cout << value << " ";

	cout << endl;
    return 0;
}

