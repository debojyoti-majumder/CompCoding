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

            // if returned -1 then the replacment character is not found
            int getReplacementCharPos(size_t pos) {
                auto retVal{-1};
                auto sz {_inputString.size() };

                for( size_t i=0; i<sz; i++ ) {
                    if( _inputString[pos] != _inputString[i] && pos != i ) {
                        if( i == 0 || i == sz - 1 ) {
                            retVal = i;
                            break;
                        }

                        auto& ch1 { _inputString[i-1] };
                        auto& ch2 { _inputString[i+1] };

                        if( ch1 != ch2 ) {
                            retVal = i;
                            break;
                        }
                    }
                }

                return retVal;
            }

        public:
            string reorganizeString(string S) {
                string retValue {""};
                _inputString = S;
                
                // If the string size is leq 2 then there is no option
                // to swap the string
                auto sz { _inputString.size() };
                if( sz <= 2 ) return S;

                for( size_t i=0; i<sz-1; i++ ) {
                    if( _inputString[i] == _inputString[i+1] ) {
                        auto pos { getReplacementCharPos(i) };
                        
                        // Should return empty string
                        if( pos == -1 ) {
                            retValue = "";
                            break;
                        }

                        // Swaping to break sequence like "kk"
                        auto tmp { _inputString[i+1] };
                        _inputString[i+1] = _inputString[pos];
                        _inputString[pos] = tmp;
                        retValue = _inputString;
                    }
                }

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
        ASSERT_THAT(s.reorganizeString("baaba"),"ababa");
    }
}