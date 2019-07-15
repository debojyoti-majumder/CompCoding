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
                    _folderNameLengthStack.emplace(folderNameLength + lastLen);
                }
                else {
                    if( false == _folderNameLengthStack.empty() ) {
                        _folderNameLengthStack.pop();
                        auto lastLen { _folderNameLengthStack.top() };
                        _folderNameLengthStack.emplace(lastLen + folderNameLength);
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
                auto topItem { _folderNameLengthStack.top() };
                auto pathLength { topItem + (int)fileName.length() };

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
        Solution s;

        EXPECT_EQ(s.lengthLongestPath(inp), 20);
    }
}