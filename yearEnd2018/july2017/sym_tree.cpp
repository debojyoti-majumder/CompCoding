// sym_tree.cpp : Defines the entry point for the console application.
// Problem description: https://leetcode.com/problems/symmetric-tree/description/

#include "stdafx.h"
#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
	private:
		bool is_mirror(TreeNode* node_1, TreeNode* node_2) {
			// Base case
			if (node_1 == nullptr && node_2 == nullptr)
				return true;

			if (node_1 != nullptr && node_2 != nullptr &&
				node_1->val == node_2->val) {
				bool ret_1 = is_mirror(node_1-> left, node_2->right);
				bool ret_2 = is_mirror(node_1->right, node_2->left);

				return ret_1 && ret_2;
			}

			return false;
		}

	public:
		bool isSymmetric(TreeNode* root) {
			return is_mirror(root, root);
		}
};

int main()
{
	TreeNode* nd_root = new TreeNode(1);
	
	TreeNode* nd_lev1_1 = new TreeNode(2);
	TreeNode* nd_lev1_2 = new TreeNode(2);

	TreeNode* nd_lev2_1 = new TreeNode(3);
	TreeNode* nd_lev2_2 = new TreeNode(4);

	TreeNode* nd_lev2_3 = new TreeNode(4);
	TreeNode* nd_lev2_4 = new TreeNode(3);

	//nd_lev1_1->left = nd_lev2_1;

	nd_lev1_1->right = nd_lev2_2;

	nd_lev1_2->left = nd_lev2_3;
	nd_lev1_2->right = nd_lev2_4;

	nd_root->left = nd_lev1_1;
	nd_root->right = nd_lev1_2;

	Solution s;
	
	cout << s.isSymmetric(nd_root) << endl;

	return 0;
}

