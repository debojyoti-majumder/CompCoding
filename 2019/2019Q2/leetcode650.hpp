// Problem URL: https://leetcode.com/problems/2-keys-keyboard/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<int, int> _returnValueCache;
    
public:
    Solution() {
        // Adding the base cases
        _returnValueCache.insert(make_pair(1, 0));
        _returnValueCache.insert(make_pair(2, 2));
    }

    int minSteps(int n, int currentClipLength = 1) {
        vector<int> numberOfOpps;
        numberOfOpps.emplace_back(n);

        // First doing cache lookup
        auto it = _returnValueCache.find(n);
        if (it != _returnValueCache.end()) {
            return it->second;
        }

        for ( int i = 2; i < n - 1; i++ ) {
            if (n % i == 0) {
                // Using recursion
                int subProblem = n / i;
                int res = minSteps(subProblem);

                // Adding a potential result
                numberOfOpps.emplace_back(i + res);
            }
        }

        // This array will always have one element hence no need to check for dereference
        auto retValue{ min_element(numberOfOpps.begin(), numberOfOpps.end()) };
        _returnValueCache.insert(make_pair(n, *retValue));

        return *retValue;
    }
};

int main() {
    Solution s;
    
    // Should output 3
    cout << s.minSteps(3) << endl;
   
    // Should output 20
    cout << s.minSteps(51) << endl;
    return 0;
}
