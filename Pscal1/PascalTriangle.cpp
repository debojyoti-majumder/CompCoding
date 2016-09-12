// Leet code problem url: https://leetcode.com/problems/pascals-triangle/
// Submitted and accepted

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
            
            // Basic seeding
            returnItem.push_back(seedItem);

            for(int i=1; i<numRows; i++ ) {
                auto workingItem = seedItem;
                
                // Padding with zero
                workingItem.push_back(0);
                workingItem.insert(workingItem.begin(), 0);
                seedItem.clear();

                for(size_t j=1; j<workingItem.size(); j++) {
                    int sum = workingItem[j] + workingItem[j-1];
                    seedItem.push_back(sum);
                }

                returnItem.push_back(seedItem);
            }

            return returnItem;
        }
};

int main() {
    Solution sol;
    
    int num;
    cin >> num;
    
    auto ret = sol.generate(num);

    // Print the triangle
    for(auto row: ret) {
        for(auto item: row)
            cout << item << " ";
        
        cout << endl;
    }

    return 0;
}