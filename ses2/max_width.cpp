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
	bool isLeafNode(TreeNode* nd) {
		if (nd == nullptr)
			return true;

		if (nd->left == nullptr && nd->right == nullptr)
			return true;
		else
			return false;
	}

public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		if (isLeafNode(root))
			return 1;

		auto l_width = widthOfBinaryTree(root->left);
		auto r_width = widthOfBinaryTree(root->right);

		if (l_width != r_width)
			return max({ l_width,r_width });
		else
			return l_width + r_width;
	}
};
