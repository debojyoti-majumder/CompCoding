/*
    Problem URL:    https://leetcode.com/problems/decode-string/description/
    Problem Id:     394
    Issue Id        30
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
private:
public:
    string decodeString(string s) {
        stack<int> repCountStack;
        stack<string> stringStack;

        stringstream loopAccumulator;
        for( const auto& ch: s ) {
            if( isdigit(ch) ) {
                repCountStack.push(ch - 48);
                continue;
            }
            else if( ch == '[' ) {
                // Would resetting the accumulator
                auto str { loopAccumulator.str() };
                if( str.length() != 0 ) 
                    stringStack.push(str);

                // Reset the accumulator    
                loopAccumulator.str("");
                continue;
            }
            else if( ch == ']' ) {
                auto reps { repCountStack.top() };
                repCountStack.pop();

                auto str { loopAccumulator.str() };
                if( str.length() != 0 )
                    stringStack.push(str);
                
                str = stringStack.top();
                stringStack.pop();
                string res { "" };

                for( auto i=0; i<reps; i++ ) {
                    res+= str;
                }

                // Clearing the accumulator is close ] is seen
                if( stringStack.empty() ) {
                    stringStack.push(res);
                }
                else {
                    // Modifing the top most item in the stack
                    stringStack.top().append(res);
                }

                loopAccumulator.str("");
                continue;
            }
            else {
                loopAccumulator << ch;
            }
        }

        auto retValue { stringStack.top() };

        // This is for string from last after ]
        auto addString { loopAccumulator.str() };
        if( addString.length() != 0 )
            retValue +=addString;

        return retValue;      
    }
};

int main() {
    Solution s;

    // Should output aaabcbc
    cout << s.decodeString("3[a]2[bc]") << endl;

    // Should output accaccacc
    cout << s.decodeString("3[a2[c]]") << endl;

    // Should outout abcabccdcdcdef
    cout << s.decodeString("2[abc]3[cd]ef") << endl;

    // Should output "aabaabaabaabaabaabcd"
    cout << s.decodeString("2[3[2[a]b]]cd") << endl;
}
