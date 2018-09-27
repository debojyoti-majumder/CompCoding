// Problem URL: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        int val;
    public:
        int singleNonDuplicate(vector<int>& nums) {
            size_t arraySize = nums.size();
            val = -1;

            for(size_t i=0; i<arraySize; i++) {
                if( val == -1 ) {
                    val = nums[i];
                }
                else if( val == nums[i] ){
                    val = -1;
                }
            }

            return val;      
        }
};

int main() {
    Solution s;

    // Should output 2
    vector<int> inp1{1,1,2,3,3,4,4,8,8};
    cout << s.singleNonDuplicate(inp1) << endl; 
    
    // Should output 10
    vector<int> inp2{3,3,7,7,10,11,11};
    cout << s.singleNonDuplicate(inp2) << endl;
    return 0;
}
