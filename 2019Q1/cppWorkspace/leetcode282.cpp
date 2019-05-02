// Leetcode282: https://leetcode.com/problems/expression-add-operators/

#include "pch.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    void static addToExpr(char op, const string exp, vector<string>& outStrings) {
        for( size_t i=0; i<outStrings.size(); i++ ) {
            string tmp{exp};
            tmp += " " + op;
            tmp += " ";
            tmp += outStrings[i];

            outStrings[i] = tmp;
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> retStrings;
        
        // Base case
        if (num.length() == 0)
            return retStrings;

        if (atoi(num.c_str()) == target) {
            retStrings.push_back(num);
        }

        for (int i = 0; i < num.length(); i++) {
            auto comp1{ num.substr(0,i+1) };
            auto comp2{ num.substr(i+1) };

            int val = atoi(comp1.c_str());
            
            auto plusOp{ addOperators(comp1, target - val) };
            auto minsOp{ addOperators(comp1, target + val) };
            vector<string> multiplyOp;

            // If divisable
            if( target % val == 0 ) {
                multiplyOp = addOperators(comp1, target / val);

            }

            Solution::addToExpr('+', comp1, plusOp);
            retStrings.insert(retStrings.end(), plusOp.begin(), plusOp.end());

            Solution::addToExpr('-', comp1, minsOp);
            retStrings.insert(retStrings.end(), minsOp.begin(), minsOp.end());

            Solution::addToExpr('*', comp1, multiplyOp);
            retStrings.insert(retStrings.end(), multiplyOp.begin(), multiplyOp.end());
        }

        return retStrings;
    }
};

template <typename T>
void printIter(const vector<T>& items) {
    cout << "[ ";

    for (const auto& val : items)
        cout << val << " ";

    cout << " ]" << endl;
}

int main() {
    Solution s;
    
    auto out1{ s.addOperators("123", 6) };
    printIter(out1);

    auto out2{ s.addOperators("232", 8) };
    printIter(out2);

    auto out3{ s.addOperators("105", 5) };
    printIter(out3);

    return 0;
}
