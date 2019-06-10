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

            int getAdjacentIndex() {
                auto index { -1 };
                auto strLength { _inputString.length() };

                for( size_t i=0; i<strLength-1; i++ ) {
                    if( _inputString[i] == _inputString[i+1] ) {
                        index = i;
                        break;
                    }
                }

                return index;
            }

            int getCandidateChar(char ch, size_t lastSwapIndex) {
                int index { -1 };

                for( size_t i=lastSwapIndex; i<_inputString.length(); i++ ) {
                    if( _inputString[i] != ch ) {
                        index = i;
                        break;
                    }
                }

                return index;
            }

        public:
            string reorganizeString(string S) {
                string retValue {""};
                _inputString = S;
                int lastIndex {0};

                auto len { S.size() };

                for( size_t i=0; i<len-1; i++ ) {
                    auto index = getAdjacentIndex();
                    
                    if( index == -1 ) {
                        retValue = _inputString;
                        break;
                    }

                    auto swIndex = getCandidateChar(_inputString[i], lastIndex);
                    if( swIndex != -1 ) {
                        lastIndex = swIndex + 1;
                        auto tmp { _inputString[index+1] };
                        _inputString[index+1] = _inputString[swIndex];
                        _inputString[swIndex] = tmp;
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
        ASSERT_THAT(s.reorganizeString("kkkkzrkatkwpkkkktrq"), "");
    }
}