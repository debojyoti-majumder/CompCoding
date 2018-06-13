// Problem URL: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
	TreeNode* buildTreeFromVector(const vector<int>& items) {
		auto sz = items.size();
		auto midIndex = sz / 2;

		if (sz == 0)
			return nullptr;

		TreeNode* nd = new TreeNode(items[midIndex]);

		if (sz != 1) {
			vector<int> leftTree(items.begin(), items.begin() + midIndex);
			vector<int> rightTree(items.begin() + midIndex + 1, items.end());

			nd->left = buildTreeFromVector(leftTree);
			nd->right = buildTreeFromVector(rightTree);
		}

		return nd;
	}

public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> sortedVector;
		auto it = head;

		while (it) {
			sortedVector.push_back(it->val);
			it = it->next;
		}

		return buildTreeFromVector(sortedVector);
	}
};

int main()
{
	ListNode* nd1 = new ListNode(-10);
	ListNode* nd2 = new ListNode(-3);
	ListNode* nd3 = new ListNode(0);
	ListNode* nd4 = new ListNode(5);
	ListNode* nd5 = new ListNode(9);
	nd1->next = nd2;
	nd2->next = nd3;
	nd3->next = nd4;
	nd4->next = nd5;

	Solution s;
	auto tree = s.sortedListToBST(nd1);

	return 0;
}

