// Problem URL: https://leetcode.com/problems/bitwise-ors-of-subarrays/description/

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <set>

using namespace std;

class Solution {
private:
    vector<int> _inputArray;
    int maskedValue = 0;

    int getSecletionValue(const bitset<32>& selectionMask) {
        for(auto i=0; i<_inputArray.size(); i++) {
            if( selectionMask.test(i) ) 
                maskedValue |= _inputArray[i];
        }

        return maskedValue;
    }

public:
    int subarrayBitwiseORs(vector<int>& A) {
        auto sz = A.size();
        auto possibilites = pow(2,sz);
        set<int> uniqueValues;

        _inputArray.clear();
        _inputArray = A;
        
        for(auto i=1; i<possibilites; i++) {
            bitset<32> selectionBits(i);
            uniqueValues.insert(getSecletionValue(selectionBits));
        }

        return uniqueValues.size();        
    }
};


int main() {
    vector<int> inp2{1,1,2};
    vector<int> inp3{1,2,4};
    Solution s;

    // These should be the sub arrays
    // [1], [1], [2], [1, 1], [1, 2], [1, 1, 2]
    cout << s.subarrayBitwiseORs(inp2) << endl;
    cout << s.subarrayBitwiseORs(inp3) << endl;
    
    return 0;
}
