// sym_present.cpp : Defines the entry point for the console application.
// Problem description: 

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

class Solution {	
	private:
		vector<int> _treeArray;
		
		void buildInOrder(TreeNode* node) {
			if( node != nullptr ) {
				buildInOrder(node->left);
				_treeArray.push_back(node->val);
				buildInOrder(node->right);
			}
		}

		bool isNumberPresent(int target) {
			if (_treeArray.size() == 1)
				return false;

			auto high_index = _treeArray.size() - 1;
			auto low_index = 0;

			while (_treeArray[high_index] + _treeArray[low_index] != target) {
				if (_treeArray[high_index] + _treeArray[low_index] > target)
					high_index--;
				else
					low_index++;

				if (high_index == low_index)
					return false;
			}

			return true;
		}
	public:
		bool findTarget(TreeNode* root, int k) {
			// Removes all the items
			_treeArray.clear();

			// Builds a sorted array
			buildInOrder(root);

			// Calls the helper function to get the result
			return isNumberPresent(k);
		}
};

int main()
{
	TreeNode* nd_root = new TreeNode(5);

	TreeNode* nd_lev1_1 = new TreeNode(3);
	TreeNode* nd_lev1_2 = new TreeNode(6);

	TreeNode* nd_lev2_1 = new TreeNode(2);
	TreeNode* nd_lev2_2 = new TreeNode(4);

	//TreeNode* nd_lev2_3 = new TreeNode(4);
	TreeNode* nd_lev2_4 = new TreeNode(7);

	nd_lev1_1->left = nd_lev2_1;
	nd_lev1_1->right = nd_lev2_2;

	//nd_lev1_2->left = nd_lev2_3;
	nd_lev1_2->right = nd_lev2_4;

	nd_root->left = nd_lev1_1;
	nd_root->right = nd_lev1_2;

	Solution s;

	s.findTarget(nd_root, 28);
	return 0;
}

