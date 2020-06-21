// Probelm URL: https://leetcode.com/problems/top-k-frequent-elements/
// Leetcode id: 347
// Issue ID: 14

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:

public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> valuecount;
		vector<pair<int, int>> freqencyVector;
		vector<int> returnValue;

		for (const auto& number : nums) {
			auto it = valuecount.find(number);
			if (it != valuecount.end())
				it->second += 1;
			else
				valuecount.insert(make_pair(number, 1));
		}
		
		for (const auto& item : valuecount)
			freqencyVector.emplace_back(item);

		sort(freqencyVector.begin(), freqencyVector.end(), [](const auto& item1, const auto& item2){
			return item1.second > item2.second;
		});

		for (size_t i = 0; i < k; i++)
			returnValue.emplace_back(freqencyVector[i].first);

		return returnValue;
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
