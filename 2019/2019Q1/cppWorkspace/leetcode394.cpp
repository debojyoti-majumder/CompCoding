/*
    Problem URL:    https://leetcode.com/problems/decode-string/description/
    Problem Id:     394
    Issue Id        30

    Comments:       Have tried iterative method, seems best to use recusion

    Related Questions:
        https://leetcode.com/problems/number-of-atoms/
        
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    string decodeString(const string &inputString) {
        string returnValue;
        int braceCount { 0 };
        int repCount = 1;
        string subString{""};
        string repString{""};

        // base case
        if( inputString.length() == 0 ) return "";

        for( size_t i=0; i<inputString.size(); i++ ) {
            if( isdigit(inputString[i]) ) {
                if( braceCount == 0 ) {
                    repString += inputString[i];            
                    subString = "";
                }
                else {
                    subString += inputString[i];
                }
            }
            else if( inputString[i] == '[' ) {
                if( braceCount != 0 ) 
                    subString += '[';
                else {
                    if( repString.length() ) {
                        repCount = atoi(repString.c_str());
                        repString = "";
                    }
                }
                braceCount++;
            }
            else if( inputString[i] == ']' ) {
                braceCount--;

                if( braceCount == 0 ) {
                    auto ret = decodeString(subString);
                    for( int i=0; i<repCount; i++ )
                        returnValue += ret;

                    subString = "";
                    repCount = 1;
                }
                else {
                    subString += ']';
                }
            }
            else {
                if( braceCount )
                    subString+= inputString[i];
                else 
                    returnValue += inputString[i];
            }
        }

        auto sub { decodeString(subString) };
        for(int i=0; i<repCount; i++) returnValue += sub;
        return returnValue;
    }
};

int main()
{
    Solution s;

    // Should output aaabcbc
    cout << s.decodeString("3[a]2[bc]") << endl;

    // Should output accaccacc
    cout << s.decodeString("3[a2[c]]") << endl;

    // Should outout abcabccdcdcdef
    cout << s.decodeString("2[abc]3[cd]ef") << endl;

    // Should output abcbcabcbcabcbc
    cout << s.decodeString("3[[a2[bc]]") << endl;

    cout << s.decodeString("10[deb]") << endl;
}
