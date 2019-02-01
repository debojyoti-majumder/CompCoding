// Problem URL: https://leetcode.com/problems/linked-list-components/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		auto listComponent{ G };		// Simple copy wan't keep the function parameter as it is
		auto it = head;
		int componentCount = 0;

		while (it != nullptr) {
			auto val = it->val;
			auto firstElement = find(listComponent.begin(), listComponent.end(), val);

			if (firstElement != listComponent.end()) {
				componentCount++;
				listComponent.erase(firstElement);

				if (it->next != nullptr) {
					auto nextVal = it->next->val;
					auto secondElement = find(listComponent.begin(), listComponent.end(), nextVal);

					// We have got a pair hence treated as one component
					if (secondElement != listComponent.end()) {
						listComponent.erase(secondElement);
						it = it->next;
					}
				}
			}

			it = it->next;
		}

		return componentCount;
	}
};

int main() {
	ListNode* head = new ListNode(0);
	auto it = head;

	for (int i = 1; i <= 10; i++) {
		it->next = new ListNode(i);
		it = it->next;
	}

	Solution s;
	vector<int> links{ 0,3,1,10 };

	// Should output 2
	cout << s.numComponents(head, links) << endl;
	
	// TODO: Memory freeing although not part of my problem
	return 0;
}
