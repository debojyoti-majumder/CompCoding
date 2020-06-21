// Problem URL: https://leetcode.com/problems/linked-list-components/

#include "pch.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
struct ListNode {
	T val;
	ListNode *next;
	ListNode(T x) : val(x), next(nullptr) {}
};

template <typename T>
ListNode<T>* createSingleList(initializer_list<T> listOfItems) {
	ListNode<T>* head = nullptr, *it = nullptr;

	for (const auto&item : listOfItems) {
		if (head == nullptr) {
			head = new ListNode<T>(item);
			it = head;
			continue;
		}

		it->next = new ListNode<T>(item);
		it = it->next;
	}

	return head;
}

class OldSolution {
public:
	int numComponents(ListNode<int>* head, vector<int>& G) {
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

class Solution {
public:
	int numComponents(ListNode<int>* head, vector<int>& G) {
		auto count = (int)G.size();
		unordered_set<int> hashSet;

		for (const auto& item : G)
			hashSet.insert(item);

		if (head == nullptr)
			return 0;

		for (auto it = head; it->next != nullptr; it=it->next) {
			auto val = hashSet.count(it->val);
			auto nextVal = hashSet.count(it->next->val);

			if (val && nextVal ) count--;
		}

		return count;
	}
};

int testFunction() {
	auto list = createSingleList({ 1,2,0,4,3 });

	OldSolution s;
	vector<int> links{ 3,4,0,2,1 };

	// Should output 1
	cout << s.numComponents(list, links) << "Output\n";
	
	Solution s2;
	cout << "Hast set impl:" << s2.numComponents(list, links);

	// TODO: Memory freeing although not part of my problem
	return 0;
}
