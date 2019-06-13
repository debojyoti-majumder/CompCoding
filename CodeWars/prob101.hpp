#include <string>
#include <sstream>
#include <vector>
#include "queuetime.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace Codewars {
    using namespace std;
    using namespace testing;

    // Problem URL: https://www.codewars.com/kata/541c8630095125aba6000c00/train/cpp
    int digital_root(int n) {
        if( n < 10 )
            return n;

        stringstream ss;
        ss << n;
        auto numberString { ss.str() };
        auto sum { 0 };

        for( const auto& ch : numberString ) {
            auto number { ch - 48 };
            sum += number;
        }

        return digital_root(sum);
    }

    GTEST_TEST(CodeWarsQueueTime, DefaultTests) {
        ASSERT_THAT(queueTime(std::vector<int>{}, 1), 0);
        ASSERT_THAT(queueTime(std::vector<int>{1,2,3,4}, 1), 10);
        ASSERT_THAT(queueTime(std::vector<int>{2,2,3,3,4,4}, 2), 9);
        ASSERT_THAT(queueTime(std::vector<int>{1,2,3,4,5}, 100), 5);
    }

    GTEST_TEST(CodeWarsQueueTime, MyTests) {
        ASSERT_THAT(queueTime(vector<int>{10, 3, 4, 1}, 2),10); 
    }
}