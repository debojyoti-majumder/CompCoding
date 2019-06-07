/*      Problem URL: https://leetcode.com/problems/merge-intervals/
*       Issue Id: 17

*       Related problems:
            https://leetcode.com/problems/teemo-attacking/
            https://leetcode.com/problems/insert-interval/
*/
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
                auto conflictId { -1 };
                static int idCount;

                for( int i=item.first; i<=item.second; i++ ) {
                    if( _occupencyMap[i] != -1 ) {
                        conflictId = _occupencyMap[i];
                        break;
                    }
                }

                if( conflictId == -1 ) {
                    // No conflict the number can be added correctly
                    idCount++;
                    _rangeIdMap.insert(make_pair(idCount, item));

                    // Update the occupency map
                    for( int i=item.first; i<=item.second; i++ )
                        _occupencyMap[i] = idCount;
                }
                else {
                    // Needs to be merged with the existing interval
                    auto& interval { _rangeIdMap[conflictId] };
                    if( item.first < interval.first ) interval.first = item.first;
                    if( item.second > interval.second ) interval.second = item.second;

                    for( int i=interval.first; i<=interval.second; i++ )
                        _occupencyMap[i] = conflictId;
                }
            }
            
            pair<int,int> getMinMax(const vector<vector<int>>& intervals) {
                auto minVal { intervals[0][0] };
                auto maxVal { intervals[0][1] };

                for( size_t i=1; i<intervals.size(); i++ ) {
                    if( intervals[i][0] < minVal )  minVal = intervals[i][0];
                    if( intervals[i][1] > maxVal )  maxVal = intervals[i][1];
                }

                return make_pair(minVal, maxVal);
            }

        public:
            vector<vector<int>> merge(vector<vector<int>>& intervals) {
                _occupencyMap.clear();
                _rangeIdMap.clear();
                
                auto sz { intervals.size() };
                if( sz <= 1 ) return intervals;

                // -1 means the place is empty
                auto range { getMinMax(intervals) };
                for( auto i=range.first; i<=range.second; i++ )
                    _occupencyMap.insert(make_pair(i, -1));

                for( const auto& interval : intervals )
                    addToMergedSet(make_pair(interval[0],interval[1]));

                
                // There has been no reduction
                if( _rangeIdMap.size() == intervals.size() )
                    return intervals;

                // Converting from map to vector, which is our return type
                // also remvoving redundent items
                vector<vector<int>> returnValue;
                for( const auto& item : _rangeIdMap ) {
                    auto intervalId { item.first };
                    auto intr { item.second };
                    
                    returnValue.emplace_back(vector<int>{intr.first, intr.second});
                }

                return merge(returnValue);
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

    GTEST_TEST(Leet056, Test3) {
        vector<vector<int>> inp{{2,3},{4,5},{6,7},{8,9},{1,10}};
        vector<vector<int>> out{{1,10}};

        Solution s;
        ASSERT_THAT(s.merge(inp), testing::UnorderedElementsAreArray(out));
    }

    GTEST_TEST(Leet056, Test4) {
        vector<vector<int>> inp1 {{2,3},{4,6},{5,7},{3,4}};
        vector<vector<int>> inp2 {{1,4},{5,6}};
        vector<vector<int>> out1 {{2,7}};
        vector<vector<int>> out2 {{1,4},{5,6}};

        Solution s;
        ASSERT_THAT(s.merge(inp1), testing::UnorderedElementsAreArray(out1));
        ASSERT_THAT(s.merge(inp2), testing::UnorderedElementsAreArray(out2));
    }
}