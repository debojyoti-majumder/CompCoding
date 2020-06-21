// Problem URL: https://leetcode.com/problems/hand-of-straights/
// Problem ID:  846
// Comment: Has a very bad runtime performance, should be improved
// maybe remove the sorting logic might help the performance

#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool handChecker(vector<int>& hand, int W) {
        auto sz{ hand.size() };
        if (sz == 0) return true;

        auto valueRange{ W - 1 };
        auto returnValue{ true };

        auto number{ hand[0] };
        hand.erase(hand.begin());

        for (unsigned int i = 0; i < valueRange; i++) {
            auto it = find_if(hand.begin(), hand.end(), [&](auto& item) {
                return item == (number + 1);
            });

            if (it == hand.end()) {
                returnValue = false;
                break;
            }

            hand.erase(it);
            number += 1;
        }

        if (returnValue) return handChecker(hand, W);

        // Comming outof the loop
        return false;
    }

public:
    bool isNStraightHand(vector<int>& hand, int W) {
        // This is more like a corenr case
        if (W == 1) return true;
        auto sz{ hand.size() };

        if (sz % W != 0) return false;

        sort(hand.begin(), hand.end());
        return handChecker(hand, W);
    }
};

int testcase()
{
    Solution s;
    vector<int> input{ 1,2,3,6,2,3,4,7,8 };
    vector<int> input2{1,2,3,4,5};
    vector<int> input3{ 5,1 };

    // Should output true
    cout << s.isNStraightHand(input, 3) << endl;
    
    // Should output false
    cout << s.isNStraightHand(input2, 4) << endl;
    
    // Should output false
    cout << s.isNStraightHand(input3, 2) << endl;
    return 0;
}
