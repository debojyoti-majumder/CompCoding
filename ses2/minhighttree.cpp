#include <vector>

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		return {  1 };
	}
};


void testMindepth() {

	Solution s;

	// Should output 1
	auto res_1 = s.findMinHeightTrees(4, vector<pair<int,int>>{ { 1, 0 },{ 1, 2 },{ 1, 3 } });
	for (auto i : res_1)
		cout << i;
	cout << endl;

	// Should output 3,4
	auto res_2 = s.findMinHeightTrees(6, vector<pair<int,int>>{ { 0, 3 },{ 1, 3 },{ 2, 3 },{ 4, 3 },{ 5, 4 } });
	for (auto i : res_2)
		cout << i;
	cout << endl;

}
