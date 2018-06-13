// Problem URL: https://leetcode.com/problems/odd-even-linked-list/description/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		auto lastNode = head;
		auto firstNode = head;
		auto it = head;
		auto listSize = 0;
		ListNode* stopNode = nullptr;

		if (head == nullptr)	return nullptr;

		while (lastNode->next) {
			lastNode = lastNode->next;
			listSize++;
		}

		// For odd size lists
		if( listSize % 2 )
			stopNode = lastNode;
		else {
			for (size_t i = 0; i < listSize - 1; i++) {
				stopNode = stopNode->next;
			}
		}

		while ( it && it != stopNode) {
			auto oddNode = it;
			auto evenNode = it->next;
			
			if( oddNode && evenNode ) {
				oddNode->next = evenNode->next;
			
				// Adding the even node at last
				lastNode->next = evenNode;
			
				// Updating the last node
				lastNode = evenNode;
				lastNode->next = nullptr;
			}
			
			it = it->next;
		}

		return head;
	}
};

int main() {
	auto nd1 = new ListNode(1);
	auto nd2 = new ListNode(2);
	auto nd3 = new ListNode(3);
	auto nd4 = new ListNode(4);
	auto nd5 = new ListNode(5);
	auto nd6 = new ListNode(6);

	nd1->next = nd2;
	nd2->next = nd3;
	nd3->next = nd4;
	nd4->next = nd5;
	nd5->next = nd6;

	Solution s;
	auto n = s.oddEvenList(nd1);

	while (n) {
		cout << n->val << endl;
		n = n->next;
	}
	return 0;
}

