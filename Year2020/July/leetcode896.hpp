#include "pch.h"

#include <vector>
#include <iostream>

using namespace std;

/* 
    Problem URL:    https://leetcode.com/problems/monotonic-array/
    Problem ID:     896

    Related Problems:
        - https://leetcode.com/problems/find-pivot-index/( Easy )
        - https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/ ( Easy )
        - https://leetcode.com/problems/search-a-2d-matrix/ ( Medium )

*/
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        // Base case an arry with size less than 3 they are always monochrome
        auto arraySize{ A.size() };
        if (arraySize < 3) return true;
        
        bool retValue{ true };
        enum class MonoInc {
            NotDefined = -1 ,
            Increasing,
            Decreasing
        } isInc;
        isInc = MonoInc::NotDefined;

        // Going through all the items
        for (int i = 0; i < arraySize - 1; i++) {
            // For equal array we can ignore it
            if (A[i + 1] == A[i]) continue;
            
            // Setting the type of inc
            if (isInc == MonoInc::NotDefined) {
                isInc = (A[i + 1] >= A[i]) ? MonoInc::Increasing : MonoInc::Decreasing;
            }

            // This should never change once set
            auto isGreater{ A[i + 1] >= A[i] };
            
            if (isGreater == false && isInc == MonoInc::Increasing ) {
                retValue = false;
                break;
            }
            else if (isGreater == true && isInc == MonoInc::Decreasing) {
                retValue = false;
                break;
            }
        }

        return retValue;
    }
};

void testSolution896() {
    vector<int> input5{ 1,1,1 };
    vector<int> input4{ 1,2,4,5 };
    vector<int> input3{ 1, 3, 2 };
    vector<int> input2{ 6,5,4,4 };
    vector<int> input1{ 1, 2, 2, 3 };

    Solution s;

    cout << s.isMonotonic(input1) << endl;      // Should be true
    cout << s.isMonotonic(input2) << endl;      // Should be true
    cout << s.isMonotonic(input3) << endl;      // Should be false
    cout << s.isMonotonic(input4) << endl;      // Should return true
    cout << s.isMonotonic(input5) << endl;      // Should return true

    vector<int> failedCase1{ 5, 3, 2, 4, 1 };
    cout << s.isMonotonic(failedCase1) << endl; // Should be false
}
