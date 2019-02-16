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
	struct TreeNode* parent;
	struct TreeNode* left;
	struct TreeNode* right;

	explicit TreeNode(int val) : ndValue(val), left(nullptr), right(nullptr), parent(nullptr) {}

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

	inline void makeParent(struct TreeNode* nd) {
		parent = nd;
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

			node2->makeParent(node1);
		}
	}

	// Should return the redundent edges
	bool detectLoop(TreeNode* root) {
		queue<TreeNode*> pendingVisitQueue;
		set<int> nodeIdSet;

		pendingVisitQueue.push(root);

		while (pendingVisitQueue.empty() == false) {
			auto currentNode = pendingVisitQueue.front();
			pendingVisitQueue.pop();

			auto leftNode = currentNode->left;
			auto rightNode = currentNode->right;

			if ( leftNode != nullptr && leftNode != currentNode->parent ) {
				pendingVisitQueue.push(leftNode);
			}

			if ( rightNode != nullptr && rightNode != currentNode->parent ) {
				pendingVisitQueue.push(rightNode);
			}

			auto count = nodeIdSet.count(currentNode->ndValue);
			if (count != 0) {
				return true;
			}

			nodeIdSet.insert(currentNode->ndValue);
		}

		return false;
	}

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		_nodes.clear();

		// Going through each edge and building the tree
		for (const auto& edge : edges) {
			if (edge.size() != 2)
				return vector<int>{-1, -1};

			auto nd1 = findOrAddNodes(edge[0]);
			auto nd2 = findOrAddNodes(edge[1]);

			// This is unidirecrional connection
			makeConnection(nd1, nd2);
			
			auto isLoopPresent = detectLoop(nd1);
			if (isLoopPresent) return edge;
		}

		return vector<int>{-1, -1};
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

	vector<vector<int>> input2 = {
			{1, 2}, { 2, 3}, { 3, 4}, { 1, 4}, { 1, 5 }
	};
	
	vector<vector<int>> input3{ {1,3},{3,4},{1,5},{3,5},{2,3} };

	Solution sol;
	auto ret = sol.findRedundantConnection(input1);
	cout << ret[0] << ", " << ret[1] << "\n";

	ret = sol.findRedundantConnection(input2);
	cout << ret[0] << ", " << ret[1] << "\n";

	// Should output 3,5, test case failing
	ret = sol.findRedundantConnection(input3);
	cout << ret[0] << ", " << ret[1] << "\n";

	return 0;
}
