// Problem URL: https://leetcode.com/problems/minimum-falling-path-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> _matrix;

    // Will return start and end index of matrix;
    pair<int,int> getValidIndexRange() {
        return pair<int,int> {-1,-1};
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        _matrix = A;
        return 0;
    }
};

void testCases() {
    Solution s;
    vector<vector<int>> input1 = {
        {1,2,3}, {4,5,6}, {7,8,9}
    };

    // Should output 12
    cout << "Test case 1:" << s.minFallingPathSum(input1) << endl;
}