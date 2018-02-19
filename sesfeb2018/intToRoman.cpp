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
        _indexedStrings.push_back("II");
        _indexedStrings.push_back("III");
        _indexedStrings.push_back("VI");
        _indexedStrings.push_back("V");
        _indexedStrings.push_back("VI");
        _indexedStrings.push_back("VII");
        _indexedStrings.push_back("VIII");
        _indexedStrings.push_back("IX");
    }

    string intToRoman(int num) {
        string romanString("");
        auto inputNumber = num;

        while( inputNumber > 0 ) {
            if( inputNumber > 10 ) {
                romanString += "X";
                inputNumber -= 10;
            }
            else {
                romanString += _indexedStrings[ inputNumber - 1];
                inputNumber = 0;
            }
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