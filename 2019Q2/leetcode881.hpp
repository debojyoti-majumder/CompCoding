// Problem URL: https://leetcode.com/problems/boats-to-save-people/
// Issue Id: 35

// Comment logs

//  1.  Starting with a greedy approch, dynamic programming does not seems necessary. I don't see many possiblity for the 
//      for the passengers to fit in

// 2.   Would not have worked out because of cases like 4,1 and 3,2 with limit 5

// 3.   Getting TLE error with 50000 input value ranging 200,960 and limit of 1000

#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

namespace Leetcode881 {
    using namespace std;

    class Solution {
    private:
        int minBoatRequired(vector<int>& people, int limit) {
            auto numberofPeople { people.size() };
            auto origialLimit{ limit };

            // Base case
            if( numberofPeople == 0 ) return 0;

            auto firstItem { people.front() };
            auto lastItem { people.back() };
            
            // This is kind of a invalid case, if false that means the 
            // boat won't be able to carry them
            if( firstItem > limit && lastItem > limit ) return 0;

            // This is also kind of a base case
            if( numberofPeople == 1 ) return 1;

            // The largest person is on the boat
            limit -= lastItem;
            people.pop_back();
        
            // If true the putting the smallest person with the largest person
            if( limit > 0 && firstItem <= limit) {
                people.erase(people.begin());
            }

            // Finding boat with the rest of the people
            return 1 + minBoatRequired(people, origialLimit);
        }

    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end());
            return minBoatRequired(people, limit);            
        }
    };

    GTEST_TEST(Leet881, BasicTests) {
        Solution s;
        
        // Should be able to fit in a boat
        vector<int> baseCase{1,2};
        ASSERT_EQ(s.numRescueBoats(baseCase, 3), 1);

        // Explanation: // (1, 2), (2) and (3)
        vector<int> input1{3,2,2,1};  
        ASSERT_EQ(s.numRescueBoats(input1, 3), 3);

        // Explanation : // (3), (3), (4), (5)
        vector<int> input2 {3,5,3,4}; 
        ASSERT_EQ(s.numRescueBoats(input2, 5), 4);
    }

    GTEST_TEST(Leet881, ExTest) {
        Solution s;

        vector<int> inp1 { 2,4 };
        ASSERT_EQ(s.numRescueBoats(inp1, 5), 2);
    }
}