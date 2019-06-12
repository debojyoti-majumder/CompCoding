#include <string>
#include <sstream>
#include <vector>

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

    int claculateSum(const vector<int>&  items) {
        int sum { 0 };

        return sum;
    }
    // Problem URL: https://www.codewars.com/kata/57b06f90e298a7b53d000a86/train/cpp
    long queueTime(vector<int> customers,int n) {
        // Base case
        if( customers.size() == 0 ) return 0;
        if( n == 1 ) return claculateSum(customers);
        
        return 0;
    }

    GTEST_TEST(CodeWarsQueueTime, DefaultTests) {
        ASSERT_THAT(queueTime(std::vector<int>{}, 1), 0);
        ASSERT_THAT(queueTime(std::vector<int>{1,2,3,4}, 1), 10);
        ASSERT_THAT(queueTime(std::vector<int>{2,2,3,3,4,4}, 2), 9);
        ASSERT_THAT(queueTime(std::vector<int>{1,2,3,4,5}, 100), 5);
    }
}