// LeetCodeWhiteBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Problem URL: https://leetcode.com/problems/redundant-connection/


#include "pch.h"

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct NodeState {
	int ndValue;
	bool isVisited;

	explicit NodeState(int val) : ndValue(val), isVisited(false) {}
};

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> redundentEdge{-1,1};
		set<NodeState> nodes;

		for (const auto& edge : edges) {
			if (edge.size() != 2)
				return vector<int>{-1, -1};

			NodeState firstNode{ edge[0] };
			NodeState secondNode{ edge[1] };
		}

		return redundentEdge;
	}
};

int main() {
	vector<vector<int>> input1 = {
		{1,2}, {1,3}, {2,3}
	};

	Solution sol;
	auto ret = sol.findRedundantConnection(input1);

	if (ret.size() != 2)
		return -1;

	cout << ret[0] << ", " << ret[1] << "\n";
	return 0;
}
