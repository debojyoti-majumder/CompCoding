// Problem URL :    https://leetcode.com/problems/longest-absolute-file-path/
// Issue Id:        36    
// Comments:
//  1. Should be in O(n)

#include <string>
#include "gtest/gtest.h"

namespace Leetcode388 {
    using namespace std;

    class Solution {
    public:
        int lengthLongestPath(string input) {
            return 0;    
        }
    };

    GTEST_TEST(Leetcode388, BasicTest) {
        auto inp{"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"};
        Solution s;

        EXPECT_EQ(s.lengthLongestPath(inp), 20);
    }
}