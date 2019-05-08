/*  Problem URL:    https://leetcode.com/problems/delete-and-earn/
    Problem ID:     740
    Issue ID:       22
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Solution {
private:
    vector<int> getReducedList(const vector<int>& nums, size_t excludeIndex) {
        vector<int> reducedList;
        auto pickedNumber { nums[excludeIndex] };

        for( size_t i=0; i<nums.size(); i++ ) {
            auto n { nums[i] };

            // Don't add the number in that case
            if( n == pickedNumber + 1 || n == pickedNumber - 1 || i == excludeIndex ) {
                continue;
            }
            
            reducedList.emplace_back(n);
        }

        return reducedList;
    }

    // Recursive function that given us the cost value
    int getMaxPoint(vector<int>& nums, size_t selectIndex = 0 ) {
        size_t sz { nums.size() };

        // base cases 
        if( selectIndex >= sz  ) return 0;
        else if( sz == 1 ) return nums[0];

        // Case: Current index is part of the final solution
        auto reducedList { getReducedList(nums, selectIndex) };
        auto selectedCost { nums[selectIndex] + getMaxPoint(reducedList) };

        // Case: Current index is not part of the final solution
        auto startIndex { selectIndex + 1 };
        auto notSelectedCost { getMaxPoint(nums, startIndex) };

        return max(selectedCost, notSelectedCost);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        // Starting selection from the first item
        return getMaxPoint(nums);
    }
};

void testLeetcode740() {
    Solution s;
    
    vector<int> inp1{3,4,2};
    vector<int> inp2{2,2,3,3,3,4};
    vector<int> tleCase {1,8,5,9,6,9,4,1,7,3,3,6,3,3,8,2,6,3,2,2,1,2,9,8,7,1,1,10,6,7,3,9,6,10,5,4,10,1,6,7,4,7,4,1,9,5,1,5,7,5};
        
    // Should output 6
    cout << s.deleteAndEarn(inp1) << endl;
    
    // Should output 9
    cout << s.deleteAndEarn(inp2) << endl;

    // Should not get TLE, correct output 138
    cout << s.deleteAndEarn(tleCase) << endl;
}

int main() {
    testLeetcode740();
    return 0;
}
