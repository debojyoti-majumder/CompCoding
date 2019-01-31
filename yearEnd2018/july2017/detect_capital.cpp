// Problem url: https://leetcode.com/problems/detect-capital/description/

#include <cctype>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // Base case, avoiding crashes 
        if(word.length() == 0 ) 
            return true;
        
        bool is_first_big = isupper(word[0]);
        int counter = 1;
        
        for(int i=1; i<word.size(); i++) {
            bool b = isupper(word[i]);
            
            // If any big letter is found
            if( b == is_first_big )
                counter++;
        }
        
        // This is for the first letter big
        if( is_first_big && counter == 1 )
            return true;
        
        // This is for all small of all big
        if( counter == word.size() )
            return true;
        else 
            return false;
    }
};
