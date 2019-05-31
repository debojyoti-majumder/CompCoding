/*
    Problemm URL:   https://leetcode.com/problems/ambiguous-coordinates/
    Problem Id:     816
    Issue Id:       
*/

#include <vector>
#include <string>

#include "gtest\gtest.h"
#include "gmock\gmock.h"

namespace Leetcode816 {
    using namespace std;

    class Solution {
        private:
            vector<string> getPossibleNumbers(const string& input) {
                vector<string> validNumbers;
                auto inputLength { input.length() };

                if( inputLength == 1 ) {
                    validNumbers.emplace_back(input);
                    return validNumbers;
                }

                // If the number is a "good integer"
                auto intVal { atoi(input.c_str()) };
                stringstream ss;
                ss << intVal;
                auto comprator { ss.str() };
                if( comprator == input ) validNumbers.emplace_back(input);

                // Have to insert a dot in every other location
                for( size_t i=1; i<inputLength; i++ ) {
                    auto candidateString { input };
                    candidateString.insert(i, ".");
                    double floatValue { atof(candidateString.c_str()) };
                    stringstream ss;
                    ss << floatValue;
                    auto fvalStr { ss.str() };

                    if( fvalStr == candidateString ) validNumbers.emplace_back(fvalStr);
                }

                return validNumbers;
            }

        public: 
            vector<string> ambiguousCoordinates(string S) {
                auto stringLength { S.length() };
                vector<string> returnCords;

                if( stringLength <= 2 ) return returnCords;
                
                for( size_t i=1; i<stringLength-2; i++ ) {
                    auto comp1 { S.substr(1,i) };
                    auto comp2 { S.substr(i+1,stringLength-i-2) };

                    auto vaildFirstCords { getPossibleNumbers(comp1) };
                    auto validSecondCords { getPossibleNumbers(comp2) };

                    for(const auto& x : vaildFirstCords ) {
                        for(const auto& y: validSecondCords ) {
                            stringstream ss;
                            ss << "(" << x << ", " << y << ")";

                            returnCords.emplace_back(ss.str());
                            ss.str() = "";
                        }                        
                    }
                }

                return returnCords;
            }
    };

    GTEST_TEST(Prob816, Ex1) {
        Solution s;
        auto ret = s.ambiguousCoordinates("(123)");

        // "(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"
        vector<string> out{"(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"};
        ASSERT_THAT(ret, testing::UnorderedElementsAreArray(out));
    }

    GTEST_TEST(Prob816, Ex2) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(00011)") };

        vector<string> out {"(0.001, 1)", "(0, 0.011)"};
        ASSERT_THAT(ret, testing::UnorderedElementsAreArray(out));
    }

    GTEST_TEST(Prob816, Ex3) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(0123)") };
        
        vector<string> out{"(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"};
        ASSERT_THAT(ret, testing::UnorderedElementsAreArray(out));
    }

    GTEST_TEST(Prob816, Ex4) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(100)") };

        vector<string> out{(10, 0)};
        ASSERT_THAT(ret, testing::UnorderedElementsAreArray(out));
    }
}