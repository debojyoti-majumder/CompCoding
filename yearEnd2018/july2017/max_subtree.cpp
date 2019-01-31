// max_subtree.cpp : Defines the entry point for the console application.
// Leetcode problem ID: 654 Solution accepted

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

void printTree(TreeNode* node) {
	if (node != nullptr) {
		printTree(node->left);
		cout << node->val;
		printTree(node->right);
	}
}

class Solution {
	private:
		// Should retrun the index
		int findMax(vector<int>& numbers) {
			if (numbers.size() == 1)
				return 0;

			int max = numbers[0];
			int ret_index = 0;

			for (size_t index = 1; index < numbers.size(); index++) {
				if (numbers[index] > max) {
					max = numbers[index];
					ret_index = index;
				}
			}

			return ret_index;
		}
	public:
		TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
			// Tacking base case
			if (nums.size() == 0)
				return nullptr;
			
			// Getting the max item
			int max_index = findMax(nums);

			TreeNode* node = new TreeNode(nums[max_index]);
			std::vector<int> leftVector(nums.begin(), nums.begin() + max_index);
			std::vector<int> rightVector(nums.begin() + max_index + 1, nums.end());

			node->left = constructMaximumBinaryTree(leftVector);
			node->right = constructMaximumBinaryTree(rightVector);

			return node;
		}
};

int main()
{
	vector<int> inp{3,2,1,6,0,5};
	Solution s;

	auto tree = s.constructMaximumBinaryTree(inp);
	printTree(tree);

    return 0;
}

