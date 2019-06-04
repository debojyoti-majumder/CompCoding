// Problem URL: https://leetcode.com/problems/merge-intervals/
// Issue Id: 17

#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace Leetcode056 {
    using namespace std;
        
    class Solution {
        public:
            vector<vector<int>> merge(vector<vector<int>>& intervals) {
                return {};
            }
    };

    GTEST_TEST(Leet056, Test1) {
        vector<vector<int>> inp{{1,3},{2,6},{8,10},{15,18}};
        vector<vector<int>> out{{1,6},{8,10},{15,18}};
        Solution s;

        // Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
        ASSERT_THAT(s.merge(inp), testing::UnorderedElementsAreArray(out));
    }

    GTEST_TEST(Leet056, Test2) {
        vector<vector<int>> inp{{1,4}, {4, 5}};
        vector<vector<int>> out{{1,5}};
        Solution s;

        ASSERT_THAT(s.merge(inp), testing::UnorderedElementsAreArray(out));
    }
}