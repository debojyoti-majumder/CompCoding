// Problem URL: https://leetcode.com/problems/product-of-array-except-self/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto lastVectorIndex = nums.size() - 1;
        if( lastVectorIndex < 1 )
            return nums;

        vector<int> forwardMultipliers(nums.size() - 1);
        vector<int> backwardMultipliers(nums.size() - 1);
        forwardMultipliers[0] = nums[0];
        backwardMultipliers[0] = nums[lastVectorIndex];

        for( int i=1; i<lastVectorIndex; i++ )
            forwardMultipliers[i] = forwardMultipliers[i - 1] * nums[i];

        for( int i=1; i<lastVectorIndex; i++ ) 
            backwardMultipliers[i] = backwardMultipliers[i - 1] * nums[lastVectorIndex - i];

        nums[0] = backwardMultipliers[lastVectorIndex - 1];
        nums[lastVectorIndex] = forwardMultipliers[lastVectorIndex - 1];

        for(int i=0; i<lastVectorIndex-1; i++) {
            nums[i+1] = forwardMultipliers[i] * backwardMultipliers[lastVectorIndex - i - 2];
        }

        return nums;
    }
};

int main() {
    vector<int> input{1,2,3,4,5,6};
    Solution s;

    auto output(s.productExceptSelf(input));
    for(auto i : output )
        cout << i << " ";
    
    cout << endl;
    return 0;
}
