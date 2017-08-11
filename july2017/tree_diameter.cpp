#include <algorithm>

using namespace std;

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
    int depthOfNode(TreeNode* node, int count) {
        int newCount = count + 1;
        
        if( node == nullptr )
            return count;
        
        return max(depthOfNode(node->left, newCount), depthOfNode(node->right, newCount));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if( root == nullptr )
            return 0;
        
        int left_depth = depthOfNode(root->left, 0);
        int right_depth = depthOfNode(root->right, 0);
        
        return left_depth + right_depth;
    }
};
