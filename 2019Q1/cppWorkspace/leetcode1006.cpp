/*
    Problem URL:    https://leetcode.com/problems/clumsy-factorial/description/
    Problem ID:     1006
    Issue Id:       28

    Related Problems:
        https://leetcode.com/problems/nth-digit/
        https://leetcode.com/problems/robot-bounded-in-circle/
        https://leetcode.com/problems/reaching-points/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct OperationDescription {
        int operand;
        bool type; // 1 = add , 0 = sub

        explicit OperationDescription(int p) : operand(p), type(false) {
        }

        OperationDescription(int p, bool val) : operand(p), type(val) {
        }

        OperationDescription() = default;
    };

    int evaluateExpression( const vector<OperationDescription>& expr ) {
        auto sz { expr.size() };
        if( sz == 0 ) return 0;

        auto sum { expr[0].operand };
        auto iterCount { sz - 1 };

        for( size_t i=1; i<sz; i++ ) {
            if( expr[i-1].type )
                sum += expr[i].operand;
            else
                sum -= expr[i].operand;
        }

        return sum;
    }

public:
    // This is would evaluate the multiplication and divisions
    int clumsy(int N) {
        // This required for the below functions to work correctly, any input beyond this 
        // would build an vector of a length at least 3
        if( N <= 2 ) return N;

        auto number { N };
        short int operand = 0;
        vector<OperationDescription> operationsTBD;

        while( number > 0 ) {
            // This is for multiplication, nothing to be done for division
            if( operand == 0 ) {
                if( number > 2 ) {
                    auto res { (number * (number - 1)) / (number - 2) };
                    
                    // The devide is need to be skipped, because the calulation 
                    // is already done, saying next operation is 3 which is addition
                    operationsTBD.emplace_back(OperationDescription{res, true});
                    number -= 3;
                    operand = 2;
                }
                else {
                    // No more numbers to process
                    operationsTBD.emplace_back(OperationDescription{number});
                    break;
                }
            }
            else if( operand == 2 || operand == 3 ) {
                // This is for addition and substraction
                if( operand == 2 ) {
                    operationsTBD.emplace_back(OperationDescription{number, false});
                    number--;
                }

                operand++;
                operand = operand % 4;
            }
        }

        return evaluateExpression(operationsTBD);
    }
};

int main() {
    Solution s;

    // Should ouput 7
    cout << s.clumsy(4) << endl;
    
    cout << s.clumsy(7) << endl;

    // Should output 11
    cout << s.clumsy(9) << endl;

    // Should output 9
    cout << s.clumsy(8) << endl;   

    // Should output 12
    cout << s.clumsy(10) << endl;

    cout << s.clumsy(3) << endl;
    return 0;
}
