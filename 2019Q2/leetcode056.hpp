// Problem URL: https://leetcode.com/problems/merge-intervals/
// Issue Id: 17

#include <vector>
#include <unordered_map>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace Leetcode056 {
    using namespace std;
        
    class Solution {
        private:
            unordered_map<int,int> _occupencyMap;
            unordered_map<int, pair<int,int>> _rangeIdMap;

            void addToMergedSet(const pair<int,int>& item) {

            }

        public:
            vector<vector<int>> merge(vector<vector<int>>& intervals) {
                _occupencyMap.clear();
                _rangeIdMap.clear();
                
                auto sz { intervals.size() };
                if( sz <= 1 ) return intervals;

                for( const auto& interval : intervals )
                    addToMergedSet(make_pair(interval[0],interval[1]));

                // Converting from map to vector, which is our return type
                vector<vector<int>> returnValue;
                for( const auto& item : _rangeIdMap )
                    returnValue.emplace_back(vector<int>{item.second.first, item.second.second});
                return returnValue;
            }
    };

    GTEST_TEST(Leet056, Test1) {
        vector<vector<int>> inp{{1,3},{2,6},{8,10},{15,18}};
        vector<vector<int>> out{{1,6},{8,10},{15,18}};
        Solution s;

        // Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
        ASSERT_THAT(s.merge(inp), testing::UnorderedElementsAreArray(out));
    }

    GTEST_TEST(Leet056, Test2) {
        vector<vector<int>> inp{{1,4}, {4, 5}};
        vector<vector<int>> out{{1,5}};
        Solution s;

        ASSERT_THAT(s.merge(inp), testing::UnorderedElementsAreArray(out));
    }
}