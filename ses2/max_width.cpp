/** https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	map<int, int> _depthMap;
	bool isLeafNode(TreeNode* nd) {
		if (nd == nullptr)
			return true;

		if (nd->left == nullptr && nd->right == nullptr)
			return true;
		else
			return false;
	}

	void incrementMap(int d) {
		auto it = _depthMap.find(d);
		if (it == _depthMap.end())
			_depthMap.insert(make_pair(d, 1));
		else
			it->second += 1;
	}

	void treeIterator(TreeNode* n, int d) {
		incrementMap(d);

		if (n == nullptr) 
			return;

		if (isLeafNode(n) == false ){
			treeIterator(n->left, d + 1);
			treeIterator(n->right, d + 1);
		}
	}

public:
	int widthOfBinaryTree(TreeNode* root) {
		int max = 0;

		treeIterator(root, 0);

		for (auto it : _depthMap) {
			if (it.second > max)
				max = it.second;
		}

		return max;
	}
};
