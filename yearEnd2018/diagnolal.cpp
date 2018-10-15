// Problem link: https://leetcode.com/problems/diagonal-traverse/description/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        return vector<int>{};        
    }
};

int main(int, char**) {
    vector<vector<int>> matrix{
        vector<int>{1,2,3},
        vector<int>{4,5,6},
        vector<int>{7,8,9}        
    };

    Solution s;
    auto ret = s.findDiagonalOrder(matrix);

    // Should output 1,2,4,7,5,3,6,8,9
    for(const auto& v: ret) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}
