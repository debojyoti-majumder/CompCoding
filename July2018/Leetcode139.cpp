// Problem Url: https://leetcode.com/problems/word-break/description/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        sort(wordDict.begin(), wordDict.end(), [] (string& s1, string s2) {
            return s1.length() < s2.length();
        });

        for(auto word : wordDict) {
            auto pos = s.find(word, 0);

            // TODO: To be replaced with recursion        
            while( pos != string::npos ) {
                s.erase(pos, word.length());
                pos = s.find(word, 0);
            } 
        }

        if( s.length() == 0 )
            return true;
        else
            return false;
    }
};

int main() {
    Solution s;
    vector<string> dict{"leet", "code"};
    vector<string> dct{"car","ca","rs"};
    
    // Should return true
    cout << s.wordBreak("leetcode", dict) << endl;

    // Should return true: This test case failing
    cout << s.wordBreak("cars", dct) << endl;

    // Failing test case, should be fixed with recursion
    vector<string> bb{"aaaa","aaa"};
    cout << s.wordBreak("aaaaaaa", bb) << endl; 

    return 0;
}
