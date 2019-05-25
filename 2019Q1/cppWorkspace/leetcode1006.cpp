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
    struct OperationDescription {
        int operand;
        bool type; // 1 = add , 0 = sub
    };

    int evaluateExpression( const vector<OperationDescription>& expr ) {
        auto sum { expr[0].operand };
        auto iterCount { expr.size() - 1 };

        for( size_t i=1; i<expr.size(); i++ ) {
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
        int prevNumber;
        vector<OperationDescription> operationsTBD;

        while( number > 0 ) {
            // This is for multiplication, nothing to be done for division
            if( operand == 0 ) {
                if( number > 2 ) {
                    prevNumber = (number * (number - 1)) / (number - 2);
                    
                    // The devide is need to be skipped, because the calulation 
                    // is already done, saying next operation is 3 which is addition
                    number -= 3;
                    operand = 2;
                }
                else {
                    prevNumber = (number * (number - 1));
                    OperationDescription desc;
                    desc.operand = 2;
                    operationsTBD.emplace_back(desc);

                    // No more numbers to process
                    number = 0;
                }
            }
            else if( operand == 2 || operand == 3 ) {
                // This is for addition and substraction
                OperationDescription desc;
                desc.operand = prevNumber;
                desc.type = operand == 2 ? true : false;
                operationsTBD.emplace_back(desc);

                prevNumber = number;

                // Determining the what would be next operation
                if( desc.type ) number--;
                operand = desc.type ? 3 : 0;
            }
        }

        return evaluateExpression(operationsTBD);
    }
};

int main() {
    Solution s;

    // Should ouput 7
    cout << s.clumsy(4) << endl;
    
    // Should output 11
    cout << s.clumsy(9) << endl;

    // Should output 9
    cout << s.clumsy(8) << endl;   

    // Should output 12
    cout << s.clumsy(10) << endl;

    return 0;
}
