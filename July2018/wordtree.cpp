// Problem URL: https://leetcode.com/problems/word-ladder/description/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
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
    int ladderLength(   string beginWord, 
                        string endWord, 
                        const vector<string>& wordList, 
                        vector<string> solutionPath = {},
                        int statckCount = 0) {
        // Base case
        if( beginWord.compare(endWord) == 0 )
            return 1;

        // This value is used to return the end distance value
        statckCount++;
        
        // If endword is not present in the list no solution is possible
        auto endItem = find(wordList.begin(), wordList.end(), endWord);
        if( endItem == wordList.end() )
            return 0;

        vector<string> solutionCnadidates;
        vector<int> editValues;

        // Iterating through each letter
        for(auto sz=0; sz<beginWord.size(); sz++ ) {
            auto possibleEdits = getPossibleWords(sz,wordList,beginWord);
            for( auto item : possibleEdits )
                solutionCnadidates.push_back(item);
        }

        cout << "Stack: " << statckCount << " " << beginWord << "[";
        for( auto sol : solutionCnadidates ) {
            auto it = find(solutionPath.begin(), solutionPath.end(), sol);
            if( it == solutionPath.end() )
                cout << sol << ",";
        }
        cout << "]" << endl;
        

        auto s = find(solutionCnadidates.begin(), solutionCnadidates.end(), endWord);
        if( s != solutionCnadidates.end() ) 
            return statckCount + 1;

        // Recursive call to find the cost
        for( auto sol : solutionCnadidates ) {
            auto it = find(solutionPath.begin(), solutionPath.end(), sol);
            
            // Have to look for new solution always
            if( it == solutionPath.end() ) {
                solutionPath.push_back(sol);
                auto v = ladderLength(sol, endWord, wordList, solutionPath, statckCount);
                editValues.push_back(v);
            }
        }

        // This seems to be buggy
		auto it = min_element(editValues.begin(), editValues.end());
        if( it != editValues.end() )
            return (*it);
        else
            return 0;
    }
};

int main() {
	Solution s1, s2, s3, s4;
	
	vector<string> wordList{"hot","dot","dog","lot","log","cog"};
	vector<string> wordlList2{"hot","dot","dog","lot","log"};
	vector<string> wc3{"a", "b", "c"};
    	vector<string> wc4{"bim", "tim", "tom", "tot","fot","fit"};

	cout << s1.ladderLength("hit", "cog", wordList) << endl;		// Should output 5
	cout << s2.ladderLength("hit", "cog", wordlList2) << endl;		// Should output 0
	cout << s3.ladderLength("a","c", wc3) << endl;                  // Should output 2          
    	cout << s4.ladderLength("bim","fot",wc4) << endl;               // Should output 5, test case created by me

	return 0;
}
