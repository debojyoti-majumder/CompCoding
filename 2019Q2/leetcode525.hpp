// Problem Url: https://leetcode.com/problems/contiguous-array/
// Problem Id:  525

#include <vector>
#include "gtest/gtest.h"

namespace Leetcode525 {
    using namespace std;

    class Solution {
        private:
            vector<int> numbers;

            int findMax(size_t pos, int contOneCount, int contZeroCount) {
                auto sz { numbers.size() };
                auto itemsRemaining { sz - pos };
                auto retVal { 0 };

                // Base cases
                if( pos >= sz - 1 ) return 0;
                if( contOneCount > itemsRemaining || contZeroCount > itemsRemaining ) return 0;

                auto num { (bool)numbers[pos] };
                auto nextNumber { (bool)numbers[pos +1] };
                
                // This means they are blanced
                if( num == !(nextNumber) ) {
                    return 2 + findMax(pos+2,0,0);
                }

                auto withoutOp { findMax(pos+1,0,0) };
                if( num ) {
                    auto withOneOp { findMax(pos+1,contOneCount+1,contZeroCount) };
                    retVal = max(withOneOp,withOneOp);
                }
                else {
                    auto withZeroOp { findMax(pos+1,contOneCount,contZeroCount+1) };
                    retVal = max(withoutOp, withZeroOp);
                }

                return retVal;
            }

        public:
            int findMaxLength(vector<int>& nums) {
                numbers = nums;
                return findMax(0,0,0);
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

    GTEST_TEST(Prob525, LeadingZero) {
        Solution s;
        vector<int> inp { 0,0,0,0,1,1};

        EXPECT_EQ(s.findMaxLength(inp), 4);
    }

    GTEST_TEST(Prob525, Ex3) {
        Solution s;
        vector<int> inp{1,1,0,0,0,0,1,1,0,1};

        EXPECT_EQ(s.findMaxLength(inp), 10);
    }
}