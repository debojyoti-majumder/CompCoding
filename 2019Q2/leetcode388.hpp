// Problem URL :    https://leetcode.com/problems/longest-absolute-file-path/
// Issue Id:        36    
// Comments:
//  1. Should be in O(n)

#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <algorithm>

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

        void processToken(const string& str) {
            auto level { getTabCount(str) };    
            auto folderName { str };
            auto dotIndex { str.find_first_of('.') };

            if( dotIndex == string::npos ) {
                // This means it's folder
                folderName.erase(remove(folderName.begin(), folderName.end(), '\t'), folderName.end());
                auto folderNameLength { folderName.size() };
                
                if( level > _currentLevel ) {
                    auto lastLen { _folderNameLengthStack.top() };
                    _folderNameLengthStack.emplace(folderNameLength + lastLen + 1);
                }
                else {
                    if( false == _folderNameLengthStack.empty() ) {
                        _folderNameLengthStack.pop();
                        auto lastLen { _folderNameLengthStack.top() };
                        _folderNameLengthStack.emplace(lastLen + folderNameLength + 1);
                    }
                    else {
                        _folderNameLengthStack.emplace(folderNameLength);
                    }
                }
            }
            else {
                // This is for file
                auto fileName { str };
                fileName.erase(remove(fileName.begin(), fileName.end(), '\t'), fileName.end());
                auto pathLength { (int)fileName.length() };

                // If the stack is empty then it is just a file name
                if( false == _folderNameLengthStack.empty() ) {
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
}