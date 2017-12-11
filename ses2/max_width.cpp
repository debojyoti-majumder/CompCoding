// Problem URL:https://leetcode.com/problems/maximum-width-of-binary-tree/description/
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
    int _count;
    
    void recurserMethod(TreeNode* nd, int depth) {
        if( nd == nullptr ) {
            _count += depth;
            return;
        }
        
        int n_depth = depth + 1;
        recurserMethod(nd->left, n_depth);
        recurserMethod(nd->right, n_depth);
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        _count = 0;
        recurserMethod(root,0);
        
        return _count;
    }
};
