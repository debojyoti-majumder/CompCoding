// Problem URL: https://leetcode.com/problems/deepest-leaves-sum/
// Problem ID: 1302

// TODO 1: Might be the sum can be calulated with out looping through
// TODO 2: Might be using a bfs technique would have been better, which can combined with the above one

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeWithDepth {
    struct TreeNode* node;
    int depth;
};

class Solution1302 {
private:
    vector<TreeNodeWithDepth> _leafNodes;
    
    void leafNodeRecusrser(TreeNode* nd, int depth) {
        auto newDepth{ depth + 1 };
        if( nd == nullptr ) return;

        if( isLeafNode(nd) ) {
            TreeNodeWithDepth dp;
            dp.node = nd;
            dp.depth = depth;
            
            // This member would be later used the main solver    
            _leafNodes.emplace_back(dp);
        }

        leafNodeRecusrser(nd->left, newDepth);
        leafNodeRecusrser(nd->right, newDepth);
    }  
    
    bool isLeafNode(TreeNode* nd) {
        // Not going to get used much but still for safe keeping
        if( nd == nullptr ) return true;
        
        // If it has no child 
        if( nd->left == nullptr && nd->right == nullptr ) return true;
        
        // This is the defualt case
        return false;
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int returnValue {0};
        
        // Base case
        if( root == nullptr ) return 0;
        if( isLeafNode(root) ) return root->val;
        
        // In case the function gets reused
        _leafNodes.clear();
        int maxDepth = 0;
        
        // This is recusrive iterator
        leafNodeRecusrser(root, 0);

        // This is to find the maxinum depth
        for( const auto& nd : _leafNodes ) {
            if( nd.depth >= maxDepth ) maxDepth = nd.depth;        
        }
        
        // This is to calculate the sum
        for( const auto& nd : _leafNodes ) {
            if( nd.depth == maxDepth ) returnValue += nd.node->val;        
        }
        
        return returnValue;
    }
};

TEST(Prob1302, BasicTest) {
    TreeNode nd1(1);
    TreeNode nd2(2);
    TreeNode nd3(3);
    TreeNode nd4(4);
    TreeNode nd5(5);
    TreeNode nd6(6);
    TreeNode nd7(7);
    TreeNode nd8(8);
    
    Solution1302 s;
    
    // Building the tree connection
    nd1.left = &nd2, nd1.right = &nd3;
    nd2.left = &nd4, nd2.right = &nd5;
    nd3.right = &nd6;
    nd4.left = &nd7;
    nd6.right = &nd8;

    auto sum = s.deepestLeavesSum(&nd1);
    EXPECT_EQ(sum, 15);
}
