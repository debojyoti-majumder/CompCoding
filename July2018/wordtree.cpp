// Problem URL: https://leetcode.com/problems/word-ladder/description/
// TODO: Implement bfs for this problem
// Design a BFS engine/library to do state finding

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    queue<pair<string,int>> _searchQueue;        
    vector<string>          _wordList;

    set<string> getPossibleWords(size_t pos, const string& beginWord) {
        set<string> retValue;
        
        for( auto item : _wordList ) {
            if( item[pos] != beginWord[pos] ) {
                auto tmpWord = beginWord;
                tmpWord[pos] = item[pos];

                auto dictItem = find(_wordList.begin(), _wordList.end(), tmpWord);
                if( dictItem != _wordList.end() ) 
                    retValue.insert(tmpWord);
            }
        }
        return retValue;
    }

    void addItemsToQueue(pair<string,int> queueItem, string endWord) {
        for(auto sz=0; sz<endWord.size(); sz++ ) {
            auto str = queueItem.first;
            
            // This lookfor possible solutions
            if( str[sz] != endWord[sz] ) {
                auto candidateItems = getPossibleWords(sz, str);
                for( auto item : candidateItems ) {
                    pair<string,int> seachItem;
                    
                    // Adding the item in the queue
                    seachItem.first = item;
                    seachItem.second = queueItem.second + 1;
                    _searchQueue.push(seachItem);
                }
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, const vector<string>& wordList) {
        pair<string,int> beginState(beginWord, 1);
        _wordList = wordList;
        _searchQueue.push(beginState);

        while( !_searchQueue.empty() ) {
            auto m = _searchQueue.front();
            if( m.first.compare(endWord) == 0 )
                return m.second;

            _searchQueue.pop();
            addItemsToQueue(m,endWord);
        }

        return 0;
    }
};

int main() {
	Solution s1, s2, s3, s4, s5, s6, s7;
	
	vector<string> wordList{"hot","dot","dog","lot","log","cog"};
	vector<string> wordlList2{"hot","dot","dog","lot","log"};
	vector<string> wc3{"a", "b", "c"};
    vector<string> wc4{"bim", "tim", "tom", "tot","fot","fit"};
    vector<string> wc5{"hot","dog"};
    vector<string> wc6{"abc", "xyz", "ayz"};
    vector<string> wc {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba",
 "to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th",
 "pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io",
 "be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	cout << s1.ladderLength("hit", "cog", wordList) << endl;		// Should output 5
	cout << s2.ladderLength("hit", "cog", wordlList2) << endl;		// Should output 0
	cout << s3.ladderLength("a","c", wc3) << endl;                  // Should output 2          
    cout << s4.ladderLength("bim","fot",wc4) << endl;               // Should output 5, test case created by me
    cout << s5.ladderLength("hot","dog", wc5) << endl;              // Should output 0
    cout << s6.ladderLength("abc", "xyz", wc6) << endl;
    cout << s7.ladderLength("qa","sq", wc) << endl;                 // Getting time limit
	return 0;
}
