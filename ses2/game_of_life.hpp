// Leetcode url: https://leetcode.com/problems/game-of-life/description/

#include <vector>
#include <iostream>

using namespace std;

struct Position {
    int x;
    int y;
};

class Solution {
private:
    vector<vector<int>> _board;
    
    vector<struct Position> getNeighbors (const struct Position& p) const {
        // Covering some base cases
        if( _board.size() == 0 ) {
            return {};
        }
        
        vector<struct Position> neighbors;
        vector<struct Position> valid_neighbors;
        
        neighbors.push_back({p.x-1,p.y-1});
        neighbors.push_back({p.x,p.y-1});
        neighbors.push_back({p.x+1,p.y-1});
        
        neighbors.push_back({p.x-1,p.y});
        neighbors.push_back({p.x+1,p.y});
        
        neighbors.push_back({p.x-1,p.y+1});
        neighbors.push_back({p.x,p.y+1});
        neighbors.push_back({p.x+1,p.y+1});
        
        auto y_bound = _board.size();
        auto x_bound = _board[0].size();

        for( auto n : neighbors ) {
            if( n.y >=0 && n.y<y_bound && n.x >= 0 && n.x < x_bound)
                valid_neighbors.push_back(n);
        }
        
        return valid_neighbors;
    }
    
    unsigned int getLiveCount(vector<vector<int>>& b, const vector<struct Position>& cells) {
        auto count = 0;
        
        for( auto cell : cells ) {
            if( b[cell.y][cell.x] == 1 )
                count++;
        }
        
        return count; 
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        _board = board;
        
        for(auto i=0; i<board.size(); i++) {
            for(auto j=0; j<board[i].size(); j++) {
                auto ne = getNeighbors({j,i});
                auto live_count = getLiveCount(board, ne);

                if( board[i][j] == 1 ) {
                    if( live_count < 2 || live_count > 3 ) {
                        _board[i][j] = 0;
                    }
                }
                else {
                    // Dead cells become alive if 3 life is there
                    _board[i][j] = live_count == 3 ? 1 : 0;
                }
            }
        }

        board = _board;
    }
};

void print2dVec(vector<vector<int>> test2) {
    for(auto r : test2 ) {
        cout << "[ ";

        for(auto p: r) {
            cout << p << " ";
        }
        cout << "],";
    }

    cout << endl;
}

int main() {
    vector<vector<int>> test1;
    test1.push_back({0,0});

    Solution s;
    s.gameOfLife(test1);
    print2dVec(test1);

    vector<vector<int>> test2{{0,0,1,1}, {1,1,0,0} ,{1,0,0,0} ,{0,0,0,0}};
    s.gameOfLife(test2); // Expected: [[0,1,1,0],[1,1,1,0],[1,1,0,0],[0,0,0,0]]
    print2dVec(test2);

    cout << endl;
}
