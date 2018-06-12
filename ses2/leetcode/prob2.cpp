// Problem URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* _head;

	void deleteInRange(ListNode* left, ListNode* right) {	
		if (left == nullptr || right == nullptr)
			return;

		auto it = _head;
		bool bStartDeleting = false;

		if (left == _head) {
			_head = right->next;
			return;
		}

		while (it != right->next) {
			if (it->next == left) {
				it->next = right->next;
				bStartDeleting = true;
			}
			else if (bStartDeleting) {
				auto tmp = it;
				it = it->next;
				delete tmp;
				continue;
			}
			
			it = it->next;
		}
		return;
	}

public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;

		_head = head;
		auto iterator = head->next;
		auto prevNode = head;

		ListNode* start = nullptr;
		ListNode* end = nullptr;

		while (iterator) {
			if (prevNode->val == iterator->val) {
				if (start == nullptr) start = prevNode;
				end = iterator;
			}
			else {
				deleteInRange(start, end);
			
				start = nullptr;
				end = nullptr;
			}

			prevNode = iterator;
			iterator = iterator->next;
		}

		deleteInRange(start, end);
		return _head;
	}
};

int main()
{
	auto node0 = new ListNode(1);
	auto node1 = new ListNode(2);
	auto node2 = new ListNode(3);
	auto node3 = new ListNode(3);
	auto node4 = new ListNode(4);
	auto node5 = new ListNode(4);
	auto node6 = new ListNode(5);
	node0->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;


	auto nd0 = new ListNode(1);
	auto nd1 = new ListNode(1);
	auto nd2 = new ListNode(2);
	auto nd3 = new ListNode(3);
	nd0->next = nd1;
	nd1->next = nd2;
	nd2->next = nd3;

	Solution s;

	auto ret = s.deleteDuplicates(node0);
	auto it = ret;
	while (it) {
		cout << it->val << " ";
		it = it->next;
	}
	cout << endl;

	ret = s.deleteDuplicates(nd0);
	it = ret;
	while (it) {
		cout << it->val << " ";
		it = it->next;
	}
	cout << endl;

	auto n1 = new ListNode(1);
	auto n2 = new ListNode(1);
	n1->next = n2;
	ret = s.deleteDuplicates(n1);
	it = ret;
	while (it) {
		cout << it->val << " ";
		it = it->next;
	}
	cout << endl;
	return 0;
}
