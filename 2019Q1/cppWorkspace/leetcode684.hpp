// LeetCodeWhiteBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Problem URL: https://leetcode.com/problems/redundant-connection/


#include "pch.h"

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int ndValue;
	struct TreeNode *left;
	struct TreeNode *right;

	explicit TreeNode(int val) : ndValue(val), left(nullptr), right(nullptr) {}

	bool addConnection(TreeNode* nd) {
		if (nd->left == nullptr) {
			nd->left = nd;
			return true;
		}
		else if (nd->right == nullptr) {
			nd->right = nd;
			return true;
		}
		else
			return false;
	}
};

class Solution {
private:
	vector<TreeNode*> _nodes;
	
	TreeNode* findOrAddNodes(int nodeId) {
		return nullptr;
	}

	void makeConnection(TreeNode* node1, TreeNode* node2) {
		if( node1 != nullptr && node2 != nullptr ) {
			node1->addConnection(node2);
			node2->addConnection(node1);
		}
	}

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> redundentEdge{-1,1};
		

		for (const auto& edge : edges) {
			if (edge.size() != 2)
				return vector<int>{-1, -1};

			auto nd1 = findOrAddNodes(edge[0]);
			auto nd2 = findOrAddNodes(edge[1]);
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
