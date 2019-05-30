/*
    Problem URL:    https://leetcode.com/problems/out-of-boundary-paths/
    Problem ID:     576
    Issue Id:       24
*/

#include "gtest/gtest.h"

#include <vector>
#include <queue>

namespace Leetcode576 {
    using namespace std;
    
    class Solution {
    private:
        struct Position {
            int x;
            int y;
            int movesLeft;
        };

        // States used by other functions
        pair<int, int> _boundary;
        vector<vector<bool>> _visitedMatrix;

        vector<Position> getPossiblePaths(const Position &currentPos) {
            vector<Position> possiblePaths;

            // There are no more moves left
            if (currentPos.movesLeft < 0)
            return possiblePaths;

            auto toLeft{currentPos};
            toLeft.y--;

            auto toRight{currentPos};
            toRight.y++;

            auto toUp{currentPos};
            toUp.x--;

            auto toDown{currentPos};
            toDown.x++;

            // Adding all the posibilities
            possiblePaths.emplace_back(toLeft);
            possiblePaths.emplace_back(toRight);
            possiblePaths.emplace_back(toUp);
            possiblePaths.emplace_back(toDown);

            return possiblePaths;
        }

        bool isOutside(const Position &pos) {
            if (pos.x < 0 || pos.x >= _boundary.first)
                return true;
            else if (pos.y < 0 || pos.y >= _boundary.second)
                return true;
            else
                return false;
        }

    // Should only be called if isOutside is ture
        int getMovesCount(const Position& pos ) {
            int retVal {1};

            if( pos.movesLeft > 2 ) {
                auto incAmount { pos.movesLeft -2 };

                // Move towards left is possible 
                if( pos.y != 0 ) retVal += incAmount;
                
                // Move towards right is possible
                if( pos.y != _boundary.second - 1 ) retVal += incAmount;

                // Move torwads up 
                if( pos.x != 0 ) retVal += incAmount;

                // Move dowards
                if( pos.x != _boundary.first - 1 ) retVal += incAmount;
            }

            return retVal;
        }

    public:
        int findPaths(int m, int n, int N, int i, int j) {
            auto retCount{0};
            _boundary.first = m;
            _boundary.second = n;
            _visitedMatrix = vector<vector<bool>> (
                m, vector<bool>(n,false) );

            Position startingPosition{i, j, N};
            queue<Position> pendingPosisition;
            pendingPosisition.push(startingPosition);
        
            while (!pendingPosisition.empty())
            {
                // Visiting the current node
                auto currentPos{pendingPosisition.front()};
                pendingPosisition.pop();
                _visitedMatrix[currentPos.x][currentPos.y] = true;

                // Get all the possible coordidate in which the in next move
                auto nextMove { currentPos };
                nextMove.movesLeft--;
                auto paths{getPossiblePaths(nextMove)};
            
                for (const auto &p : paths) {
                    if (isOutside(p)) {
                        // The item can move to left or move to right and come back
                        retCount += getMovesCount(currentPos);
                        retCount = retCount % (int)(pow(10,9) + 7);
                    }
                    else if( _visitedMatrix[p.x][p.y] == false ) {
                        // If already visited not going to explore
                        pendingPosisition.push(p);
                    }
                }
            }

            return retCount;
        }
    };

    TEST(Solution576, BasicTests) {
        Solution s;

        EXPECT_EQ(s.findPaths(2, 2, 2, 0, 0), 6);
        EXPECT_EQ(s.findPaths(1, 3, 3, 0, 1), 12);
    }

    TEST(Solution576, ValidationTest) {
        Solution s;
        EXPECT_EQ(s.findPaths(3, 3, 5, 0, 1), 109);
    }

    TEST(Solution576, TestTLE1) {
        Solution s;
        EXPECT_EQ(s.findPaths(10, 10, 11, 5, 5), 121406);
    }     
}
