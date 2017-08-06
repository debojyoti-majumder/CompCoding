// tree_with_sorted.cpp.cpp : Defines the entry point for the console application.
// Leecode url: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void print_tree_preorder(TreeNode * node) {
	if (node != nullptr) {
		cout << node->val << " ";
		print_tree_preorder(node->left);
		print_tree_preorder(node->right);
	}
}

class Solution {
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			// Base case
			if (nums.size() == 0)
				return nullptr;

			auto mid_index = nums.size() / 2;
			auto node = new TreeNode(nums[mid_index]);

			// Subsetting the array items
			vector<int> left_subtree(nums.begin(), nums.begin() + mid_index);
			vector<int> right_subtree(nums.begin() + mid_index + 1, nums.end());

			// Calling the rescursive calls to build the tree
			node->left = sortedArrayToBST(left_subtree);
			node->right = sortedArrayToBST(right_subtree);

			return node;
		}
};
int main()
{
	vector<int> n{ 2,4,6,7,8,9,78,100 };
	Solution s;

	auto root = s.sortedArrayToBST(n);
	print_tree_preorder(root);

    return 0;
}

