// LeetCodeWhiteBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Problem URL: https://leetcode.com/problems/redundant-connection/


#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct TreeNode {
	int ndValue;
	struct TreeNode *left;
	struct TreeNode *right;

	explicit TreeNode(int val) : ndValue(val), left(nullptr), right(nullptr) {}

	bool addConnection(TreeNode* nd) {
		if (left == nullptr) {
			left = nd;
			return true;
		}
		else if (right == nullptr) {
			right = nd;
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
		auto node = find_if(_nodes.begin(), _nodes.end(), [&](auto n) {
			return n->ndValue == nodeId;
		});

		// If found retrun the exsisting node
		if (node != _nodes.end())
			return *node;

		// Allocating the node
		auto newNode = new TreeNode(nodeId);
		_nodes.emplace_back(newNode);

		return newNode;
	}

	void makeConnection(TreeNode* node1, TreeNode* node2) {
		if( node1 != nullptr && node2 != nullptr ) {
			node1->addConnection(node2);
			node2->addConnection(node1);
		}
	}

	// Should return the redundent edges
	pair<int,int> performBFS(TreeNode* root) {
		queue<TreeNode*> pendingVisitQueue;
		set<int> nodeIdSet;

		pendingVisitQueue.push(root);

		while (pendingVisitQueue.empty() == false) {
			auto currentNode = pendingVisitQueue.front();
			pendingVisitQueue.pop();

			if (currentNode->left != nullptr)
				pendingVisitQueue.push(currentNode->left);

			if (currentNode->right != nullptr)
				pendingVisitQueue.push(currentNode->right);

			auto count = nodeIdSet.count(currentNode->ndValue);
			if (count != 0) {
				return pair<int, int>{currentNode->ndValue, -1};
			}

			nodeIdSet.insert(currentNode->ndValue);
		}

		return pair<int, int> {-1, -1};
	}

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> redundentEdge{-1,1};		

		// Going through each edge and building the tree
		for (const auto& edge : edges) {
			if (edge.size() != 2)
				return vector<int>{-1, -1};

			auto nd1 = findOrAddNodes(edge[0]);
			auto nd2 = findOrAddNodes(edge[1]);

			// This is unidirecrional connection
			makeConnection(nd1, nd2);
		}

		// Handling zero input cases
		if (_nodes.size() == 0)
			return redundentEdge;

		// Can choose any arbitary node
		performBFS(_nodes[0]);

		return redundentEdge;
	}

	~Solution() {
		for (auto ptr : _nodes)
			delete ptr;
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
