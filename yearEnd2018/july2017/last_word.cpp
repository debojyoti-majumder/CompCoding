// Problem URL: https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        bool space_found = false;
        bool start_count = false;
        for( auto ch=s.end()-1; ch >= s.begin(); ch-- ) {
            if(*ch != ' ')
                start_count = true;
            
            if( start_count ) {
                counter++;
                
                // Found my last word
                if( *ch == ' ' ) {
                    space_found = true;
                    break;
                }
            }
        }
        
        
        return space_found ? counter - 1 : counter;
    }
};
