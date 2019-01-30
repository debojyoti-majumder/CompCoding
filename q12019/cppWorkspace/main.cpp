// Problem URL: https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 0 means to right, 1 means down, 2 mean left, 3 means up

class Solution {
private:
    vector<vector<bool>>    _visitedMatrix;
    int                     _direction;
    pair<int,int>           _currentPos;

    pair<int,int> getNextIndex() {
        // These are the x and y cordinates
        pair<int,int> newPosition = _currentPos;

        switch (_direction) {
            case 0:
                newPosition.second++;
                break;
                
            case 1:
                newPosition.first++;
                break;
     
            case 2:
                newPosition.second--;
                break;
     
            case 3:
                newPosition.first--;
                break;
     
            default:
                break;
        }
    }

    bool isValidPos(const pair<int,int>& pos) {
        return true;
    }

    inline void changeDirection() {
        _direction = ( _direction + 1 ) % 4;
    }

    bool getNextPos() {
        auto validPosFound = false;
        for(int i=0; i<4; i++) {

        }
        return validPosFound;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> returnCollection{};
        _visitedMatrix.clear();
        _direction = 1;
        _currentPos.first = 0, _currentPos.second = 0;

        do {
            returnCollection.emplace_back(matrix[_currentPos.first][_currentPos.second]);
            _visitedMatrix[_currentPos.first][_currentPos.second] = true;
        } while(getNextPos()) ;

        return returnCollection;        
    }
};

int main() {
    return 0;
}