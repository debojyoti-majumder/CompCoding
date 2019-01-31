#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        bool is_circle = false;
        int initial_x_pos = 0;
        int initial_y_pos = 0;
        
        for( auto action:moves ) {
            switch(action) {
                case 'U':
                    initial_y_pos -= 1;
                    break;
                case 'D':
                    initial_y_pos += 1;
                    break;
                case 'L':
                    initial_x_pos -= 1;
                    break;
                case 'R':
                    initial_x_pos += 1;
                    break;
            }
        
        }
        
        if( initial_x_pos == 0 && initial_y_pos == 0 )
            return true;
        else
            return false;
    }
};

int main() {
    Solution s;

    // Should output true
    cout << s.judgeCircle("UD") << endl;    

    // Should output false
    cout << s.judgeCircle("LL") << endl;

    cout << s.judgeCircle("LLLRRUDUDRUU") << endl;
    cout << s.judgeCircle("LLRRUUDDLRUD") << endl;

    return 0;
}
