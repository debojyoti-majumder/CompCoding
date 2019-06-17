// Problem URL: https://leetcode.com/problems/container-with-most-water/

#include <vector>
#include "gtest/gtest.h"

namespace Leetcode011 {
    using namespace std;
    using namespace testing;

    class Solution {
        private:
            // Min value, is left
            tuple<int,bool> getSocre(const vector<int>& numbers) {
                auto firstItem { numbers.begin() };
                auto lastItem { numbers.back() };

                auto isLeftLess { *firstItem < lastItem };
                auto minVal { min(*firstItem, lastItem) };
                minVal = minVal * (numbers.size() - 1);

                return make_tuple(minVal,isLeftLess);
            };

        public:
            int maxArea(vector<int>& height) {
                auto retVal { getSocre(height) };
                auto maxVal { get<0>(retVal) };

                while( height.size() > 2 ) {
                    auto isLeft { get<1>(retVal) };

                    if( isLeft )
                        height.erase(height.begin());
                    else {
                        height.pop_back();
                    }
                    
                    retVal = getSocre(height);
                    if( get<0>(retVal) < maxVal ) 
                        break;
                    
                    maxVal = get<0>(retVal);
                }

                return maxVal;
            }
    };

    GTEST_TEST(Leetcode011, BasicTests) {
        Solution s;
        vector<int> nums {1,8,6,2,5,4,8,3,7};
        vector<int> testCrash {0,2};

        ASSERT_THAT(s.maxArea(nums),49);
        ASSERT_THAT(s.maxArea(testCrash), 0);
    }

    GTEST_TEST(Leetcode011, Extest) {
        vector<int> inp {2,3,4,5,18,17,6};
        Solution s;

        ASSERT_THAT(s.maxArea(inp), 17);
    }
}