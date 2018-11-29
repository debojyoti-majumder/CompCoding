// Problem URL: https://leetcode.com/problems/hand-of-straights/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	void addItemToSubArray(vector<int>& sub, int i) {
		if (sub.empty()) {
			sub.emplace_back(i);
			return;
		}

		auto it = upper_bound(sub.begin(), sub.end(), i);
		sub.insert(it, i);
	}

public:
	bool isNStraightHand(vector<int>& hand, int W) {
		auto sz = hand.size();
		auto numOfBlocks(sz / W);
		vector<vector<int>> handArrangment(W);
		
		while (hand.empty() == false) {
			auto item = hand.back();
			hand.pop_back();
		}

		return true;
	}
};

int main() {
	vector<int> input1{ 1,2,3,6,2,3,4,7,8 };
	vector<int> input2{ 1,2,3,4,5 };
	Solution s;

	cout << s.isNStraightHand(input1, 3) << endl;	// Should return true
	cout << s.isNStraightHand(input2, 4) << endl;	// Should return false

	return 0;
}
