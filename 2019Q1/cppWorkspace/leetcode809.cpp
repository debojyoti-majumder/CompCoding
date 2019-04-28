/*
Problem URL: https://leetcode.com/problems/expressive-words/

Related Problems: 
    a. https://leetcode.com/problems/regular-expression-matching/
    b. https://leetcode.com/problems/output-contest-matches/ ( Premium )
    c. https://leetcode.com/problems/ambiguous-coordinates/

TODO:
    This problem can be optimized by not building the all the character frequency.
    We have to compare the char count simultaniously
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<pair<char,int>> CharSequence;

class Solution {
private:
    CharSequence getCharSequence(const string& str) {
        CharSequence seq;
        auto len { str.length() };

        // Return empty sequence for empty string
        if( len == 0 )
            return seq;

        char prevChar = str[0];
        int counter = 1;
        
        for(size_t i=1; i<len; i++) {
            if( prevChar != str[i] ) {
                seq.emplace_back(pair<char,int>{prevChar, counter});
                prevChar = str[i];
                counter = 1;
            }
            else {
                counter++;
            }
        }

        seq.emplace_back(pair<char,int>{prevChar,counter});
        return seq;
    }

    bool compareCharSequence(const CharSequence& source, const CharSequence& target) {
        auto sourceLength { source.size() };
        auto targetLength { target.size() };

        if( sourceLength != targetLength )
            return false;

        for( size_t i=0; i<sourceLength; i++ ) {
            // "first" is the character that we are comparing
            if( source[i].first == target[i].first ) {
                if( (source[i].second < 3 && source[i].second != target[i].second) 
                    || target[i].second > source[i].second ) { 
                    return false;
                }
            }
            else {
                return false;
            }
        }   

        return true;
    }

public:
    int expressiveWords(string S, vector<string>& words) {
        auto sourceSequence{ getCharSequence(S) };
        int matchCounter = 0;

        for(const auto& word : words) {
            auto targetSequence { getCharSequence(word) };
            if( compareCharSequence(sourceSequence, targetSequence) )
                matchCounter++;
        }

        return matchCounter;
    }
};

int main() {
    string inputWord{"heeeeeelloooo"};
    vector<string> possibleMatch{"hello", "hi", "helo"};

    
    Solution s;
    cout << s.expressiveWords(inputWord, possibleMatch) << endl;
    
    // Should output zero
    string testWord{"aaa"};
    vector<string> match{"aaaa"};
    cout << s.expressiveWords(testWord, match) << endl;
    
    string test2{"vvvppppeeezzzzztttttkkkkkkugggggbbffffffywwwwwwbbbccccddddddkkkkksssppppddpzzzzzhhhhbbbbbmmmy"};
    vector<string> match2{
                "vvpeezttkkuggbbfywwbbccddkkspdpzhbbmmyy",
                "vvppeeztkkugbfywwbccddkksspdppzhhbmyy",
                "vppezzttkkugbffyywbccddksspddpzhhbmy",
                "vvppezztkugbffyywwbbccddkssppddpzzhhbbmmy",
                "vvppezttkuggbfyywwbbcddkspdppzhhbmy",
                "vppeezzttkkuugbfyywwbbccdkkssppdpzzhbbmy",
                "vpeezztkkugbbffyywwbbccddkksppdpzzhhbbmmy",
                "vppeeztkkuuggbffywbbccddkksppdppzhhbmyy",
                "vpeeztkkuggbfyywbbccdksppdpzhbmy",
                "vpeezztkkugbffywwbbccdkkssppddppzzhhbbmmy",
                "vvpeztkkugbbfyywbcdkssppddpzzhhbbmyy",
                "vpezztkugbbffyywwbcddksppddpzzhbbmy",
                "vvpeezztkkugbbffywwbccdkkspddpzzhbmmyy",
                "vvpeezzttkkuuggbbffyywbbccdkspdppzhhbmy",
                "vvppeezztkkuggbbfywbcdkspdpzhhbmyy",
                "vvppeezzttkkuugbffyywwbbccddkkspddpzzhbmyy",
                "vppezztkuuggbffywwbcdksspdppzhhbmyy",
                "vvppeezzttkuuggbffywbccddkksspddppzzhhbmmy",
                "vvppezzttkuggbffywbbccdkspddppzzhhbmy",
                "vvpezzttkuugbbfywwbccdkssppdpzhbbmmy",
                "vvpeezzttkuugbbffyywbccdksppddppzhhbmyy",
                "vpeezzttkkuggbbffywbccddksppddpzhhbbmy",
                "vvpezttkuuggbffywwbbccddkspdppzhhbmmyy",
                "vppeezzttkkuugbffywbccddksppddpzhhbmmyy",
                "vvpezttkkuugbbfywbccdkspddppzzhbbmmy",
                "vppezzttkkuugbbffywwbcddkssppddpzhhbmmy",
                "vppezzttkugbfywbbcdksppddppzzhhbmyy",
                "vppeeztkuggbbffywbbccdkkspddppzzhbbmmy",
                "vvpeeztkuuggbbfywbcdkksspddppzhhbbmmyy","vpezttkkuuggbbffyywwbbcdksspddppzhhbmy","vpeezzttkkuuggbffywwbccdkksspddppzzhbmyy","vpezttkkuugbffyywbccdksspddppzhbbmmyy","vvppezztkugbbffyywbbccdkksppdppzhbmyy","vvpeezttkuggbbfyywwbbcddkksppdpzzhbbmyy","vvpeztkuuggbffyywbbccdkksspddppzzhbbmy","vppeezzttkugbbffyywbccddksppdppzzhbmmyy","vppeezttkkuugbbfywwbccddkksspdpzhhbmmy","vpeezzttkugbbffywbbccdkksspddppzhbbmyy","vpeezttkkuugbbfywbbccddksppddppzzhhbmmy","vpeezztkuuggbbffywwbbccddksspddpzzhhbbmmyy","vppeezttkkuggbbffyywwbccdksspdpzzhbmy","vpezzttkkuugbbfyywbbcdksspdppzzhbbmyy","vvppezttkkuggbbfyywbbccdkksspddpzhbbmyy","vvpezzttkuggbbffyywbbcdkksppdpzzhbmmyy","vvpeztkugbfywwbccddkkspddpzhhbbmyy","vvppezttkuugbbfyywwbcddkksspdppzhhbbmy","vvpeeztkkuuggbbfywwbcdkspddpzzhhbmmy","vvpeezttkugbffywbbccdkkssppddppzhhbbmyy","vpeztkuuggbbfyywwbcddksppddpzhbbmy","vppeztkuggbbfyywbcdksspdppzzhhbmy","vppeezttkkugbbffyywbccddkksppdpzhhbmy","vvppeeztkugbfyywbcdkksppdppzhbmyy","vpezttkuugbbffywbcdksppddpzzhhbbmmy","vppezzttkuugbfyywbcddkksspdpzhbbmmy","vppezzttkkuggbffywbbcdksspdpzzhhbbmmyy","vpezzttkuggbfyywbbccdksspdpzhhbbmmy","vvppezttkkugbffyywbcdkssppdpzzhbmy","vvpeezttkkuuggbbfyywbbccdkspdppzhhbmy","vpeezttkkuugbfywbccddkksppddpzzhhbmmy","vvppezttkuuggbbffywbbccdkksppdpzzhhbbmmy","vvppeeztkuggbbffyywbccdksspddppzzhbmmyy","vvppeezztkuggbfywwbccddkkspddpzhbbmy","vpezttkuuggbfyywwbcdkkspdpzhhbbmmyy","vppezzttkuggbffywbbcdkkssppddppzhhbmyy","vppeztkuuggbffyywbccdkkspdppzzhhbmmyy","vppeezztkuuggbfywbccddkksspddppzhhbbmyy","vvppeztkuugbfywwbccdkkspddppzzhhbmmy","vvpezztkuugbbffyywwbbccddksppdpzhbbmmyy","vvpezzttkkuuggbffyywwbbcdkspdpzhbmmyy","vvppeztkkuuggbbfyywbbccdksppdppzzhbmmyy","vvppezztkuggbffyywwbcddkkssppdpzhbmmyy","vvpezzttkkuggbbffywwbcddkksspdpzzhhbbmmy","vpezztkkuuggbfyywwbccddkssppdppzhhbbmmy","vvppezztkuugbffywwbccdkkspdppzhhbmmy","vpeztkugbfyywwbcdkksspdppzzhbmmy","vvpeezzttkkugbbfywwbcdkkspdpzzhhbmmy","vpezzttkuuggbbfywbccdkspddppzzhhbbmmy","vppeztkkuugbffyywwbbcddksspddppzhbbmyy","vpeztkkuggbffyywbbccddkssppdppzhbmyy","vvppeezztkuggbffyywwbcddkksppdppzhbmyy","vpeezztkugbfyywbbccdkkspdppzhbmmyy","vvppeezttkugbfywwbcddkkssppdppzhbmmyy","vpeeztkuggbffywwbbccddksspdppzzhhbmmy","vvppeeztkuugbfywbcddkssppddppzzhhbbmyy","vpezzttkuggbbffyywwbbccdkssppddppzhbbmy","vpezttkugbfywbbcddkksspddppzhbbmy","vpeezzttkkuggbbffyywwbccddkspddppzhbmyy","vppeezzttkugbffywbccdkkspddpzhhbbmyy","vpezzttkuggbbfyywbbccdkksspddpzzhhbmmy","vvppezttkugbfywwbbcdkksspddpzzhhbbmyy","vppezztkkuggbffyywbcddkkssppddpzzhhbbmmy","vppeztkkuggbfywwbccdkksppdppzhhbmmy","vvpeezzttkugbffyywwbbcddkssppddpzzhbmmy","vvpezztkkuuggbfyywbccdkksspddpzhhbbmyy","vpezttkuuggbffywbbccdksppdpzhbmmyy","vvpezzttkuggbbfywbccddksspdpzzhhbmmy","vvpeezzttkkugbbfywwbcdkksppddpzhbmy","vppeezttkkuugbbfyywwbcddkkspdpzhhbbmmyy",
                "vvppeeztkkuugbbfyywwbbcddkksspdppzhbbmyy","vvpeezzttkkuugbfywwbbcddkspdpzzhbbmyy"};

    // Should output 2
    cout << s.expressiveWords(test2, match2) << endl;
    return 0;
}
