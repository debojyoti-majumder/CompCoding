#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\sources\Leetcode319.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(Leetcode319Test) {
    private:
        Leetcode319::Solution s;

    public:
        TEST_METHOD(Case1) {
            Assert::AreEqual(s.bulbSwitch(3), 1);
        }

        TEST_METHOD(Case2) {
            Assert::AreEqual(s.bulbSwitch(18), 4);
        }
    };
}