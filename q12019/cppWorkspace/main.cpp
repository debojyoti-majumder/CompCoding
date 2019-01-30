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

        return newPosition;
    }

    bool isValidPos(const pair<int,int>& pos) {
        auto rowCount = _visitedMatrix.size();
        if( rowCount == 0 )
            return false;

        // If visted then not valid
        if( _visitedMatrix[pos.first][pos.second] ) 
            return false;
                    
        // Bound checking for row
        if( pos.first < 0 || pos.first >= rowCount )
            return false;
        
        // Bound checking for column
        auto colCount = _visitedMatrix[0].size();
        if( pos.second < 0 || pos.second >= colCount )
            return false;

        return true;
    }

    inline void changeDirection() {
        _direction = ( _direction + 1 ) % 4;
    }

    bool getNextPos() {
        auto validPosFound = false;
        
        // Looking for next valid position
        for(int i=0; i<4; i++) {
            auto nextPos = getNextIndex();
            auto isValid = isValidPos(nextPos);

            // Don't have to look for other position
            if( isValid ) {
                _currentPos = nextPos;
                validPosFound = true;
                break;
            }
            else 
                changeDirection();
        }

        return validPosFound;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> returnCollection{};
        _visitedMatrix.clear();
        _direction = 1;
        _currentPos.first = 0, _currentPos.second = 0;

        // Initilizing the visited matrix
        for(const auto& row: matrix) 
            _visitedMatrix.emplace_back(vector<bool>(row.size(), false));

        do {
            returnCollection.emplace_back(matrix[_currentPos.first][_currentPos.second]);
            _visitedMatrix[_currentPos.first][_currentPos.second] = true;
        } while(getNextPos()) ;

        return returnCollection;        
    }
};

int main() {
    vector<vector<int>> testCase1{
        vector<int> {1,2,3},
        vector<int> {4,5,6},
        vector<int> {7,8,9}
    };

    Solution s;
    auto iter = s.spiralOrder(testCase1);

    for( const auto& item : iter )
        cout << item << " ";
    cout << endl;

    return 0;
}