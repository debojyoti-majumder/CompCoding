// Problem url: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
/**
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
    void recurse_flatter(TreeNode* nd) {
	if (nd != nullptr) {
		// Performing the shift
		auto temp = nd->right;
		nd->right = nd->left;
		nd->left = nullptr;

		// Go to the right most tree node
		auto it = nd;
		while (it->right != nullptr)
			it = it->right;

		// Append the node
		it->right = temp;

		// Call the function recusrively
		flatten(nd->right);
	}
    }
public:
    void flatten(TreeNode* root) {
        recurse_flatter(root);
    }
    
};
