/*
    Problem URL:    https://leetcode.com/problems/add-to-array-form-of-integer/
    Problem ID:     989
    Issue Id:       25       
*/

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
    // "pos" is from right
    void addDigitAt(vector<int>& A, int number, size_t pos) {
        // Should not happen but still it's safegaurd
        if( number >= 10) return;

        auto startPos { A.size() - pos };
        auto tempVal { A[startPos] };
        bool additionalDigitRequired { true };

        for( auto i=startPos; i>=0; i-- ) {
            tempVal += number;

            if( tempVal < 10 ) {
                A[i] = tempVal;
                additionalDigitRequired = false;
                break;
            }
            else {
                number = 1;
                tempVal -= 10;
                A[i] = tempVal;
            }
        }

        if( additionalDigitRequired )
            A.insert(A.begin(),1);
    }

public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        // Converting the to string
        stringstream numberStream;
        numberStream << K;
        auto numberString { numberStream.str() };

        for( size_t i=1; i<=numberString.length(); i++ ) {
            // 48 is zero acsi value, calling the helper 
            auto actualNumber{ (int)numberString[i-1] - 48 };
            addDigitAt(A, actualNumber, i);
        }

        return A;
    }
};


template <typename T>
void printVector(const vector<T>& list) {
    cout << "[ ";

    for( const auto& item : list ) 
        cout << item << " "; 

    cout << "]" << endl;
}

int main() {
    Solution s;

    // Should output 1234
    vector<int> inp1{1,2,0,0};
    auto ret1 {s.addToArrayForm(inp1, 34)};
    printVector(ret1);

    // Should output 455
    vector<int> inp2{2,7,4};
    auto ret2 { s.addToArrayForm(inp2, 181) };
    printVector(ret2);

    // Should output 1021
    vector<int> inp3 {2,1,5};
    auto ret3 { s.addToArrayForm(inp3, 806) };
    printVector(ret3);

    // Should output 10000000000
    vector<int> inp4 { 9,9,9,9,9,9,9,9,9,9 };
    auto ret4 { s.addToArrayForm(inp4, 1) };
    printVector(ret4);
    
    return 0;
}
