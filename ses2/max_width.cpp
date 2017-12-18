// ConsoleApplication4.cpp : Finds the maximum depth of the tree
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

// Problem URL:https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	map<int, vector<int>> _depToPosVector;
	bool isLeafNode(TreeNode* nd) const {
		if (nd->left == nullptr && nd->right == nullptr)
			return true;
		else
			return false;
	}

	void updateMapInfo(int d, int pos) {
		auto it = _depToPosVector.find(d);

		if (it == _depToPosVector.end()) {
			_depToPosVector.insert(make_pair(d, vector<int>({ pos })));
		}
		else
			it->second.push_back(pos);
	}

	void treeTraversor(TreeNode* nd, int depth, int pos) {
		if (nd != nullptr) {
			updateMapInfo(depth, pos);
			treeTraversor(nd->left, depth + 1, 2 * pos);
			treeTraversor(nd->right, depth + 1, 2 * pos + 1);
		}
	}

public:
	int widthOfBinaryTree(TreeNode* root) {
		// This method should build depth map
		treeTraversor(root, 0, 0);
		vector<int> depthValues;

		for (auto it = _depToPosVector.begin(); it != _depToPosVector.end(); it++) {
			auto v = it->second;

			auto max_it = max_element(v.begin(), v.end());
			auto min_it = min_element(v.begin(), v.end());

			depthValues.push_back((*max_it - *min_it) + 1);
		}

		auto ret_it = max_element(depthValues.begin(), depthValues.end());
		return *ret_it;
	}
};

int main()
{
	TreeNode* tree1 = new TreeNode(1);

	Solution s;

	tree1->left = new TreeNode(2);
	tree1->left->left = new TreeNode(4);
	tree1->left->right = new TreeNode(5);

	tree1->right = new TreeNode(3);
	//tree1->right->left = new TreeNode(6);
	//tree1->right->right = new TreeNode(7);

	// Should output 2 
	cout << s.widthOfBinaryTree(tree1) << endl;

	TreeNode* tree2 = new TreeNode(10);
	tree2->left = new TreeNode(20);
	tree2->left->left = new TreeNode(30);
	tree2->left->left->left = new TreeNode(40);
	
	tree2->right = new TreeNode(50);
	tree2->right->right = new TreeNode(60);
	tree2->right->right->right = new TreeNode(70);

	// Should output 8
	cout << s.widthOfBinaryTree(tree2) << endl;
	return 0;
}

