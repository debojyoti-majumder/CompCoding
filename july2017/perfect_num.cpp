// Problem url: https://leetcode.com/problems/perfect-number/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> getfactors(int num) {
        vector<int> factors;

        for( int i=1; i<num; i++ ) {
            if( num % i == 0 )
                factors.push_back(i);
        }

        return factors;
    }

    int get_sum(vector<int> nums) {
        int sum = 0;
        for(auto m : nums)
            sum += m;
        
        return sum;
    }
public:
    bool checkPerfectNumber(int num) {
        auto factors = getfactors(num);
        auto sum = get_sum(factors);

        if( sum == num )
            return true;
        else
            return false;      
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
    return 0;
}
