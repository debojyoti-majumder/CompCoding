#pragma once

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	// Builds a tree from the array
	static TreeNode* buildTree(int* nums, size_t array_size) {
		TreeNode* root(nullptr);

		return root;
	}
};
