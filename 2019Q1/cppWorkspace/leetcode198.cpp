/*
Issue link:     https://github.com/debojyoti-majumder/CompCoding/issues/18
Problem URL:    https://leetcode.com/problems/house-robber/
Leetcode ID:    198 

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
        size_t sz = nums.size();

        // Covering all the base cases
        if( sz == 0 ) return 0;
        else if( sz == 1 ) return nums[0];
        else if( sz == 2 ) return nums[0] > nums[1] ? nums[0] : nums[1];

        // This means the array size is at least 3
        auto firstItem { nums[0] };
        auto secondItem { nums[1] };

        // Robbing the first house
        nums.erase(nums.begin());
        nums.erase(nums.begin());

        auto arrCopy{nums};            
        auto cost1 = firstItem + rob(arrCopy);

        // Robbing the second house
        nums.erase(nums.begin());
        auto arrCopy2{nums};
        auto cost2 = secondItem + rob(arrCopy2);
        
        return cost1 > cost2 ? cost1 : cost2;
    }
};

int main() {
    vector<int> test1{1,2,3,1};
    vector<int> test2{2,7,9,3,1};
    vector<int> tleTestCase {   155,44,52,58,250,225,109,118,211,73,137,96,137,89,174,66,134,26,25,205,239,85,
                                146,73,55,6,122,196,128,50,61,230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,212,241,
                                242,157,79,133,66,36,165 };
    Solution s;

    // Should output 4
    cout << s.rob(test1) << endl;

    // Should output 12
    cout << s.rob(test2) << endl;

    // Getting TLE error, correct output 4517
    cout << s.rob(tleTestCase) << endl;
    return 0;
}
