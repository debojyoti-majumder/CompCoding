// Problem Url: https://leetcode.com/problems/contains-duplicate-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        return true;      
    }
};

int main() {
    Solution s;
    vector<int> v{10,20,30,40,10,20};

    // Test case 1: Should return true
    cout << s.containsNearbyDuplicate(v,5) << endl;
    
    // Test case 2: Should return false
    cout << s.containsNearbyDuplicate(v,2) << endl;

    return 0;
}