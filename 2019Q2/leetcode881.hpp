// Problem URL: https://leetcode.com/problems/boats-to-save-people/
// Issue Id: 35

#include <vector>
#include "gtest/gtest.h"

namespace Leetcode881 {
    using namespace std;

    class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            return 0;
        }
    };

    GTEST_TEST(Leet881, BasicTests) {
        Solution s;
        vector<int> baseCase{1,2};
        vector<int> input1{3,2,2,1};  
        vector<int> input2 {3,5,3,4}; 

        // Should be able to fit in a boat
        ASSERT_EQ(s.numRescueBoats(baseCase, 3), 1);

        // Explanation: // (1, 2), (2) and (3)
        ASSERT_EQ(s.numRescueBoats(input1, 3), 3);

        // Explanation : // (3), (3), (4), (5)
        ASSERT_EQ(s.numRescueBoats(input2, 5), 4);
    }
}