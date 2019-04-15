// Leetcode282: https://leetcode.com/problems/expression-add-operators/

#include "pch.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> retStrings;
        
        // Base case
        if (num.length() == 0)
            return retStrings;

        if (atoi(num.c_str()) == target) {
            retStrings.push_back(num);
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
