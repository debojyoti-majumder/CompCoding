// Problem URL: https://leetcode.com/problems/expressive-words/

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// This can be replaced by a vector also
typedef map<char,int> CharMap;

class Solution {
private:
    CharMap getCharMap(string s) {
        CharMap charMap;
        
        // Empty string won't be having map
        if( s.length() == 0 ) {
            return charMap;
        }

        char prevCh = s[0];
        int currentCounter = 1;

        for( size_t i=1; i<s.length(); i++ ) {
            auto ch {s[i]};
            
            if( ch != prevCh ) {
                charMap.insert(make_pair(prevCh, currentCounter));
                prevCh = ch;
                currentCounter = 1;
            } else {
                currentCounter++;
            }
        }

        // This is for the last character
        charMap.insert(make_pair(prevCh, currentCounter));
        return charMap;
    }

    bool compareCharMap(const CharMap& lhs, const CharMap& rhs) {
        // If sizes are not same then they are not going to be comapred 
        auto sz = lhs.size();
        if( sz != rhs.size() ) {
            return false;
        }

        // Going through each letter
        for(const auto& item : lhs ) {
            auto it = rhs.find(item.first);
            if( it == rhs.end() ) {
                return false;
            }

            int sourceCount = item.second;
            int targetCount = it->second;
            
            if( sourceCount > 2 ) {
                continue;
            }

            if( sourceCount != targetCount )
                return false;
        }

        return true;
    }

public:
    int expressiveWords(string S, vector<string>& words) {
        auto sourceStrMap { getCharMap(S) };
        int compareCounter = 0;

        for(const auto& word: words) {
            auto wordMap{ getCharMap(word)};
            
            if( compareCharMap(sourceStrMap, wordMap) ) {
                compareCounter += 1;
            } 
        }

        return compareCounter;        
    }
};

int main() {
    string inputWord{"heeeeeellloooo"};
    vector<string> possibleMatch{"hello", "hi", "helo"};

    Solution s;
    cout << s.expressiveWords(inputWord, possibleMatch) << endl;

    return 0;
}
