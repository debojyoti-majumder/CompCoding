// Leet code problem url: https://leetcode.com/problems/pascals-triangle/
// Not yet submitted

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) 
        {
            vector<vector<int>> returnItem;
            vector<int> seedItem = {1};

            for(int i=0; i<numRows; i++ ) {
                auto workingItem = seedItem;
                
            }

            return returnItem;
        }
};

int main() {
    Solution sol;

    auto ret = sol.generate(5);
    return 0;
}