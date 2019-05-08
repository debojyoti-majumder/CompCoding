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
    map<string,int> _cache;

    string stringfy(const vector<int>& nums) {
        stringstream ss;
        
        for( const auto& num : nums ) {
            ss << num << " ";
        }
        
        return ss.str();        
    }

    vector<int> getReducedList(const vector<int>& nums, int pickedNumber, size_t excludeIndex) {
        vector<int> reducedList;

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

    int getMaxPoint(vector<int>& nums) {
        size_t sz { nums.size() };

        // base cases 
        if( sz == 0 ) return 0;
        else if( sz == 1 ) return nums[0];

        // Representing the vector as string
        string strRepresentation { stringfy(nums) };
        vector<int> costs;

        // DP table lookup
        auto it = _cache.find(strRepresentation);
        if( it != _cache.end() ) return it->second;

        // Picking up one number, calulating the cost for the reduced list
        for( size_t i=0; i<nums.size(); i++ ) {
            auto number{ nums[i] };
            auto rlist { getReducedList(nums, number, i) };
            costs.emplace_back( number + getMaxPoint(rlist) );
        }

        // Adding to the DP table
        auto maxCost { max_element(begin(costs), end(costs)) };
        _cache.insert(make_pair(strRepresentation, *maxCost));
        
        return *maxCost;
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        // Preparing input for the main routine
        sort(nums.begin(), nums.end());
        _cache.clear();

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
