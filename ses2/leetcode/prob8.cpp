// Problem URL: https://leetcode.com/problems/h-index-ii/description/

#include <iostream>
#include "helperFunc.hpp"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        return 0;        
    }
};

int main(int, char**) {
    vector<int> p{0,1,3,5,6};
    Solution s;

    // Output should be 3
    printVectorItems(p);
    cout << s.hIndex(p) << endl;
    return 0;
}
