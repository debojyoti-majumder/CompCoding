// Problem URL: https://leetcode.com/problems/linked-list-components/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		return 0;
	}
};

void testSolution() {
	ListNode* head = new ListNode(0);
	auto it = head;

	for (int i = 1; i < 4; i++) {
		it->next = new ListNode(i);
		it = it->next;
	}

	Solution s;
	vector<int> links{ 0,3,1,4 };

	cout << s.numComponents(head, links) << endl;
}
