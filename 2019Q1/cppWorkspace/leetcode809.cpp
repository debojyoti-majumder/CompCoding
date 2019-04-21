// Problem URL: https://leetcode.com/problems/expressive-words/
// Map is incorrect container to choose, to be fixed

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef vector<pair<char,int>> CharSequence;

class Solution {
private:
    CharSequence getCharSequence(const string& str) {
        CharSequence seq;

        return seq;
    }

    bool compareCharSequence(const CharSequence& source, const CharSequence& target) {
        return true;
    }

public:
    int expressiveWords(string S, vector<string>& words) {
        auto sourceSequence{ getCharSequence(S) };
        int matchCounter = 0;

        for(const auto& word : words) {
            auto targetSequence { getCharSequence(word) };
            if( compareCharSequence(sourceSequence, targetSequence) == 0 )
                matchCounter++;
        }

        return matchCounter;
    }
};

int main() {
    string inputWord{"heeeeeellloooo"};
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
