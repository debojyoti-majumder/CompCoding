// Problem URL: https://leetcode.com/problems/random-pick-index/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // Value to index map
    unordered_map<int, vector<int>> _itemMap;

public:
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++ ) {
            auto it = _itemMap.find(nums[i]);

            if( it == _itemMap.end() ) {
                _itemMap.insert(make_pair(nums[i], vector<int>{i}));
            }
            else {
                it->second.emplace_back(i);
            }
        }
    }
    
    int pick(int target) {
        auto it = _itemMap.find(target);
        if( it == _itemMap.end() ) return -1;

        auto& itemIndexes { it->second };
        int randIndex = rand() % itemIndexes.size();
        return itemIndexes[randIndex];        
    }
};
