#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\sources\leetcode576.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(Leetcode576Test) {
private:
    Leetcode576::Solution s;

public:
    TEST_METHOD(basicCases) {
        Assert::AreEqual(s.findPaths(2, 2, 2, 0, 0), 6 );
        Assert::AreEqual(s.findPaths(1, 3, 3, 0, 1), 12 );
    }
    };
}