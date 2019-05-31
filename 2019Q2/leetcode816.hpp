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
                    auto fvalStr { to_string(floatValue) };

                    // Have to remove 
                    fvalStr.erase(fvalStr.find_last_not_of('0') + 1, string::npos );

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

    GTEST_TEST(Prob816, ZeroTest) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(0123)") };
        auto zeroTest { s.ambiguousCoordinates("(0000001)") };   
        
        vector<string> out{"(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"};
        vector<string> out2{"(0, 0.00001)"};

        ASSERT_THAT(ret, testing::UnorderedElementsAreArray(out));
        ASSERT_THAT(zeroTest, testing::UnorderedElementsAreArray(out2));
    }

    GTEST_TEST(Prob816, Ex4) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(100)") };

        vector<string> out{"(10, 0)"};
        ASSERT_THAT(ret, testing::UnorderedElementsAreArray(out));
    }

    GTEST_TEST(Prob816, LongString) {
        Solution s;
        auto ret { s.ambiguousCoordinates("(133569498)") };

        vector<string> out{
            "(1, 3.3569498)","(1, 33.569498)","(1, 335.69498)","(1, 3356.9498)","(1, 33569.498)","(1, 335694.98)","(1, 3356949.8)","(1, 33569498)",
            "(1.3, 3.569498)","(1.3, 35.69498)","(1.3, 356.9498)","(1.3, 3569.498)","(1.3, 35694.98)","(1.3, 356949.8)","(1.3, 3569498)",
            "(13, 3.569498)","(13, 35.69498)","(13, 356.9498)","(13, 3569.498)","(13, 35694.98)","(13, 356949.8)","(13, 3569498)",
            "(1.33, 5.69498)","(1.33, 56.9498)","(1.33, 569.498)","(1.33, 5694.98)","(1.33, 56949.8)","(1.33, 569498)",
            "(13.3, 5.69498)","(13.3, 56.9498)","(13.3, 569.498)","(13.3, 5694.98)","(13.3, 56949.8)","(13.3, 569498)",
            "(133, 5.69498)","(133, 56.9498)","(133, 569.498)","(133, 5694.98)","(133, 56949.8)","(133, 569498)",
            "(1.335, 6.9498)","(1.335, 69.498)","(1.335, 694.98)","(1.335, 6949.8)","(1.335, 69498)",
            "(13.35, 6.9498)","(13.35, 69.498)","(13.35, 694.98)","(13.35, 6949.8)","(13.35, 69498)",
            "(133.5, 6.9498)","(133.5, 69.498)","(133.5, 694.98)","(133.5, 6949.8)","(133.5, 69498)",
            "(1335, 6.9498)","(1335, 69.498)","(1335, 694.98)","(1335, 6949.8)","(1335, 69498)",
            "(1.3356, 9.498)","(1.3356, 94.98)","(1.3356, 949.8)","(1.3356, 9498)",
            "(13.356, 9.498)","(13.356, 94.98)","(13.356, 949.8)","(13.356, 9498)",
            "(133.56, 9.498)","(133.56, 94.98)","(133.56, 949.8)","(133.56, 9498)",
            "(1335.6, 9.498)","(1335.6, 94.98)","(1335.6, 949.8)","(1335.6, 9498)",
            "(13356, 9.498)","(13356, 94.98)","(13356, 949.8)","(13356, 9498)",
            "(1.33569, 4.98)","(1.33569, 49.8)","(1.33569, 498)","(13.3569, 4.98)","(13.3569, 49.8)","(13.3569, 498)","(133.569, 4.98)","(133.569, 49.8)","(133.569, 498)","(1335.69, 4.98)","(1335.69, 49.8)","(1335.69, 498)","(13356.9, 4.98)","(13356.9, 49.8)","(13356.9, 498)","(133569, 4.98)","(133569, 49.8)","(133569, 498)","(1.335694, 9.8)","(1.335694, 98)","(13.35694, 9.8)","(13.35694, 98)","(133.5694, 9.8)","(133.5694, 98)","(1335.694, 9.8)","(1335.694, 98)","(13356.94, 9.8)","(13356.94, 98)","(133569.4, 9.8)","(133569.4, 98)","(1335694, 9.8)","(1335694, 98)","(1.3356949, 8)","(13.356949, 8)","(133.56949, 8)","(1335.6949, 8)","(13356.949, 8)","(133569.49, 8)","(1335694.9, 8)","(13356949, 8)"};
        ASSERT_THAT(ret, testing::UnorderedElementsAreArray(out));
    }
}