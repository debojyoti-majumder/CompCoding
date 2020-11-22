// CPPWorkspace.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

// Problem URL: https://leetcode.com/problems/shuffle-the-array/
// Status: Accepted

class Solution {
public:
    // Going to use inplace replacement to save memory
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        auto it = nums.begin();

        for (int i = 0; i < n; i++) {
            auto targetElement = it + n;

            it = nums.insert(it + 1, *targetElement);
            it++;
        }

        nums.erase(nums.begin() + 2 * n, nums.end());
        return nums;
    }
};

bool ElementWiseCompaison (
    const std::vector<int>& firstVector,
    const std::vector<int>& secondVector
) {
    bool bRet = true;
    size_t compSize = firstVector.size();

    if (compSize != secondVector.size()) return false;

    auto firstIt = firstVector.begin();
    for (auto secondIt = secondVector.begin(); secondIt != secondVector.end(); secondIt++, firstIt++) {
        if (*secondIt != *firstIt) {
            bRet = false;
            break;
        }
    }

    return bRet;
}

int main() {
    std::vector<int> inputArray{ 1,2,3,10,20,30 };
    Solution s;

    auto retValue = s.shuffle(inputArray, 3);
    std::vector<int> expectedValues{ 1, 10, 2, 20, 3, 30 };

    // Doing element wise comparison
    std::cout << ElementWiseCompaison(retValue, expectedValues) << std::endl;
    return 0;
}
