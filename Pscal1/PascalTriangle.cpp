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

            if(numRows <= 0 )
                return returnItem;
            
            if( numRows == 1 ) {
                returnItem.push_back(seedItem);
                return returnItem;
            }

            for(int i=1; i<numRows; i++ ) {
                auto workingItem = seedItem;
                
                // Padding with zero
                workingItem.push_back(0);
                workingItem.insert(workingItem.begin(), 0);
            }

            return returnItem;
        }
};

int main() {
    Solution sol;

    auto ret = sol.generate(5);

    // Print the triangle
    for(auto row: ret) {
        for(auto item: row)
            cout << item << " ";
        
        cout << endl;
    }

    return 0;
}