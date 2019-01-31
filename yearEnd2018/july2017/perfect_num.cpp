// Problem url: https://leetcode.com/problems/perfect-number/description/
// Math help was required https://en.wikipedia.org/wiki/Perfect_number 
// used a formula to get the numbers

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {

public:
    bool checkPerfectNumber(int num) {
        bool is_perfect = false;
        vector<int> prime_list{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

        for( auto prime : prime_list ) {
            // This is the formula to get the perfect number
            int perfect_num = pow(2, prime - 1) * (pow(2,prime) - 1 );
            
            // Don't need to find anymore
            if( perfect_num > num )
                break;
            if( perfect_num == num ) {
                is_perfect = true;
                break;
            }
        }

        return is_perfect;
    }
};

int main() {
    Solution s;

    // Should return true because 28 = 2 + 4 + 7 + 14
    cout << s.checkPerfectNumber(28) << endl;

    // Should not work out
    cout << s.checkPerfectNumber(33) << endl;

    // Should not work out
    cout << s.checkPerfectNumber(1) << endl;

    // Big test cases
    cout << s.checkPerfectNumber(99999992) << endl;
    cout << s.checkPerfectNumber(99999993) << endl;
    cout << s.checkPerfectNumber(99999998) << endl;

    return 0;
}
