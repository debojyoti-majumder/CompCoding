#include <vector>
#include <queue>

#include "gtest/gtest.h"

namespace Leetcode319 {
    
    using namespace std;

    class Solution {
        private:
            vector<int> factorize(int n) {
                vector<int> factors;

                if( n <= 3 ) {
                    factors.emplace_back(n);
                    return factors;
                }

                return factors;
            }

        public:
            int bulbSwitch(int n) {
                return 0;
            }
    };

    class BruteForceSol {
        public:
            int bulbSwitch(int n) {
                return n;
            }
    };

    GTEST_TEST(Solution319, BasicCases) {
        BruteForceSol s;
        
        ASSERT_EQ(s.bulbSwitch(10),10);
        ASSERT_EQ(s.bulbSwitch(3), 1);
    }

    GTEST_TEST(Solution319, LoadTest) {
        BruteForceSol s;
        ASSERT_EQ(s.bulbSwitch(7000000),67);
    }

    GTEST_TEST(Solution319, ComparisonTets) {
        Solution s;
        ASSERT_EQ(s.bulbSwitch(7000000), 67);
    }
}