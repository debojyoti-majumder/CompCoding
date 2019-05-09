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
    map<string, int> _cache;

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

    template<typename KEY, typename VALUE>
    string toString( const map<KEY,VALUE>& inputMap ) {
        stringstream accmulator;

        for( const auto& item : inputMap ) {
            accmulator << item.first << "=" << item.second << " ";
        }

        return accmulator.str();
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

        // Doing DP table lookup
        string cacheKey { toString(numberMap) };
        auto it { _cache.find(cacheKey) };
        if( it != _cache.end() ) {
            return it->second;
        }

        // Case: Current index is part of the final solution
        auto reducedList { getReducedList(numberMap, candidateItem) };
        int selectedCost {  
            (int)( candidateItem->first * candidateItem->second ) + 
            getMaxPoint(reducedList, reducedList.begin()) 
        };

        // Case: Current index is not part of the final solution
        auto startIndex { next(candidateItem) };
        int notSelectedCost { getMaxPoint(numberMap, startIndex) };

        // Adding the value to the DP table
        auto retVal { max(selectedCost, notSelectedCost) };
        _cache.insert(make_pair(cacheKey, retVal));
        
        return retVal;
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
    
    // Should output 6
    vector<int> inp1{3,4,2};
    cout << s.deleteAndEarn(inp1) << endl;
    
    // Should output 9
    vector<int> inp2{2,2,3,3,3,4};
    cout << s.deleteAndEarn(inp2) << endl;

    // // Should not get TLE, correct output 138
    vector<int> tleCase {   1,8,5,9,6,9,4,1,7,3,3,6,3,3,8,2,6,3,2,2,1,2,9,8,
                            7,1,1,10,6,7,3,9,6,10,5,4,10,1,6,7,4,7,4,1,9,5,1,5,7,5};
    cout << s.deleteAndEarn(tleCase) << endl;

    vector<int> tleCase2 {  12,32,93,17,100,72,40,71,37,92,58,34,29,78,11,84,77,90,
                            92,35,12,5,27,92,91,23,65,91,85,14,42,28,80,85,38,71,62,82,66,3,33,33,55,60,48,78,63,
                            11,20,51,78,42,37,21,100,13,60,57,91,53,49,15,45,19,51,2,96,22,32,2,46,62,58,11,29,6,74,
                            38,70,97,4,22,76,19,1,90,63,55,64,44,90,51,36,16,65,95,64,59,53,93};
    cout << s.deleteAndEarn(tleCase2) << endl;
}
