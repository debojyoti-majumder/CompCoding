// Sess1.cpp: Defines the entry point for the console application.
// House robber: https://leetcode.com/problems/house-robber/description/

// TODO Problem: https://github.com/jtfell/c-fft/blob/master/fft.c Transfer this to C++ and then to CUDA
// TODO Problem: Do that with alsa audio maybe with streaming audio

#include "stdafx.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct House {
	unsigned int houseNumber;
	int money;

	// This is to make the sorting in decending order
	friend bool operator<(const House& h1, const House& h2) {
		return h1.money > h2.money;
	}
};

class Solution {
private:
	bool isNearBy(const House& h1, const House& h2) {
		if (h1.houseNumber + 1 == h2.houseNumber || 
			h2.houseNumber + 1 == h1.houseNumber )
			return true;

		return false;
	}

	int rob(vector<House> items) {
		auto lastItem = items[0];
		int sum = lastItem.money;

		for (size_t i = 1; i < items.size() - 1; i++) {
			if (isNearBy(lastItem, items[i]) == false) {
				lastItem = items[i];
				sum += lastItem.money;
			}
		}

		return sum;
	}

public:
	int rob(vector<int>& nums) {
		// Base case
		if (nums.size() == 0)
			return 0;

		// Building the house array
		vector<House> houses;
		for (unsigned int i = 0; i < (unsigned int) nums.size(); i++) {
			House h;
			
			h.houseNumber = i;
			h.money = nums[i];

			houses.push_back(h);
		}

		// Sorting them to get the most value
		sort(houses.begin(), houses.end());

		return rob(houses);
	}
};

int main() {
	vector<int> input{ 23, 6, 5, 89, 33, 45 };

	// Should output 157
	Solution s;
	auto val = s.rob(input);
	cout << "Test case 1: " << val << endl;

	// Should output 249
	vector<int> case2{ 34,5,78,9,13,44,62,93 };
	val = s.rob(case2);
	cout << "Test case 2: " << val << endl;

	return 0;
}
