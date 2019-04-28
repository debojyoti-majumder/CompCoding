/*
Issue link: https://github.com/debojyoti-majumder/CompCoding/issues/18
Problem URL: https://leetcode.com/problems/house-robber/

Related Problems:
    a. https://leetcode.com/problems/house-robber-ii/
    b. https://leetcode.com/problems/house-robber-iii/
    c. https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        return 0;        
    }
};

int main() {
    vector<int> test1{1,2,3,1};
    vector<int> test2{2,7,9,3,1};
    Solution s;

    // Should output 4
    cout << s.rob(test1) << endl;

    // Should output 12
    cout << s.rob(test2) << endl;
    return 0;
}
