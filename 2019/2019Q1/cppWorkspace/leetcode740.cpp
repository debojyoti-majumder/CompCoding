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
        if( numMap.size() == 0 ) return 0;
        
        auto accCost { 0 };
        auto prevNumber { 0 };

        map<int,size_t> costMap;

        for( const auto& numberItem : numMap ) {
            if( numberItem.first == numMap.begin()->first ) {
                prevNumber = numberItem.first;
                costMap.insert(numberItem);
            }
            else if( costMap.size() == 3 ) {
                accCost += getMaxPoint(costMap, costMap.begin());
                
                costMap.clear();
                costMap.insert(numberItem);
                prevNumber = numberItem.first;
            }
            else if( prevNumber + 1 == ( numberItem.first ) ) {
                prevNumber = numberItem.first;
                costMap.insert(numberItem);
            }
        }

        accCost += getMaxPoint(costMap, costMap.begin());
        return accCost;
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

    vector<int> q{1,2,3,4,5,6};
    cout << s.deleteAndEarn(q) << endl;

    // Should output 138
    vector<int> tleCase {   1,8,5,9,6,9,4,1,7,3,3,6,3,3,8,2,6,3,2,2,1,2,9,8, 7,1,1,10,6,7,3,9,6,10,5,4,10,1,6,7,4,7,4,1,9,5,1,5,7,5};
    cout << s.deleteAndEarn(tleCase) << endl;

    vector<int> tleCase2 {  25,95,76,4,90,87,46,44,58,33,62,79,5,3,32,21,87,31,44,68,49,45,18,50,26,74,64,17,81,49,80,58,15,6,90,8,6,28,15,16,9,98,50,96,30,27,67,99,86,63,19,54,80,4,84,24,60,22,75,35,76,3,37,80,16,51,14,51,93,49,84,82,48,9,7,79,7,68,15,11,71,59,18,47,5,57,64,38,99,35,57,9,13,14,81,25,5,14,74,63,80,78,70,48,32,54,34,40,21,95,98,25,72,59,21,49,19,2,18,93,14,81,57,41,95,69,71,64,50,35,26,72,92,51,18,11,55,26,2,95,93,35,71,47,88,22,66,90,72,
                            66,61,11,76,10,95,24,35,75,15,95,24,76,78,58,28,23,75,73,40,40,84,18,31,91,7,97,13,96,39,17,22,85,28,79,61,73,
                            88,36,82,27,95,31,96,59,20,13,44,13,7,29};
    cout << s.deleteAndEarn(tleCase2) << endl;
}
