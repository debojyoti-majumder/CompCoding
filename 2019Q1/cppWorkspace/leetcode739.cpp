/*
    Problem URL:    https://leetcode.com/problems/daily-temperatures/description/
    Problem ID:     739
    Issue Id:       26
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    vector<int> dailyTemperatures(vector<int>& T) {
        auto inputLength { T.size() };
        vector<int> waitDaysList(inputLength, 0);
        vector<size_t> waitList;
        waitList.emplace_back(0);

        // Should do just one pass, the array is going to be long
        for( size_t i=1; i<inputLength; i++ ) {
            auto currentTemp { T[i] };
            
            // Removing item from the wait list is we have got a hotter temp
            auto remIt = remove_if(waitList.begin(), waitList.end(), [&](size_t index) {
                auto temp { T[index] };
                auto ret { currentTemp > temp };
                
                // If the item getting removed then we store the index
                if( ret ) {
                    auto diff { i - index };
                    waitDaysList[index] = diff;
                }

                // returning the comparison result
                return ret;
            });
            waitList.erase(remIt, waitList.end());

            // By deault all the items would be added to the wait list
            waitList.emplace_back(i);
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
    vector<int> inp{73, 74, 75, 71, 69, 72, 76, 73};

    // Should output [1, 1, 4, 2, 1, 1, 0, 0]
    auto ret { s.dailyTemperatures(inp) };
    printVector(ret);

}

int main(int argc, const char *argv[]) {;
    testLeetcode739();
    return 0;
}
