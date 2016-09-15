// Leet code problem url: https://leetcode.com/problems/pascals-triangle/
// Submitted and accepted
// Add the part 2 of the probelm

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        int factorial(int n) {
            if( n < 1 )
                return 1;
            else
                return n*factorial(n-1);
        }

        int nCrFactorialWay(int n,int r) {
            
        }

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

                // Doing the addition
                for(size_t j=1; j<workingItem.size(); j++) {
                    int sum = workingItem[j] + workingItem[j-1];
                    seedItem.push_back(sum);
                }

                // Adding the data to the main result
                returnItem.push_back(seedItem);
            }

            return returnItem;
        }

        vector<int> generatenthRow(int row) {
            vector<int> retValue;

            return retValue;
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