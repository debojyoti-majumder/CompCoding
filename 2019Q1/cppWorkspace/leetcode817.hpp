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
		auto listComponent{ G };
		auto it = head;
		int componentCount = 0;

		while (it != nullptr) {
			auto val = it->val;

			if (it->next != nullptr) {
				auto nextVal = it->next->val;

				auto element1 = find(listComponent.begin(), listComponent.end(), val);
				auto element2 = find(listComponent.begin(), listComponent.end(), nextVal);

				// If both the element is found then we have got a component
				if (element1 != listComponent.end() && element2 != listComponent.end()) {
					// Adding to the component count
					componentCount++;

					// Erasing those two elements
					listComponent[element1 - listComponent.begin()] = -1;
					listComponent[element2 - listComponent.begin()] = -1;
					
					// This should double icrement
					it = it->next;
				}
			}

			it = it->next;
		}

		auto deletedCount = count_if(listComponent.begin(), listComponent.end(), [](int item) {
			return item == -1;
		});

		if (deletedCount == listComponent.size() - 1)	componentCount++;

		return componentCount;
	}
};

int main() {
	ListNode* head = new ListNode(0);
	auto it = head;

	for (int i = 1; i <= 4; i++) {
		it->next = new ListNode(i);
		it = it->next;
	}

	Solution s;
	vector<int> links{ 0,3,1,4 };

	// Should output 2
	cout << s.numComponents(head, links) << endl;
	
	// TODO: Memory freeing although not part of my problem
	return 0;
}
