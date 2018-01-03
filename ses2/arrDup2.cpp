// Problem Url: https://leetcode.com/problems/contains-duplicate-ii/description/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class ArrayItem {
    private:
        int     _num;
        size_t  _pos;
        ArrayItem() {}

    public:
        ArrayItem(int n, size_t p) : _num(n) , _pos(p) {}
        bool operator < (const ArrayItem& obj) const {
            return _num < obj._num;
        }

        size_t getPos() const { return _pos; }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        auto arr_size = nums.size();
        set<ArrayItem>  number_set;
        bool ret_value = false;

        for(auto i=0; i<arr_size; i++) {
            ArrayItem item(nums[i], i);    
            auto ret = number_set.insert(item);
            
            if( ret.second == false ) {
                auto p = ret.first->getPos();
                auto diff = abs((int)p - (int)i);

                if( diff <= k )
                    ret_value = true;
            }
        }

        return ret_value;      
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