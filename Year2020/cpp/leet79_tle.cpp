#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

struct Position {
    int x;
    int y;
    
    bool operator==(const Position& rhs) const {
        if( x == rhs.x and y == rhs.y ) return true;
        else return false;
    }
    
    bool isValid(int xBound, int yBound) const {
        if( x < 0 or y < 0 ) return false;
        if( x >= xBound or y >= yBound ) return false;
        
        return true;
    }
    
    list<Position> getValidPos(int rows,int cols) const {
        list<Position> allPositions;
        allPositions.emplace_back(Position{x-1, y});
        allPositions.emplace_back(Position{x+1, y});
        allPositions.emplace_back(Position{x, y+1});
        allPositions.emplace_back(Position{x, y-1});
        
        list<Position> validPositions;
        for(const auto& p : allPositions ) {
            if( p.isValid((int)rows, (int)cols) ) validPositions.emplace_back(p);
        }
        
        return validPositions;
    }
};

// 79
class Solution {
private:
    string                  _searchWord;
    vector<vector<char>>    _board;
    int                     _rows;
    int                     _cols;
    
    bool isPathFound(vector<Position> path, int strIndex, Position startingPos) {
        char ch { _searchWord[strIndex] };
        
        // Have to look further on the strings
        if( ch == _board[startingPos.x][startingPos.y] ) {
            path.emplace_back(startingPos);
            auto validOptions { startingPos.getValidPos(_rows,_cols) };
            bool bFound = false;
            
            // We have found all the strings
            if( path.size() == _searchWord.size() ) return true;
            
            for( const auto& opts : validOptions ) {
                auto it = find(path.begin(), path.end(), opts);
                
                // We are only cosidering the unvisited node
                if( it == path.end() ) {
                    int idx = strIndex + 1;

                    if( isPathFound(path, idx, opts) ) {
                        bFound = true;
                        break;
                    }
                }
            }
            
            return bFound;
        }
        else
            return false;
    }
    
private:
    bool isAllCharsPresent() {
        int findCount = 0;
        set<char> charSet;
        for( char ch : _searchWord ) charSet.insert(ch);
        
        for( char ch : charSet ) {
            for( const vector<char>& v : _board ) {
                auto it = find(v.begin(),v.end(), ch);
                if( it != v.end() ) {
                    findCount += 1;
                    break;
                }
            }
        }
        
        return findCount == charSet.size();
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        _searchWord = word;
        _board = board;
        _rows = (int)_board.size();
        if( _rows == 0 ) return true;
        _cols = (int)_board[0].size();
        
        if( isAllCharsPresent() == false ) return false;
        
        for( int i=0; i<_rows; i++ ) {
            for(int j=0; j<_cols; j++ ) {
                vector<Position> serachHistory;
                bool bFound = isPathFound(serachHistory, 0, Position{i,j});
                if( bFound ) return true;
            }
        }
        
        return false;
    }
};

int main() {
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    Solution s;
    auto ret = s.exist(board1, "ABCCED");
    cout << "Output:" << ret << endl;
    
    vector<vector<char>> singleCell = {
        {'a'}
    };
    
    ret = s.exist(singleCell, "a");
    cout << "Output 2:" << ret << endl;
    return 0;
}
