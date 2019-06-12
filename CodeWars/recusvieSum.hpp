#include <string>
#include <sstream>

namespace Codewars {
    using namespace std;

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
}