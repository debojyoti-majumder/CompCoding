// Problem Url: https://leetcode.com/problems/contiguous-array/
// Problem Id:  525

#include <vector>
#include "gtest/gtest.h"

namespace Leetcode525 {
    using namespace std;

    class Solution {
        public:
            int findMaxLength(vector<int>& nums) {
                return 0;
            }
    };

    GTEST_TEST(Prob525, Ex1) {
        Solution s;
        vector<int> inp{0,1};

        EXPECT_EQ(s.findMaxLength(inp), 2);
    }

    GTEST_TEST(Prob525, Ex2) {
        Solution s;
        vector<int> inp{0,1,0};

        EXPECT_EQ(s.findMaxLength(inp), 2);
    }

    GTEST_TEST(Prob525, Ex3) {
        Solution s;
        vector<int> inp{1,1,0,0,0,0,1,1,0,1};

        EXPECT_EQ(s.findMaxLength(inp), 10);
    }
}