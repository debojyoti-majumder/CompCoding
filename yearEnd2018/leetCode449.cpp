// Problem URL: https://leetcode.com/problems/serialize-and-deserialize-bst/

#include "stdafx.h"

#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x) , left(nullptr), right(nullptr) {}
};


class Codec {
	public:
		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			string accData;
			vector<string> treeArray;

			for (const auto& item : treeArray) {
				accData += item;
				accData += ",";
			}
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			return nullptr;
		}
};

int main() {
	TreeNode nd0(0), nd1(1), nd2(2), nd3(3), nd4(4), nd5(5), nd6(6), nd7(7), nd8(8), nd9(9);

	Codec c;
	auto serilizedData = c.serialize(&nd0);
	auto tr = c.deserialize(serilizedData);

	return 0;
}
