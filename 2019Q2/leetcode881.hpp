// Problem URL: https://leetcode.com/problems/boats-to-save-people/
// Issue Id: 35

// Comment logs

//  1.  Starting with a greedy approch, dynamic programming does not seems necessary. I don't see many possiblity for the 
//      for the passengers to sit in

#include <vector>
#include <list>
#include "gtest/gtest.h"

namespace Leetcode881 {
    using namespace std;

    class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            auto numberOfPeople { people.size() };
            auto originalLimit { limit };

            list<vector<int>::iterator> canBeFitInBoat;

            if( numberOfPeople == 0 ) return 0;

            for(size_t i=0; i<numberOfPeople; i++) {
                // This means the boat is full
                if( limit == 0 ) break;
                
                // Assigning the persons in the boat
                if( people[i] <= limit ) {
                    limit -= people[i];
                    canBeFitInBoat.emplace_back(people.begin() + i);
                }
            }

            for( const auto& it : canBeFitInBoat ) {
                people.erase(it);
            }

            return 1 + numRescueBoats(people, originalLimit);
        }
    };

    GTEST_TEST(Leet881, BasicTests) {
        Solution s;
        vector<int> baseCase{1,2};
        vector<int> input1{3,2,2,1};  
        vector<int> input2 {3,5,3,4}; 

        // Should be able to fit in a boat
        ASSERT_EQ(s.numRescueBoats(baseCase, 3), 1);

        // Explanation: // (1, 2), (2) and (3)
        ASSERT_EQ(s.numRescueBoats(input1, 3), 3);

        // Explanation : // (3), (3), (4), (5)
        ASSERT_EQ(s.numRescueBoats(input2, 5), 4);
    }
}