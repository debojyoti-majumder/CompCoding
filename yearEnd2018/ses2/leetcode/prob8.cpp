// Problem URL: https://leetcode.com/problems/h-index-ii/description/

#include <iostream>
#include "helperFunc.hpp"
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> reversed(citations);
        reverse(reversed.begin(), reversed.end());
        int hIndex = 0;

        for(auto i=0; i<=reversed.size(); i++) {
            auto minValue = min(reversed[i], i+1);
            if( minValue > hIndex )
                hIndex = minValue;
        }
        
        return hIndex;        
    }
};

int main(int, char**) {
    vector<int> p{0,1,3,5,6};
    Solution s;

    // Output should be 3
    cout << s.hIndex(p) << endl;

    // Output should be 5
    vector<int> x{3,4,5,8,10};
    cout << s.hIndex(x) << endl;

    vector<int> pp{1};
    cout << s.hIndex(pp) << endl;

    vector<int> testCase4{1,1};
    cout << s.hIndex(testCase4) << endl;
    
    return 0;
}
