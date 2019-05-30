/*
    Problem URL:    https://leetcode.com/problems/out-of-boundary-paths/
    Problem ID:     576
    Issue Id:       24
*/

#include <vector>
#include <queue>
#include <iostream>

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

public:
    int findPaths(int m, int n, int N, int i, int j) {
        auto retCount{0};
        _boundary.first = m;
        _boundary.second = n;
        _visitedMatrix = vector<vector<bool>> (
            m,
            vector<bool>(n,false)
        );

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
                    if( currentPos.movesLeft > 2 )
                        retCount += 2;
                    else
                        retCount += 1;

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

int main() {
    Solution s;

    // Should output 6
    cout << s.findPaths(2, 2, 2, 0, 0) << endl;
    
    // Should output 12
    cout << s.findPaths(1, 3, 3, 0, 1) << endl;

    // Getting TLE, should output 121406
    cout << s.findPaths(10, 10, 11, 5, 5) << endl;
    return 0;
}
