/*
    Problem URL:    https://leetcode.com/problems/daily-temperatures/description/
    Problem ID:     739
    Issue Id:       26
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> dailyTemperatures(vector<int>& T) {
        auto inputLength { T.size() };
        vector<int> waitDaysList(0, inputLength);
        vector<size_t> waitStack;
        waitStack.emplace_back(0);

        // Should do just one pass, the array is going to be long
        for( size_t i=1; i<inputLength; i++ ) {
            auto currentTemp { T[i] };

            // If we have got a higher temerature empty the satck
            // and also we the wait value
            auto lastItemIndex { waitStack.back() };
            if( currentTemp > T[lastItemIndex] ) {
                // Should update the indexes here
                while( false == waitStack.empty() ) {
                    waitStack.pop_back();
                    waitDaysList[lastItemIndex] = i - lastItemIndex;
                }
            }
            
            // The current item goes back in the stack
            waitStack.emplace_back(i);
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

int main(int argc, const char *argv[]) {
    Solution s;
    vector<int> inp{73, 74, 75, 71, 69, 72, 76, 73};

    // Should output [1, 1, 4, 2, 1, 1, 0, 0]
    auto ret { s.dailyTemperatures(inp) };
    printVector(ret);
    
    return 0;
}
