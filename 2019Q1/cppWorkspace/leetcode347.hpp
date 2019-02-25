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

	HeapNode(int val) : itemCount(0), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	HeapNode* _root;

	vector<int> getVectorFromHeap() {
		return vector<int>{};
	}

public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<HeapNode*> heapNodes;
		
		for (auto i = 0; i < k; i++)
			heapNodes.emplace_back(new HeapNode(nums[i]));

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
	
	// Test case 1
	vector<int> input1{ 1,1,1,2,2,3 };
	auto ret = s.topKFrequent(input1, 2);
	printvector(ret);

	return 0;
}
