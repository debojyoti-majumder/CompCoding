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

    pair<int, int> _boundary;

    vector<Position> getPossiblePaths(const Position &currentPos) {
        vector<Position> possiblePaths;

        // There are no more moves left
        if (currentPos.movesLeft < 0)
            return possiblePaths;

        auto toLeft{currentPos};
        toLeft.x--;

        auto toRight{currentPos};
        toRight.x++;

        auto toUp{currentPos};
        toUp.y--;

        auto toDown{currentPos};
        toDown.y++;

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
    int findPaths(int m, int n, int N, int i, int j)
    {
        auto retCount{0};
        _boundary.first = m;
        _boundary.second = n;

        Position startingPosition{i, j, N};
        queue<Position> pendingPosisition;
        pendingPosisition.push(startingPosition);

        while (!pendingPosisition.empty())
        {
            auto currentPos{pendingPosisition.front()};
            pendingPosisition.pop();
            
            // Get all the possible coordidate in which the in next move
            currentPos.movesLeft--;
            auto paths{getPossiblePaths(currentPos)};
            
            for (const auto &p : paths)
            {
                if (isOutside(p))
                    retCount++;
                else
                    pendingPosisition.push(p);
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
