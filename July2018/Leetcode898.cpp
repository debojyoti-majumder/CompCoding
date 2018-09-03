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

    int getSecletionValue(const bitset<32>& selectionMask) {
        int maskedValue = 0, startOffset = 0, endOffset = 0;
        
        for( auto i=0; i<32;i++ ) {
            if( selectionMask.test(i) ) {
                startOffset = i;
                break;
            }
        }

        for( auto i=startOffset; i<32; i++ ){
            if( selectionMask.test(i) )
                endOffset = i;
            else
                break;
        }

        for( auto i=startOffset; i<=endOffset; i++ ) {
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
    vector<int> inp1{1};
    vector<int> inp2{1,1,2};
    vector<int> inp3{1,2,4};
    vector<int> inp4{599,187,674,261,883,475,329,979,17,685,528,538,873,118,361,16,417,353,
    533,652,916,548,858,1006,685,85,819,1022,522,669,375,319,138,133,230,314,830,976,825,982,
    222,172,687,30,899,597,546,233,216,779};
    
    Solution s;

    // These should be the sub arrays
    // [1], [1], [2], [1, 1], [1, 2], [1, 1, 2]
    cout << s.subarrayBitwiseORs(inp1) << endl;     // Should output 1
    cout << s.subarrayBitwiseORs(inp2) << endl;     // Should output 3
    cout << s.subarrayBitwiseORs(inp3) << endl;     // Should output 6
    cout << s.subarrayBitwiseORs(inp4) << endl;     // Getting TLE
    
    return 0;
}
