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
                auto lastItem { numbers.end() };

                auto isLeftLess { *firstItem < *lastItem };
                auto minVal { min(*firstItem, *lastItem) };
                minVal = minVal * (numbers.size() - 1);

                return make_tuple(minVal,isLeftLess);
            };

        public:
            int maxArea(vector<int>& height) {
                auto retVal { getSocre(height) };
                auto maxVal { get<0>(retVal) };

                while( height.size() ) {
                    auto isLeft { get<1>(retVal) };

                    if( isLeft )
                        height.erase(height.begin());
                    else {
                        height.pop_back();
                    }
                    
                    retVal = getSocre(height);
                }

                return maxVal;
            }
    };

    GTEST_TEST(Leetcode011, BasicTests) {
        Solution s;
        vector<int> nums {1,8,6,2,5,4,8,3,7};
        ASSERT_THAT(s.maxArea(nums),49);
    }
}