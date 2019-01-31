// Solution accepted: https://leetcode.com/problems/merge-two-binary-trees/description/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        int value_1 = 0;
        int value_2 = 0;
        
        // This is the base for recursion
        if( t1 == nullptr && t2 == nullptr )
            return nullptr;
        
        if( t1 )
            value_1 = t1->val;
        
        if( t2 )
            value_2 = t2->val;
        
        TreeNode* node = new TreeNode(value_1 + value_2);
        
        TreeNode* t1_left_child = nullptr;
        TreeNode* t2_left_child = nullptr;
        TreeNode* t1_right_child = nullptr;
        TreeNode* t2_right_child = nullptr;
        
        if( t1 ) {
            t1_left_child = t1->left;
            t1_right_child = t1->right;
        }
        
        if( t2 ) {
            t2_left_child = t2->left;
            t2_right_child = t2->right;
        }
        
        node->left = mergeTrees(t1_left_child, t2_left_child);
        node->right = mergeTrees(t1_right_child, t2_right_child);
        
        return node;
    }
};
