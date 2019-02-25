// LeetCodeWhiteBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Problem URL: https://leetcode.com/problems/redundant-connection/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

struct GraphNode {
	int value;
	vector<GraphNode*> childrens;
	
	GraphNode(int v) : value(v), childrens{} {}

	void addConnection(GraphNode* nd) {
		if( nd != nullptr ) childrens.emplace_back(nd);
	}
};

struct LoopingException {
	int source;
};

class Solution {
private:
	map<int, GraphNode*>	_nodes;
	set<int>				_vistsedList;

	void buildNodes(vector<vector<int>>& edges) {
		// Going through all the edges and building the graph
		for (const auto& edge : edges) {
			auto node1Id = edge[0];
			auto node2Id = edge[1];

			GraphNode *node1, *node2;
			auto it1 = _nodes.find(node1Id);
			if (it1 == _nodes.end()) {
				node1 = new GraphNode(node1Id);
				_nodes.insert(make_pair(node1Id, node1));
			}
			else
				node1 = it1->second;

			auto it2 = _nodes.find(node2Id);
			if (it2 == _nodes.end()) {
				node2 = new GraphNode(node2Id);
				_nodes.insert(make_pair(node2Id, node2));
			}
			else
				node2 = it2->second;

			// This is because it's unidiretional graph
			node1->addConnection(node2);
			node2->addConnection(node1);
		}
	}

	void performDFS(GraphNode* node, GraphNode* parent = nullptr ) {
		if (node == nullptr)
			return;

		auto it = _vistsedList.count(node->value);

		if (it == 0) {
			_vistsedList.insert(node->value);

			for (auto& nd : node->childrens) {
				if( nd != parent ) performDFS(nd, node);
			}
		}
		else {
			LoopingException ex;
			if (parent != nullptr)
				ex.source = parent->value;

			_vistsedList.clear();
			throw ex;
		};
	}

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		// Doing the job of a constructor here
		_nodes.clear();
		_vistsedList.clear();
		
		vector<int> retVal{ -1,-1 };
		buildNodes(edges);

		try {
			auto startNode = _nodes.begin();
			performDFS(startNode->second);
		}
		catch(LoopingException& ex) {
			for (auto it = edges.crbegin(); it != edges.crend(); it++) {
				auto edge = *it;

				if (edge[0] == ex.source || edge[1] == ex.source) {
					retVal = edge;
					break;
				}
			}
		}

		// Memory cleanup
		for (auto& nd : _nodes)
			delete nd.second;

		return retVal;
	}
};

int main() {
	vector<vector<int>> input1 = {
		{1,2}, {1,3}, {2,3}
	};

	vector<vector<int>> input2 = {
			{1, 2}, { 2, 3}, { 3, 4}, { 1, 4}, { 1, 5 }
	};

	vector<vector<int>> input3{ {1,3},{3,4},{1,5},{3,5},{2,3} };

	Solution sol;

	// Should output 2,3
	auto ret = sol.findRedundantConnection(input1);
	cout << ret[0] << ", " << ret[1] << "\n";

	// Should output 1,4
	ret = sol.findRedundantConnection(input2);
	cout << ret[0] << ", " << ret[1] << "\n";

	// Should output 3,5, test case failing
	ret = sol.findRedundantConnection(input3);
	cout << ret[0] << ", " << ret[1] << "\n";

	return 0;
}
