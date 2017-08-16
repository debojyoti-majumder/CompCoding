// Problem description: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// solution should run in O(log n) time and O(1) space.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Remove the const while submitting the solution
    int singleNonDuplicate(const vector<int>& nums) {
        return 0;        
    }
};

int main() {
    Solution s;

    // Output: 2
    cout << s.singleNonDuplicate(vector<int>{1,1,2,3,3,4,4,8,8}) << endl;
    
    // Output: 10
    cout << s.singleNonDuplicate(vector<int>{3,3,7,7,10,11,11}) << endl;
    
    return 0;
}
