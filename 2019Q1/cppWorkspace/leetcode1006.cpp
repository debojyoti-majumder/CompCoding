/*
    Problem URL:    https://leetcode.com/problems/clumsy-factorial/description/
    Problem ID:     1006
    Issue Id:       28
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct OperationDescription
    {
        int operand;
        int opType; // 0 = multiply 1=division 2=add 1=sub
    };
    vector<OperationDescription> _operations;

    void buildOperationList(int number) {
        _operations.clear();
        short int opCounter { 0 };

        for( int i=number; i>=1; i-- ) {
            OperationDescription desc;

            desc.operand = i;
            desc.opType = opCounter;
            _operations.emplace_back(desc);

            opCounter++;
            opCounter = opCounter % 4;
        }
    }

    // Should perform all the division first
    void reduceDivAndMul() {
        auto sz { _operations.size() };

        for( size_t i=0; i<sz; i++ ) {
            // We need to look for operand next
            if( _operations[i].opType == 0 && i < sz - 2 ) {
                int mulVal = { _operations[i].operand / _operations[i+1].operand };
                _operations[i+1] = mulVal;
            }
            else if( _operations[i].opType == 1 && i < sz - 2 ) {
                // My guess is this should always be 1
                int devidedValue { _operations[i].operand / _operations[i+1].operand };
                _operations[i+1].operand = devidedValue;
            }
        }
    }

    int evaluate() {
        int result { 1 };
        auto sz {_operations.size()-1};

        // Initalized to 1 becuase of multiplication would be done first
        for( size_t i=0; i<sz; i++ ) {
           switch( _operations[i].opType ) {
                // Addition
                case 2:
                    result = _operations[i].operand + _operations[i+1].operand;
                    _operations[i+1].operand = result;
                    break;
                
                // Substraction
                case 3:
                    result = _operations[i].operand - _operations[i+1].operand;
                    _operations[i+1].operand = result;
                    break;
           }
        }

        return _operations[sz].operand;
    }

public:
    int clumsy(int N) {
        // This required for the below functions to work correctly, any input beyond this 
        // would build an vector of a length at least 3
        if( N <= 2 ) return N;

        // Doing the computation to reduce the list
        buildOperationList(N);
        reduceDivAndMul();

        return evaluate();
    }
};

int main() {
    Solution s;

    // Should ouput 7
    cout << s.clumsy(4) << endl;
    
    // Should output 12
    cout << s.clumsy(10) << endl;
    return 0;
}
