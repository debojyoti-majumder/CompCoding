#pragma once

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct MyTreeNode : public TreeNode {
	// Should build the tree form a array
	static TreeNode* buildTreeNode(int* arr, size_t sz) {
		TreeNode* root(nullptr);

		return root;
	}
};
