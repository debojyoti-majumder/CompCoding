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
#include <map>

using namespace std;

class Solution {
private:
    map<size_t,int> _cache;

public:
    int rob(vector<int>& nums, size_t index = 0 ) {
        auto sz { nums.size() };
        if( index == 0 )    
            _cache.clear();
            
        // Base case
        if( index >= sz ) return 0;
        
        // DP table lookup
        auto it { _cache.find(index) };
        if( it != _cache.end() ) return it->second;

        // Calling recusrsively
        auto currentNotSelected { rob(nums, index + 1) };
        auto curentSelected { nums[index] + rob(nums, index + 2) };
        auto maxValue { max(currentNotSelected, curentSelected) };

        // Adding to the cache
        _cache.insert(make_pair(index, maxValue));
        return maxValue;
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
