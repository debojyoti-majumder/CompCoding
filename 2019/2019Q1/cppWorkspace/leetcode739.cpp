/*
    Problem URL:    https://leetcode.com/problems/daily-temperatures/description/
    Problem ID:     739
    Issue Id:       26
    
    Related Problem:    
        https://leetcode.com/problems/next-greater-element-i/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
    int findMinDiff(const vector<pair<int,size_t>>& list, const pair<int,size_t>& candidate) {
        if( list.empty() ) return 0;
        size_t minVal = -1;
        bool minFound = false;

        for( const auto& item : list ) {
            auto indexDiff { item.second - candidate.second };
            if( item.first > candidate.first && indexDiff < minVal ) {
                minVal = indexDiff;
                minFound = true;
            }
        }

        return minFound ? minVal : 0;
    }

public:
    vector<int> dailyTemperatures(vector<int>& T) {
        auto inputLength { T.size() };

        // The wait list intialized, the last element is would always be zero
        vector<int> waitDaysList(inputLength, 0);
        waitDaysList[inputLength - 1] = 0;
        vector<pair<int, size_t>> maxValueList;
        maxValueList.emplace_back(make_pair(T[inputLength - 1], inputLength -1));

        for( int i=inputLength - 2; i>=0; i-- ) {
            auto currentTemp { make_pair(T[i],i) };
            
            auto it = remove_if(maxValueList.begin(), maxValueList.end(),[&]( pair<int,size_t>& item ){
                return item.first <= currentTemp.first;
            });
            if( it != maxValueList.end() ) maxValueList.erase(it);

            waitDaysList[i] = findMinDiff(maxValueList, currentTemp);
            maxValueList.emplace_back(currentTemp);
        }

        return waitDaysList;
    }
};

template <typename T>
void printVector(const vector<T>& list) {
    cout << "[ ";

    for( const auto& item : list ) 
        cout << item << " "; 

    cout << "]" << endl;
}

void testLeetcode739() {
    Solution s;
    
    // Should output [1, 1, 4, 2, 1, 1, 0, 0]
    vector<int> inp{73, 74, 75, 71, 69, 72, 76, 73};
    auto ret { s.dailyTemperatures(inp) };
    printVector(ret);
    
    // Should output [0,0,0,0,0]
    vector<int> sameInp {53,53,53,53,53};
    auto ret2 { s.dailyTemperatures(sameInp) };
    printVector(ret2);

    // Should output all zero
    vector<int> huge(40000, 45);
    auto ret3 { s.dailyTemperatures(huge) };
    printVector(ret3);

}

int main(int argc, const char *argv[]) {;
    testLeetcode739();
    return 0;
}
