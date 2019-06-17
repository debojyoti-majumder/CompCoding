/*
    Problem URL: https://leetcode.com/problems/reorganize-string/
    Problem Id:  767
    Issue Id:    33
*/

#include <string>
#include "gtest/gtest.h"

namespace Leetcode767 {
    using namespace std;

    // This implementation have already given TLE error
    // best option would be to do a search
    class BruteForceSolution {
        private:
            bool isTwoAdjacent(const string& str) {
                auto sz{ str.size() };

                for( size_t i=0; i<=sz-2; i++ ) {
                    if( str[i] == str[i+1] )
                        return true;
                }

                return false;
            } 

            string permuteString(string s, size_t swapIndex = 0) {
                auto sz { s.size() };
                
                if( sz == swapIndex + 1 ) {
                    if( false == isTwoAdjacent(s) )
                        return s;
                }
                
                for( size_t i=swapIndex; i<sz; i++ ) {
                    auto nextItem{s};
                    auto buff { nextItem[i] };
                    nextItem[i] = nextItem[swapIndex];
                    nextItem[swapIndex] = buff;

                    auto ret = permuteString(nextItem, swapIndex+1);
                    if( ret.size() != 0 ) return ret;
                }

                return "";
            }

        public:
            string reorganizeString(string S) {
                return permuteString(S);
            }
    };

    class Solution {
        private:
            string _inputString;
        public:
            string reorganizeString(string S) {
                string retValue {""};
                _inputString = S;
                
                return retValue;
            }
    };

    GTEST_TEST(Leet767, Test1) {
        Solution s;
        ASSERT_THAT(s.reorganizeString("aab"), "aba");
        ASSERT_NE(s.reorganizeString("abcdeff"), "");
    }

    GTEST_TEST(Leet767, Test2) {
        Solution s;
        ASSERT_THAT(s.reorganizeString("aaab"), "");
    }

    GTEST_TEST(Leet767, TLECase1) {
        Solution s;
        ASSERT_NE(s.reorganizeString("kkkkzrkatkwpkkkktrq"), "");
    }
}