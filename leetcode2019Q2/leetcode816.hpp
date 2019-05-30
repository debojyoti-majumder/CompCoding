/*
    Problemm URL:   https://leetcode.com/problems/ambiguous-coordinates/
    Problem Id:     816
    Issue Id:       
*/

#include <vector>
#include <string>

#include "gtest\gtest.h"

namespace Leetcode816 {
    using namespace std;

    class Solution {
        public:
            vector<string> ambiguousCoordinates(string S) {
                return {};
            }
    };

    GTEST_TEST(Prob816, Ex1) {
        Solution s;
        auto ret = s.ambiguousCoordinates("(123)");

        vector<string> out { "(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)" };
        ASSERT_EQ(ret, out);
    }

    GTEST_TEST(Prob816, Ex2) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(00011)") };

        vector<string> out {"(0.001, 1)", "(0, 0.011)"};
        ASSERT_EQ(out, ret);
    }

    GTEST_TEST(Prob816, Ex3) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(0123)") };
        
        vector<string> out{"(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"};
        ASSERT_EQ(out, ret);
    }

    GTEST_TEST(Prob816, Ex4) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(100)") };

        vector<string> out{(10, 0)};
        ASSERT_EQ(ret, out);
    }
}