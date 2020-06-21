// Problem URL :    https://leetcode.com/problems/longest-absolute-file-path/
// Issue Id:        36    
// Comments:
//  1. Should be in O(n)

#include <string>
#include <stack>

#include "gtest/gtest.h"

namespace Leetcode388 {
    using namespace std;
    
    class Solution {
    private:
        int _returnValue;
        int _currentLevel;
        stack<int> _folderNameLengthStack;

        int getTabCount(const string& str) {
            auto tabCount = 0;
            
            for( const auto& ch : str ) {
                if( ch == '\t' )
                    tabCount++;
                else
                    break;
            }

            return tabCount;
        }

        string getGoodPath(const string& input) {
            string outputString{""};
            auto charSeen { false };

            for( size_t i=0; i<input.size(); i++ ) {
                if( (input[i] == '\t' || input[i] == ' ') && charSeen == false ) {
                    continue;
                }
                else {
                    charSeen = true;
                    outputString += input[i];
                }
            }

            return outputString;
        }

        void processToken(const string& str) {
            auto level { getTabCount(str) };    
            auto dotIndex { str.find_first_of('.') };

            if( dotIndex == string::npos ) {
                // This means it's folder
                auto folderName { getGoodPath(str) };
                auto folderNameLength { folderName.size() };
                
                if( level > _currentLevel ) {
                    auto lastLen { _folderNameLengthStack.top() };
                    _folderNameLengthStack.emplace(folderNameLength + lastLen + 1);
                }
                else {    
                    if( _folderNameLengthStack.size() > 1 ) {
                        _folderNameLengthStack.pop();
                        auto lastLen { _folderNameLengthStack.top() };
                        _folderNameLengthStack.emplace(lastLen + folderNameLength + 1);
                    }
                    else {
                        if( !_folderNameLengthStack.empty() )
                            _folderNameLengthStack.pop();
                        
                        _folderNameLengthStack.emplace(folderNameLength);
                    }
                }
            }
            else {
                // This is for file
                auto fileName { getGoodPath(str) };
                auto pathLength { (int)fileName.length() };

                
                if( !_folderNameLengthStack.empty() ) {
                    auto topItem { _folderNameLengthStack.top() };
                    pathLength += 1 + topItem;
                }

                if( pathLength > _returnValue )
                    _returnValue = pathLength;
            }

            _currentLevel = level;
        }

    public:
        int lengthLongestPath(string input) {
            stringstream inputStream(input);
            string token;
            
            // Initilizing the states
            _returnValue = 0;
            _currentLevel = 0;
            
            // Ensuring the number stack would never be empty
            while(!_folderNameLengthStack.empty()) 
                _folderNameLengthStack.pop();

            while(getline(inputStream, token)) {
                processToken(token);
            }

            return _returnValue;
        }
    };

    GTEST_TEST(Leetcode388, BasicTest) {
        auto inp{"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"};
        auto inp2{"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"};
        auto inp3 {"a.txt"};
        auto inp4 {"a\n\tb.txt\na2\n\tb2.txt"};

        Solution s;

        EXPECT_EQ(s.lengthLongestPath(inp), 20);
        EXPECT_EQ(s.lengthLongestPath(inp2), 32);
        EXPECT_EQ(s.lengthLongestPath(inp3), 5);
        EXPECT_EQ(s.lengthLongestPath(inp4), 9);
    }

    GTEST_TEST(Leetcode388, ExTestCases) {
        auto inp1 { "dir\n    file.txt" };
        auto inp2 {"dir\n\tsubdir1\n\tsubdir2"};
        auto filenamewithSpaces {"new folder\n\tsome file.txt"};
        Solution s;

        EXPECT_EQ(s.lengthLongestPath(inp1), 12);
        EXPECT_EQ(s.lengthLongestPath(inp2), 0);
        EXPECT_EQ(s.lengthLongestPath(filenamewithSpaces), 24);
    }
}