// Problem url: https://leetcode.com/problems/array-partition-i/#/description

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            return 0;
        }
};

int main() {
    Solution s;

    int test_case1[] = {1,2,3,4};
    vector<int> input_1(test_case1,test_case1 + sizeof(test_case1)/sizeof(int));
    
    int test_case2[] = {1,4,3,2,6,7,8,9,2,3};
    vector<int> input_2(test_case2, test_case2 + sizeof(test_case2)/sizeof(int));

    // Should output 4
    cout << s.arrayPairSum(input_1) << endl;
    
    // Should output 20
    cout << s.arrayPairSum(input_2) << endl;

    return 0;
}
