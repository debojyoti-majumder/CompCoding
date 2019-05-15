/*
    Problem URL:    https://leetcode.com/problems/expression-add-operators/
    Problem ID:     282
*/

#include "myhelper.hpp"

using namespace std;

class Solution {
private:
    void addToSolution(vector<string>& retVal, string left, char symbol) {

    }

private:
    vector<string> getTarget() {

    }
    
public:
    vector<string> addOperators(string num, int target) {
        vector<string> retValues;
        auto stringLength { num.length() };

        // Base case
        if( stringLength == 0 ) return retValues;

        for( size_t i=0; i<stringLength; i++ ) {
            auto leftPart { num.substr(0, i + 1) };
            auto rightPart { num.substr(i+1) };

            auto leftValue { atoi(leftPart.c_str()) };
            
            if( leftValue == target ) retValues.emplace_back(leftPart);

            if( rightPart.length() ) {
                auto rightValue { atoi(rightPart.c_str()) };

                auto minusTarget = target + rightValue;
                auto plusTarget = target - rightValue;
                auto devideTarget = target * rightValue;

                if( leftValue % rightValue == 0 ) {
                    auto multiplyTarget = leftValue * rightValue; 
                } 
                else if( rightValue % leftValue == 0 ) {
                    auto multiplyTarget = leftValue * rightValue;
                }
            }

            
        }

        return retValues;
    }
};

void test282() {
    Solution s;

    // ["1+2+3", "1*2*3"] 
    s.addOperators("123", 6);
    
    // Should output ["2*3+2", "2+3*2"]
    s.addOperators("232", 8);

    // Should output ["1*0+5","10-5"]
    s.addOperators("105", 5);
    
    // Should output ["0+0", "0-0", "0*0"]
    s.addOperators("00",  0);

    // Should output []
    s.addOperators("3456237490", 9191);
}

int main() {
    test282();
    return 0;
}
