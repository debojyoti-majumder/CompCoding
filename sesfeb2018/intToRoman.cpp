// Problem URL: https://leetcode.com/problems/integer-to-roman/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string>  _indexedStrings;        
    
public:
    Solution() {
        _indexedStrings.push_back("I");
        _indexedStrings.push_back("V");
        _indexedStrings.push_back("X");
        _indexedStrings.push_back("L");
        _indexedStrings.push_back("C");
        _indexedStrings.push_back("D");
        _indexedStrings.push_back("M");
    }

    string intToRoman(int num) {
        string romanString("");
        auto inputNumber = num;

        while( inputNumber > 0 ) {
        }   

        return romanString;
    }
};

int main() {
    Solution s;

    // Should output VI
    cout << s.intToRoman(6) << endl;

    // Should output XXXII
    cout << s.intToRoman(32) << endl;
    return 0;
}