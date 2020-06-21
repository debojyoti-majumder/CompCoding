/*
    Problem URL:    https://leetcode.com/problems/add-to-array-form-of-integer/
    Problem ID:     989
    Issue Id:       25       

    Related Challange:
        https://leetcode.com/problems/plus-one/
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

        int startPos { (int)A.size() - (int)pos };
        bool additionalDigitRequired { true };

        for( int i=startPos; i>=0; i-- ) {
            auto tempVal { A[i] };
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
        auto digitCounter { 1 };

        // If the number is bigger the array it need to be padded
        int sizeDiff { int(numberString.size() - A.size()) };
        if( sizeDiff > 0 ) {
            for( int i=0; i<sizeDiff; i++ )    A.insert(A.begin(),0);
        }

        // Adding one digit at a time
        for( size_t i=numberString.length(); i>=1; i-- ) {
            // 48 is zero acsi value, calling the helper 
            auto actualNumber{ (int)numberString[i-1] - 48 };
            addDigitAt(A, actualNumber, digitCounter++);
        }

        // returning the updated array
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
    printVector(s.addToArrayForm(inp2, 181));

    // Should output 1021
    vector<int> inp3 {2,1,5};
    printVector(s.addToArrayForm(inp3, 806));

    // Should output 10000000000
    vector<int> inp4 { 9,9,9,9,9,9,9,9,9,9 };
    printVector(s.addToArrayForm(inp4, 1));
    
    // Should output 23
    vector<int> inp5 {0};
    printVector(s.addToArrayForm(inp5, 23));

    // 
    vector<int> inp6 { 1, 6 };
    printVector(s.addToArrayForm(inp6, 116 ));
    return 0;
}
