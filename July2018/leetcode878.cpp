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

        _magicalNumbers.push_back(smaller);
        _magicalNumbers.push_back(bigger);

        for( auto i=0; i<N; i++ ) {
            auto item_1 = _magicalNumbers[i] * smaller;
            auto item_2 = _magicalNumbers[i] * bigger;

            bool isItem1Added = false;
            if( item_1 != _magicalNumbers[i + 1] ) {
                isItem1Added = true;
                _magicalNumbers.push_back(item_1);
            }

            if( isItem1Added ) {
                _magicalNumbers.push_back(item_2);
            }
            else {
                if( _magicalNumbers[i + 1] != item_2 )
                    _magicalNumbers.push_back(item_2);
            }
        } 

        return _magicalNumbers[N -1];
    }
};

int main(int, char**) {
    Solution s;

    cout << s.nthMagicalNumber(4, 2, 3) << " ";     // Should output 6
    cout << s.nthMagicalNumber(3, 6, 4) << " ";     // Should output 8
    cout << s.nthMagicalNumber(5, 2, 4 ) <<  endl;  // Should output 10

    return 0;
}
