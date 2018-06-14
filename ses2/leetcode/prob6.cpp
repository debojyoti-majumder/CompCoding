// Problem URL: https://leetcode.com/problems/find-k-closest-elements/description/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> retItems;
		vector<int> possiblities;
		auto findCount = 0;
		auto bOriginalItemFound = false;

		for (int i = k - x; i <= x + k; i++) {
			possiblities.push_back(i);
		}

		for (auto it = arr.begin(); it != arr.end(); ++it) {
			if (x == *it)	bOriginalItemFound = true;
			auto fItem = find(possiblities.begin(), possiblities.end(), *it);

			if (fItem != possiblities.end()) {
				retItems.push_back(*fItem);
			}
		}

		if (!bOriginalItemFound) {
			vector<int> firstKItems(arr.begin(), arr.begin() + k);
			return firstKItems;
		}
		else {
			auto it = find(retItems.begin(), retItems.end(), x);
			vector<int> finalItems(retItems.begin(), it+1);
			auto itemsOnRight = k - finalItems.size();
			
			if (itemsOnRight > 0) {
				vector<int> rt(it + 1, it + 1 + itemsOnRight);
				finalItems.insert(finalItems.end(), rt.begin(), rt.end());
			}

			return finalItems;
		}
	}
};

int main() {
	vector<int> nums{ 1, 2, 3, 4, 5};
	Solution s;
	auto ret = s.findClosestElements(nums, 3, 2);
	
	for (auto i : ret) {
		cout << i << " ";
	}
	cout << endl;

	// Should output [1,2,3,4]
	ret = s.findClosestElements(nums, 4, -1);
	for (auto i : ret) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

