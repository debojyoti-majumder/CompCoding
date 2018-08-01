// Problem URL: https://leetcode.com/problems/profitable-schemes/description/

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
		return 0;
	}
};

int main() {
	Solution s;

	// Should output 2
	cout << s.profitableSchemes(5, 3, vector<int>{2, 2}, vector<int>{2, 3}) << endl;

	// Should output 7
	cout << s.profitableSchemes(10, 5, vector<int>{2, 3, 5}, vector<int>{6, 7, 8}) << endl;
}
