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
        public:
            string reorganizeString(string S, size_t startPos = 0) {
                auto lengthDiff { S.length() - startPos };
                string retValue {""};

                // These will be base cases for the recursive call
                if( lengthDiff <= 1 ) return S;
                else if( lengthDiff == 2 ) return S[startPos] == S[startPos + 1] ? "" : S;

                auto char1 { S[startPos] };
                auto char2 { S[startPos + 1] };
                
                if( char1 == char2 ) {
                    // Have to find a character which is not equal to those chars
                    auto it = find_if(S.begin(), S.end(), [&](char ch) {
                        return ch != char1;
                    });
                    
                    if( it != S.end() ) {
                    }
                }
                else {
                    auto nextString { S.substr(startPos+1) };
                    auto ret { reorganizeString(nextString) };
                    
                    if( ret.length() != 0 && char2 != ret[0]) {
                        retValue += char1 + char2;
                        retValue += ret;
                    }
                }

                return retValue;
            }
    };

    GTEST_TEST(Leet767, Test1) {
        Solution s;
        ASSERT_THAT(s.reorganizeString("aab"), "aba");
        ASSERT_THAT(s.reorganizeString("abcdeff"), "abcdfef");
    }

    GTEST_TEST(Leet767, Test2) {
        Solution s;
        ASSERT_THAT(s.reorganizeString("aaab"), "");
    }

    GTEST_TEST(Leet767, TLECase1) {
        Solution s;
        ASSERT_THAT(s.reorganizeString("kkkkzrkatkwpkkkktrq"), "");
    }
}