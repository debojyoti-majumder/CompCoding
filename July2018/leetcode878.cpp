// Problem URL: https://leetcode.com/problems/nth-magical-number/description/

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
private:
    vector<int> _magicalNumbers;

public:
    int nthMagicalNumber(int N, int A, int B) {
        auto smaller(A);
        auto bigger(B);
        _magicalNumbers.clear();
        
        if( A > B ) {
            smaller = B;
            bigger = A;
        }

        if( bigger % smaller == 0 ) 
            return smaller * N;

        return 0;
    }
};

int main(int, char**) {
    Solution s;

    cout << s.nthMagicalNumber(4, 2, 3) << " ";     // Should output 6
    cout << s.nthMagicalNumber(3, 6, 4) << " ";     // Should output 8
    cout << s.nthMagicalNumber(5, 2, 4 ) <<  endl;  // Should output 10

    return 0;
}
