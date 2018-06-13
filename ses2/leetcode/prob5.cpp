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
		auto p = listSize % 2 ? listSize / 2 + 1 : listSize / 2;
		for(size_t i=0; i<p; i++){
			auto oddNode = it;
			auto evenNode = it->next;
			
			if( oddNode && evenNode ) {
				if( evenNode->next != nullptr )
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

	auto n1 = new ListNode(1);
	auto n2 = new ListNode(2);
	n1->next = n2;
	n = s.oddEvenList(n1);
	while (n) {
		cout << n->val << endl;
		n = n->next;
	}

	return 0;
}

