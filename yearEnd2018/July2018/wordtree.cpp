// Problem URL: https://leetcode.com/problems/word-ladder/description/
// Design a BFS engine/library to do state finding

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>
#include <chrono>

using namespace std::chrono;
using namespace std;

class Solution {
private:
    deque<pair<string,int>> _searchQueue;        
    vector<string>          _wordList;
    vector<string>          _excelude;
    vector<int>             _pos;

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

    void addIfNotpresent(const pair<string,int>& item) {
        bool bFound = false;

        for(auto sh : _excelude ) {
            if( sh.compare(item.first) == 0 ) {
                bFound = true;
                break;
            }
        }

        if( bFound == false )
            _searchQueue.push_back(item);
    }

    void addItemsToQueue(pair<string,int> queueItem, string endWord) {
        int i = -1;

        for(auto sz : _pos ) {
            auto str = queueItem.first;
            
            // This lookfor possible solutions
            if( str[sz] != endWord[sz] ) {
                auto candidateItems = getPossibleWords(sz, str);
                for( auto item : candidateItems ) {
                    pair<string,int> seachItem;
                    
                    // Adding the item in the queue
                    seachItem.first = item;
                    seachItem.second = queueItem.second + 1;
                    addIfNotpresent(seachItem);
                }
            }
            else {
                i = sz;
            }
        }

        if( i != -1 ) {
            auto p = find(_pos.begin(), _pos.end(), i);
            _pos.erase(p);
        }
    }

public:
    int ladderLength(string beginWord, string endWord, const vector<string>& wordList) {
        pair<string,int> beginState(beginWord, 1);
        _wordList = wordList;
        _searchQueue.push_back(beginState);

        for( auto sz=0; sz<endWord.size(); sz++ )
            _pos.push_back(sz);

        while( !_searchQueue.empty() ) {
            auto m = _searchQueue.front();
            _excelude.push_back(m.first);

            if( m.first.compare(endWord) == 0 )
                return m.second;
            
            _searchQueue.pop_front();
            addItemsToQueue(m,endWord);
        }

        return 0;
    }
};

int main() {
	Solution s1, s2, s3, s4, s5, s6, s7, s8;
    Solution s9;
	auto start = high_resolution_clock :: now();

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
    vector<string> bigWc {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
	vector<string> reds{"ted","tex","red","tax","tad","den","rex","pee"};

    cout << s1.ladderLength("hit", "cog", wordList) << ",";		// Should output 5
	cout << s2.ladderLength("hit", "cog", wordlList2) << ",";		// Should output 0
	cout << s3.ladderLength("a","c", wc3) << ",";                  // Should output 2          
    cout << s4.ladderLength("bim","fot",wc4) << ",";               // Should output 5, test case created by me
    cout << s5.ladderLength("hot","dog", wc5) << ",";              // Should output 0
    cout << s6.ladderLength("abc", "xyz", wc6) << ",";
    cout << s7.ladderLength("qa","sq", wc) << ",";                 // Getting time limit
	cout << s8.ladderLength("cet","ism", wc) << ",";
    cout << s9.ladderLength("red","tax",reds) << endl;              // Should return 4

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;
    return 0;
}
