// Problem Url: https://leetcode.com/problems/invert-binary-tree/description/
// This code should invert a binary tree

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	 void displayInOrder() {

	 }
};

class Solution {
private:
	void invertRecurser(TreeNode* nd) {
		if( isLeaf(nd) == false ) {
			invertRecurser(nd->left);
			invertRecurser(nd->right);
		}
	}

	bool isLeaf(TreeNode* nd) const {
		if( nd == nullptr )
			return true;

		if( nd->left == nullptr && nd->right == nullptr )
			return true;
		
		return false;
	}

public:
    TreeNode* invertTree(TreeNode* root) {
		invertRecurser(root);
        return root;
    }
};

int main() {
	TreeNode* root = new TreeNode(4);
	TreeNode* leftSubTree = new TreeNode(2);
	TreeNode* rightSubTree = new TreeNode(3);

	leftSubTree->left = new TreeNode(9);
	leftSubTree->right = new TreeNode(5);

	rightSubTree->left = new TreeNode(3);
	rightSubTree->right = new TreeNode(8);

	root->left = leftSubTree;
	root->right = rightSubTree;

	Solution s;
	s.invertTree(root);
	
	return 0;
}