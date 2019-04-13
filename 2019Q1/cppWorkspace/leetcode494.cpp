// Problem URL: https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int _possibleCount;

    void findDFS(vector<int>& array, int index, unsigned int target) {
        auto sz = array.size();

        if( sz == index ) {
            if( target == 0 ) _possibleCount++;
            return;
        }

        findDFS(array, index + 1, target - array[index]);
        findDFS(array, index + 1, target + array[index]);
    }

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        _possibleCount = 0;
        findDFS(nums, 0, S);
        
        return _possibleCount;
    }
};

int testmain(int, char**) {
    Solution s;
    vector<int> testCase1{1,1,1,1,1};
    vector<int> testCase2{1,0};

    cout << s.findTargetSumWays(testCase1, 3) << endl;
    cout << s.findTargetSumWays(testCase2, 1) << endl;

    return 0;
}
