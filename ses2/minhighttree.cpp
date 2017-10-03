// MoreSolu.cpp : Defines the entry point for the console application.
// Problem url: https://leetcode.com/problems/minimum-height-trees/description/

#include "stdafx.h"

class TreeNode {
private:
	int _nodeid;

public:
	TreeNode() {}
	TreeNode(int id) : _nodeid(id), _depth(0), _neibours() { }
	int getId() const { return _nodeid; }
	vector<int> _neibours;
	int _depth;
};

class Solution {
private:
	vector<TreeNode> _nodeList;

	int dfs(int node_id, int p, int depth) {
		unsigned int m = 20000;
		vector<int> values;

		for (auto m : _nodeList[node_id]._neibours) {
			if (p != m) {
				values.push_back(dfs(m, node_id,depth+1));
			}
		}

		if (values.size() == 0)
			return depth;

		m = values[0];
		for (auto i = values.size()-1; i >= 1; i--) {
			if (m < values[i])
				m = values[i];
		}

		return m;
	}
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		for (auto i = 0; i < n; i++) {
			TreeNode n(i);
			_nodeList.push_back(n);
		}

		for (auto edge : edges) {
			// Make the connection
			_nodeList[edge.first]._neibours.push_back(edge.second);
			_nodeList[edge.second]._neibours.push_back(edge.first);
		}
		
		vector<int> v;
		vector<int> ret;

		for (int i = 0; i < n; i++)
			v.push_back(dfs(i, -1, 0));
		
		int m = v[0];
		for (auto l : v) {
			if (l < m)
				m = l;
		}

		for (int i = 0; i < n; i++) {
			if (m == v[i])
				ret.push_back(i);
		}

		return ret;
	}
};


void testMindepth() {

	//Solution s;

	//// Should output 1
	//auto res_1 = s.findMinHeightTrees(4, vector<pair<int, int>>{ { 1, 0 }, { 1, 2 }, { 1, 3 } });
	//for (auto m : res_1)
	//	cout << m << "";
	//cout << endl;

	//Solution s2;

	//// Should output 3,4
	//auto res_2 = s2.findMinHeightTrees(6, vector<pair<int, int>>{ { 0, 3 }, { 1, 3 }, { 2, 3 }, { 4, 3 }, { 5, 4 } });
	//for (auto m : res_2)
	//	cout << m << "";
	//cout << endl;

	Solution s3;

	// Should output 3
	auto res_3 = s3.findMinHeightTrees(6, vector<pair<int, int>>{{0, 1}, { 0, 2}, { 0, 3}, { 3, 4}, { 4, 5}});
	for (auto m : res_3)
		cout << m << "";
	cout << endl;
}

int main() {
	testMindepth();
    return 0;
}

