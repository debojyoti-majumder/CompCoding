#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>


// Problem URL: https://leetcode.com/problems/sum-of-left-leaves/description/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
    
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
	//cout << s.widthOfBinaryTree(tree1) << endl;

	TreeNode* tree2 = new TreeNode(10);
	tree2->left = new TreeNode(20);
	tree2->left->left = new TreeNode(30);
	tree2->left->left->left = new TreeNode(40);

	tree2->right = new TreeNode(50);
	tree2->right->right = new TreeNode(60);
	tree2->right->right->right = new TreeNode(70);

	// Should output 8
	// cout << s.widthOfBinaryTree(tree2) << endl;
	return 0;
}
