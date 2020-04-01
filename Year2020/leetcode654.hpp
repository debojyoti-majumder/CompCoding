// Problem URL: https://leetcode.com/problems/maximum-binary-tree/
// Problem Id: 654

// Status: Accepted
// TODO 1: Reduce memory usage if posible

#include <vector>
#include <algorithm>

#include "TreeNode.h"
#include <gtest/gtest.h>

class Solution654 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        auto sz { nums.size() };

        // Base cases
        if( sz == 0 ) return nullptr;
        else if( sz == 1 ) return new TreeNode(nums[0]);

        // The max node becomes the root node
        auto maxElementIt { max_element(nums.begin(), nums.end()) };
        auto rootNode { new TreeNode(*maxElementIt) };
        
        // If the left sub tree is posible then create copy of it
        if( maxElementIt != nums.begin() ) {
            auto leftPathEnd { maxElementIt };
            vector<int> leftSubPart(nums.begin(), leftPathEnd);
            rootNode->left = constructMaximumBinaryTree(leftSubPart);
        }

        // Same done for right as in with the left one
        if( maxElementIt != nums.end() ) {
            auto rightPathStart { ++maxElementIt };
            vector<int> rightSubPart(rightPathStart, nums.end());
            rootNode->right = constructMaximumBinaryTree(rightSubPart);
        }

        return rootNode;        
    }
};

// This test case is not complete but someting to be worked with
TEST(Solution654, basicCase) {
    Solution654 s;
    vector<int> input1{3,2,1,6,0,5};
    auto tree { s.constructMaximumBinaryTree(input1) };

    //      6
    //    /   \
    //   3     5
    //    \    / 
    //     2  0   
    //       \
    //        1
    EXPECT_EQ(tree->val, 6);
    EXPECT_EQ(tree->left->val,3);
    EXPECT_EQ(tree->right->val,5);
}
