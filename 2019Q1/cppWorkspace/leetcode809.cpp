// Problem URL: https://leetcode.com/problems/expressive-words/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        return 0;        
    }
};

int main() {
    string inputWord{"heeeeeellloooo"};
    vector<string> possibleMatch{"hello," "hi", "helo"};

    Solution s;
    cout << s.expressiveWords(inputWord, possibleMatch) << endl;

    return 0;
}
