// Leet code problem url: https://leetcode.com/problems/pascals-triangle/
// Submitted and accepted
// Add the part 2 of the probelm fails with 13 seems like nCr implementaion is flawed

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    private:
        // This is for precalculated factorial lookup
        map<int,int> _factorialLookUp;

        int factorial(int n) {
            //auto it = _factorialLookUp.find(n);

            //if( it != _factorialLookUp.end() ) {
            //    return it->second;
            //}

            if( n < 1 )
                return 1;
            else {
                int res = n*factorial(n-1);
                //_factorialLookUp.insert(make_pair(n,res));

                return res;
            }
                
        }

        int nCrFactorialWay(int n,int r) {
            long long top1 = factorial(n);
            long bottom1 = factorial(r);
            long bottom2 = factorial(n-r);

            return (int) (top1/(bottom1*bottom2));
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

        vector<int> generatenthRow(int rowIndex) {
            vector<int> retValue;
            
            if( rowIndex <0 ) {
                return retValue;
            }

            cout << nCrFactorialWay(13,12) << endl;

//            int r = rowIndex;
//            for(int i=0; i<r; i++) 
//                retValue.push_back(nCrFactorialWay(r,r-i));
            
//            retValue.push_back(1);
            return retValue;
        }
};

int main() {
    Solution sol;
    
    /*int num;
    cin >> num;
    
    auto ret = sol.generate(num);

    // Print the triangle
    for(auto row: ret) {
        for(auto item: row)
            cout << item << " ";
        
        cout << endl;
    }*/

    // Generating the nth row through formula
    auto retRow = sol.generatenthRow(13);
    for(auto p: retRow) 
        cout << p << " ";
    cout << endl;

    return 0;
}