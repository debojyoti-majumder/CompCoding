#include <vector>

class TreeNode {
private:
	int _nodeid;
	int _depth;
	vector<TreeNode> _childrens;

public:
	TreeNode(int id) : _nodeid(id), _depth(0), _childrens({}) {}
	
	void addChild(TreeNode nd) {
		if (_depth == 0)
			_depth = 1;

		_childrens.push_back(nd);
		for (auto child : _childrens)
			child.increaseDepth();
	}

	void increaseDepth() {
		_depth += 1;
		for (auto child : _childrens)
			child.increaseDepth();
	}
};

class Solution {
private:
	map<int, TreeNode> _nodeList;

	// Creates and get's the node for the node list
	TreeNode getNode(int nodeId) {
		auto n = _nodeList.find(nodeId);
		if (n == end(_nodeList)) {
			TreeNode m(nodeId);

			_nodeList.insert({ nodeId, m });
			return m;
		}
		else
			return n->second;
	}

public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		for (auto edge : edges) {
			if (edge.first > n || edge.second > n)
				throw "Invalid Edge input exception";

			auto nd_1 = getNode(edge.first);
			auto nd_2 = getNode(edge.second);

			nd_1.addChild(nd_2);
			nd_2.addChild(nd_1);
		}

		return { 1 };
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

