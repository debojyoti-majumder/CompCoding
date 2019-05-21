/*
    Problem URL:    https://leetcode.com/problems/out-of-boundary-paths/
    Problem ID:     576
    Issue number:   24
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<bool>> _visitedMatrix;
    
    // Represents the visit cursor
    struct Position {
        int x;
        int y;
        int movesLeft;
    };

    vector<Position> getAllPosition(const Position& startPos) {
        vector<Position> positions;

        return positions;
    }

    bool isOutside(const Position& pos) {
        return false;
    }

    int performBFS(const Position& startPosistion) {
        int pathCount { 0 };

        // Queue for pending items to visit
        queue<Position> visitQueue;
        visitQueue.emplace(startPosistion);

        while( false == visitQueue.empty() ) {
            // Taking the first item from the queue
            auto item { visitQueue.front() };
            visitQueue.pop();
            auto isOut { isOutside(item) };

            // Later on the code flow we don't have to worry 
            // about indexes
            if( isOut ) {
                pathCount++;
                continue;
            }

            // Visitng an unvisited node with non zero moves left
            auto isVisited { _visitedMatrix[item.x][item.y] };
            if( false == isVisited && item.movesLeft != 0 ) {
                _visitedMatrix[item.x][item.y] = true;
                auto nextPositions { getAllPosition(item) };

                for( auto pos : nextPositions ) {
                    pos.movesLeft--;
                    visitQueue.emplace(pos);
                }
            }
        }

        return pathCount;
    }

public:
    int findPaths(int m, int n, int N, int i, int j) {
        // Resetting the program states
        _visitedMatrix.clear();
    
        // Creating a matrix to remember if we have already visisted the matrix or not
        for( auto i=0; i<m; i++ ) {
            vector<bool> visitMask(n, false);
            _visitedMatrix.emplace_back(visitMask);
        }

        // Calling the BFS algo
        Position pos{ i, j, N };
        return performBFS(pos);        
    }
};

void test576() {
    Solution s;

    // Should output 6
    cout << s.findPaths(2,2,2,0,0) << endl;

    // Should output 12
    cout << s.findPaths(1,3,3,0,1);
}

int main() {
    test576();
    return 0;
}
