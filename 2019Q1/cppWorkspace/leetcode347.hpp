// Probelm URL: https://leetcode.com/problems/top-k-frequent-elements/
// Leetcode id: 347
// Issue ID: 14

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct HeapNode {
	int item;
	int itemCount;

	HeapNode* left;
	HeapNode* right;

	HeapNode(int val) : item(val), itemCount(0), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	vector<HeapNode*> heapNodes;

	vector<int> getVectorFromHeap() {
		vector<int> items;
		for (const auto& nd : heapNodes)
			items.emplace_back(nd->item);

		return items;
	}

	void addElementtoHeap(HeapNode* node, int val) {
		if (node == nullptr)
			return;

		// Uninitilized node
		if (node->item == 0 && node->itemCount == 0) {
			node->item = val;
			node->itemCount = 1;
			return;
		}

		// If the same value increment count
		if (node->item == val) {
			node->itemCount += 1;
			return;
		}

		if (val < node->item)
			addElementtoHeap(node->left, val);
		else
			addElementtoHeap(node->right, val);
	}

public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		
		for (auto i = 0; i < k; i++)
			heapNodes.emplace_back(new HeapNode(0));

		for (int i = 0; i < (int)(k / 2); i++) {
			auto leftIndex = 2 * i + 1;
			auto rightIdnex = 2 * i + 2;

			if (leftIndex < k)	heapNodes[i]->left = heapNodes[leftIndex];
			if (rightIdnex < k) heapNodes[i]->right = heapNodes[rightIdnex];
		}

		// Always adding from the root
		for (const auto& item : nums)
			addElementtoHeap(heapNodes[0], item);

		// Returning the values in the node, not the nodes itself
		return getVectorFromHeap();
	}
};

template <typename T>
void printvector(const T& arr) {
	for (const auto& item : arr)
		cout << item << " ";

	cout << endl;
}

int main() {
	Solution s;
	
	// Test case 1, should output 1,2
	vector<int> input1{ 1,1,1,2,2,3 };
	auto ret = s.topKFrequent(input1, 2);
	printvector(ret);

	// test case 2 should output 1,2,3
	vector<int> input2{ 1,1,1,2,2,3,3,3,4 };
	ret = s.topKFrequent(input2, 3);
	printvector(ret);	

	return 0;
}
