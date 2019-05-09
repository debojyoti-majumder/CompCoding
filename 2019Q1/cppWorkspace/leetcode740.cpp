/*  Problem URL:    https://leetcode.com/problems/delete-and-earn/
    Problem ID:     740
    Issue ID:       22
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Solution {
private:
    map<int, size_t> buildMap(const vector<int>& vec) {
        map<int,size_t> returnedMap;

        for( const auto& item : vec ) {
            auto it { returnedMap.find(item) };
            if( it != returnedMap.end() )
                it->second += 1;
            else
                returnedMap.insert(make_pair(item, 1));
        }
        
        return returnedMap;
    }

    map<int, size_t> getReducedList(map<int, size_t> numberMap, map<int, size_t>::iterator candidateItem) {
        map<int, size_t> reducedList;
        auto pickedNumber { candidateItem->first };

        for( const auto& item : numberMap ) {
            if( pickedNumber == item.first || item.first == pickedNumber - 1 || 
                item.first == pickedNumber + 1) {
                continue;
            }

            reducedList.insert(make_pair(item.first, item.second));
        }

        return reducedList;
    }

    // Recursive function that given us the cost value
    int getMaxPoint(map<int,size_t>& numberMap, map<int, size_t>::iterator candidateItem) {
        // base case
        if( candidateItem == numberMap.end() || numberMap.size() == 0 ) return 0;

        // Case: Current index is part of the final solution
        auto reducedList { getReducedList(numberMap, candidateItem) };
        int selectedCost {  
            (int)( candidateItem->first * candidateItem->second ) + 
            getMaxPoint(reducedList, reducedList.begin()) 
        };

        // Case: Current index is not part of the final solution
        auto startIndex { next(candidateItem) };
        int notSelectedCost { getMaxPoint(numberMap, startIndex) };

        return max(selectedCost, notSelectedCost);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        // Building the map of numbers
        auto numMap { buildMap(nums) };

        // Starting selection from the first item
        return getMaxPoint(numMap, numMap.begin());
    }
};

void testLeetcode740() {
    Solution s;
    
    vector<int> inp1{3,4,2};
    vector<int> inp2{2,2,3,3,3,4};
    vector<int> tleCase {1,8,5,9,6,9,4,1,7,3,3,6,3,3,8,2,6,3,2,2,1,2,9,8,7,1,1,10,6,7,3,9,6,10,5,4,10,1,6,7,4,7,4,1,9,5,1,5,7,5};
        
    // Should output 6
    cout << s.deleteAndEarn(inp1) << endl;
    
    // Should output 9
    cout << s.deleteAndEarn(inp2) << endl;

    // Should not get TLE, correct output 138
    cout << s.deleteAndEarn(tleCase) << endl;
}
