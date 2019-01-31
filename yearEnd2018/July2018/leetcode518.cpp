// Problem URL: https://leetcode.com/problems/find-bottom-left-tree-value/description/

#include "stdafx.h"
#include <iostream>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	struct MaxDepthNode {
		int depth;
		TreeNode* node;
	}_resNode;

	void perfromPreOrder(TreeNode* root, int depth = 0) {
		auto newDepth = depth + 1;
		
		if( root != nullptr ) {
			// This is where the node gets processed
			if (depth > _resNode.depth) {
				_resNode.depth = depth;
				_resNode.node = root;
			}

			// Recusrive call for tree traversal
			perfromPreOrder(root->left, newDepth);
			perfromPreOrder(root->right, newDepth);
		}
	}

public:
	int findBottomLeftValue(TreeNode* root) {
		if (root == nullptr)
			return 0;

		_resNode.depth = 0;
		_resNode.node = root;

		perfromPreOrder(root);

		return _resNode.node->val;
	}
};


int main() {
	Solution s;
	
	TreeNode* root = new TreeNode(1);
	TreeNode* l1 = new TreeNode(2);
	TreeNode* r1 = new TreeNode(3);

	root->left = l1;
	root->right = r1;

	cout << s.findBottomLeftValue(root) << endl;

	return 0;
}
