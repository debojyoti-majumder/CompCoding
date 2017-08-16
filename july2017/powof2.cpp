// Problem url: https://leetcode.com/problems/power-of-two/description/

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> binary_represntation(n);

        if( binary_represntation.count() == 1 ) {
            // If only the sign bit is on then it's not power of two
            if( binary_represntation[31] )
                return false;
            else
                return true;        
        }
        else
            return false;
    }
};

int main() {
    Solution s;
    
    // Should return true
    cout << s.isPowerOfTwo(32) << endl;
    
    // Should return false
    cout << s.isPowerOfTwo(49) << endl;

    // Failed this test case
    cout << s.isPowerOfTwo(-2147483648) << endl;

    return 0;
}
