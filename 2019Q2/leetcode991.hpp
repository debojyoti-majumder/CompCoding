// https://leetcode.com/problems/broken-calculator/
// Should take a gready approch

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct ValueObject
{
    int value;
    int operationCount;
};

class Solution {
private:
    deque<ValueObject>  _solutionQueue;
    vector<int>         _retValues;
    set<int>            _valuesSeen;

    void addToSolutionQueue(const ValueObject& v) {
        auto it = _valuesSeen.find(v.value);

        if (it == _valuesSeen.end()) {
            _solutionQueue.emplace_back(v);
            _valuesSeen.insert(v.value);
        }
    }

public:
    int brokenCalc(int X, int Y) {
        ValueObject v{X, 0};

        // Initialization, clearing the set for the previous function call
        // Swaping values of X and Y will fail test case
        _valuesSeen.clear();
        _retValues.clear();
        addToSolutionQueue(v);

        while (!_solutionQueue.empty()) {
            auto queueItem{_solutionQueue.front()};
            _solutionQueue.pop_front();

            // We have found out the operation
            if (queueItem.value == Y) {
                _retValues.emplace_back(queueItem.operationCount);
            }

            // These are the two operation in the calculator
            auto currentValue {queueItem.value};
            ValueObject option1 { currentValue - 1, queueItem.operationCount + 1 };
            ValueObject option2 { currentValue * 2, queueItem.operationCount + 1 };

            // Adding them in the possible solution queue
            if( option1.value > 0 ) {
                addToSolutionQueue(option1);
            }
            
            if( option2.value <= Y + 1 ) {
                addToSolutionQueue(option2);
            }
        }

        // This case should not happen by any means, keeping for error reporting
        if( _retValues.empty() ) return -1;

        // Retunging the mininum value
        return *min_element(_retValues.begin(), _retValues.end());
    }
};

int main() {
    Solution s;

    // Should output 2 ( 2 -> 4 -> 3 )
    cout << s.brokenCalc(2, 3) << endl;

    // Should output 2 ( 5 -> 4 -> 8 )
    cout << s.brokenCalc(5, 8) << endl;

    // Should output 3 ( 3 -> 6 -> 5 -> 10 )
    cout << s.brokenCalc(3, 10) << endl;

    // Should output 1023
    cout << s.brokenCalc(1024, 1) << endl;

    // Getting TLE
    cout << s.brokenCalc(1,1000000000) << endl;
    return 0;
}
