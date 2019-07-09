// Problem URL: https://leetcode.com/problems/boats-to-save-people/
// Issue Id: 35

// Comment logs

//  1.  Starting with a greedy approch, dynamic programming does not seems necessary. I don't see many possiblity for the 
//      for the passengers to fit in

// 2.   Would not have worked out because of cases like 4,1 and 3,2 with limit 5

// 3.   Getting TLE error with 50000 input value ranging 200,960 and limit of 1000.
//      This is the exact solution they have provided but they are not removing element from the vector
//      Have taken 67 ms

// 4.  With usage of index run time reduced by half ( 30 ms ) should not have been the case in STL. 
//     Really need to look into your own list implementation 

#include <vector>
#include <algorithm>

// Includs for unit testing
#include "gtest/gtest.h"
#include <random>

namespace Leetcode881 {
    using namespace std;

    class Solution {
    private:
        int _returnValue;

        // Expects the array to be sorted and uses recusion
        void minBoatRequired(vector<int>& people, int limit) {
            auto numberofPeople { people.size() };
            auto origialLimit{ limit };

            // Base case
            if( numberofPeople == 0 ) return;

            auto firstItem { people.front() };
            auto lastItem { people.back() };
            
            // This is kind of a invalid case, if false that means the 
            // boat won't be able to carry them
            if( firstItem > limit && lastItem > limit ) return;

            // This is also kind of a base case
            if( numberofPeople == 1 ) { 
                people.pop_back();
                _returnValue++;
                return;
            }

            // The largest person is on the boat
            limit -= lastItem;
            people.pop_back();
        
            // If true the putting the smallest person with the largest person
            if( limit > 0 && firstItem <= limit) {
                people.erase(people.begin());
            }

            _returnValue++;
        }
    public:
        int numRescueBoatsNotUsed(vector<int>& people, int limit) {
            // Given TLE on 50K length of data
            sort(people.begin(), people.end());
            _returnValue = 0;

            while( false == people.empty() )
                minBoatRequired(people, limit);

            return _returnValue;
        }

        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end());
            auto boatsRequired { 0 };
            int leftIndex { 0 };
            int rightIndex { (int) (people.size() - 1) };

            while( leftIndex <= rightIndex ) {
                // If the lightest person can be fit in with the heaviest person
                auto totalWeight { people[leftIndex] + people[rightIndex] };
                if( totalWeight <= limit && leftIndex != rightIndex )
                    leftIndex++;
                
                // the heaviest person always gets boarded
                rightIndex--;
                boatsRequired++;
            }

            return boatsRequired;
        }
    };

    GTEST_TEST(Leet881, BasicTests) {
        Solution s;
        
        // Should be able to fit in a boat
        vector<int> baseCase{1,2};
        ASSERT_EQ(s.numRescueBoats(baseCase, 3), 1);

        // Got a crash on this test case
        vector<int> inp1 { 2,4 };
        ASSERT_EQ(s.numRescueBoats(inp1, 5), 2);

        // Explanation: // (1, 2), (2) and (3)
        vector<int> input1{3,2,2,1};  
        ASSERT_EQ(s.numRescueBoats(input1, 3), 3);

        // Explanation : // (3), (3), (4), (5)
        vector<int> input2 {3,5,3,4}; 
        ASSERT_EQ(s.numRescueBoats(input2, 5), 4);
    }

    GTEST_TEST(Leet881, LoadTest) {
        Solution s;
        vector<int> input;

        random_device random_device;
        mt19937 random_engine(random_device());
        uniform_int_distribution<int> testInputGenerator(200, 960);

        for(long i=0; i<50000; i++) {
            input.emplace_back(testInputGenerator(random_engine));
        }

        ASSERT_NE(s.numRescueBoats(input,1000),0);
    }
}