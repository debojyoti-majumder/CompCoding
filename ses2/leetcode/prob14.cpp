// Problem URL: https://leetcode.com/problems/subsets-ii/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <map>
#include <bitset>

using namespace std;
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set<vector<int>> returnedSet;
		size_t sz = nums.size();
		size_t numberOfItems = (size_t) pow(2, sz);
				
		for (size_t i = 0; i < numberOfItems; i++) {
			bitset<32> binaryRep(i);
			vector<int> item;

			for (size_t i = 0; i < sz; i++) {
				if (binaryRep.test(i))
					item.push_back(nums[i]);
			}

			returnedSet.insert(item);
		}

		vector<vector<int>> returnedItems;
		for (auto item : returnedSet)
			returnedItems.push_back(item);

		return returnedItems;
	}
};

template<typename T>
void printVector(vector<T> items) {
	for (auto item : items) {
		cout << item << " ";
	}

	cout << endl;
}

int main() {
	//Input: [1, 2, 2]
	//	Output :
	//	[
	//		[2],
	//		[1],
	//		[1, 2, 2],
	//		[2, 2],
	//		[1, 2],
	//		[]
	//	]

	Solution s;
	vector<int> inp{ 1,2,2 };
	vector<int> inp2{ 4, 4, 4, 1, 4 };

	auto vals(s.subsetsWithDup(inp));

	for (auto v : vals) {
		printVector(v);
	}

	auto vals2(s.subsetsWithDup(inp2));

	for (auto v : vals2) {
		printVector(v);
	}
	return 0;
}
