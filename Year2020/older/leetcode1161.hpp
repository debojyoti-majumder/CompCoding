// Problem URL: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Problem ID: 1161

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        return 0;      
    }
};

TEST(Prob1161, BasicTest) {
    TreeNode nd1(1);
    TreeNode nd2(7);
    TreeNode nd3(0);
    TreeNode nd4(7);
    TreeNode nd5(-8);

    Solution s;
    nd1.left = &nd2, nd1.right = &nd3;
    nd2.left = &nd4, nd2.right = &nd5;

    EXPECT_EQ(s.maxLevelSum(&nd1), 2);
}
