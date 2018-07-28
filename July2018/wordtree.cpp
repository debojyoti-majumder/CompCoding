// Problem URL: https://leetcode.com/problems/word-ladder/description/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<string> _solutionPath;

    set<string> getPossibleWords(size_t pos, const vector<string>& wordList, const string& beginWord) {
        set<string> retValue;
        
        for( auto item : wordList ) {
            if( item[pos] != beginWord[pos] ) {
                auto tmpWord = beginWord;
                tmpWord[pos] = item[pos];

                auto dictItem = find(wordList.begin(), wordList.end(), tmpWord);
                if( dictItem != wordList.end() ) 
                    retValue.insert(tmpWord);
            }
        }

        return retValue;
    }

public:
    int ladderLength(string beginWord, string endWord, const vector<string>& wordList) {
        cout << beginWord << "--> ";
        
        // Base case
        if( beginWord.compare(endWord) == 0 )
            return 0;

        vector<string> solutionCnadidates;
        vector<int> editValues;

        // Iterating through each letter
        for(auto sz=0; sz<beginWord.size(); sz++ ) {
            auto possibleEdits = getPossibleWords(sz,wordList,beginWord);
            for( auto item : possibleEdits )
                solutionCnadidates.push_back(item);
        }

        // Recursive call to find the cost
        for( auto sol : solutionCnadidates ) {
            auto it = find(_solutionPath.begin(), _solutionPath.end(), sol);
            
            // Have to look for new solution always
            if( it == _solutionPath.end() ) {
                _solutionPath.push_back(sol);
                editValues.push_back(ladderLength(sol, endWord, wordList) + 1);
            }
        }

		auto it = min_element(editValues.begin(), editValues.end());
        if( it != editValues.end() )
            return *it;
        else
            return 0;
    }
};

int main() {
	Solution s1, s2;
	
	vector<string> wordList{"hot","dot","dog","lot","log","cog"};
	vector<string> wordlList2{"hot","dot","dog","lot","log"};
	
	cout << s1.ladderLength("hit", "cog", wordList) << endl;		// Should output 5
	cout << s2.ladderLength("hit", "cog", wordlList2) << endl;		// Should output 0
	
	return 0;
}
