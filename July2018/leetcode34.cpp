// Problem Url: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private: 
    int _targetNumber;
    vector<int> _numbers;
    int pos;

    bool doBinarySearch(size_t startPos, size_t endPos) {
        if( startPos == endPos ) {
            pos = startPos;
            return _numbers[startPos] == _targetNumber;
        }

        int midPos = (endPos - startPos) / 2;
        midPos = startPos + midPos;

        if( _numbers[midPos] == _targetNumber ) {
            pos = midPos;
            return true;
        }
        else if( _targetNumber < _numbers[midPos] ) {
            auto x = midPos - 1;
            return doBinarySearch(startPos, x);
        }
        else {
            auto x = midPos + 1;
            return doBinarySearch(x, endPos);
        }
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> retValue{-1, -1};
        _numbers = nums;
        _targetNumber = target;
        pos = -1;

        auto sz = nums.size();
        if( sz == 0 )
            return retValue;
            
        if( doBinarySearch(0, sz-1) ) {
            // If found have to search left and right
            auto pointerLeft = pos;
            auto pointerRight = pos;

            while( _numbers[pointerLeft] == _targetNumber )
                --pointerLeft;

            while( _numbers[pointerRight] == _targetNumber )
                ++pointerRight;
            
            retValue[0] = pointerLeft + 1;
            retValue[1] = pointerRight - 1;
        }
        
        return retValue;        
    }
};

int main() {
    Solution s;
    vector<int> inp1{5,7,7,8,8,10};
    vector<int> inp2{5,7,7,8,8,8,8,10};
    vector<int> inp;

    auto ret = s.searchRange(inp1, 8);

    // Should return 3,4
    cout << ret[0] << " " << ret[1] << endl;

    // Should return -1,1
    ret = s.searchRange(inp1, 6);
    cout << ret[0] << " " << ret[1] << endl;

    // Should return 3,6;
    ret = s.searchRange(inp2,8);
    cout << ret[0] << " " << ret[1] << endl;

    ret = s.searchRange(inp,8);
    cout << ret[0] << " " << ret[1] << endl;

    return 0;
}
