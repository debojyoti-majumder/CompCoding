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
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        size_t sz = nums.size();
        int robbedAmount { 0 };
        
        // Covering all the base cases
        if( sz == 0 ) return 0;
        else if( sz == 1 ) return nums[0];
        else if( sz == 2 ) return nums[0] > nums[1] ? nums[0] : nums[1];

        // Size of the array is atleast 3
        auto cost1 { nums[0] + nums[2] };
        auto cost2 { nums[1] };
        // This is also a base case
        if(sz == 3) return max(cost1, cost2);

        cost2 += nums[3];                   // For the mask 0101
        auto cost3 { nums[0] + nums[3] };   // For mask 1001   
        nums.erase(nums.begin(), nums.begin() + 4);
        
        auto maxProfit { max({ cost1, cost2, cost3 }) };
        auto is4thElemeSelected{ (maxProfit == cost2 || maxProfit == cost3) };
        if( is4thElemeSelected && sz > 4 )
            nums.erase(nums.begin());
            
        return maxProfit + rob(nums);
    }
};

int main() {
    vector<int> test1{1,2,3,1};
    vector<int> test2{2,7,9,3,1};
    vector<int> randomInput {1,2,3,1,8,7,2,2,3,8,9};
    vector<int> tleTestCase {   155,44,52,58,250,225,109,118,211,73,137,96,137,89,174,66,134,26,25,205,239,85,
                                146,73,55,6,122,196,128,50,61,230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,212,241,
                                242,157,79,133,66,36,165 };
    vector<int> tricky{ 9,2,2,9,0,0,9 };
    Solution s;

    // Should output 4
    cout << s.rob(test1) << endl;

    // Should output 12
    cout << s.rob(test2) << endl;

    // Should output 26
    cout << s.rob(randomInput) << endl;
    
    // Should output 27
    cout << s.rob(tricky) << endl;
    
    // Getting TLE error, correct output 4517
    cout << s.rob(tleTestCase) << endl;
    return 0;
}
