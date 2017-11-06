// Leetcode url: https://leetcode.com/problems/game-of-life/description/

struct Position {
    int x;
    int y;
};

class Solution {
private:
    vector<vector<int>> _board;
    vector<vector<int>> _tempboard;
    
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
        
        for( auto n : neighbors ) {
            if( n.x >= 0 && n.x < _board[0].size() && n.y >= 0 && n.y < _board.size() )
                valid_neighbors.push_back({n.x,n.y});
        }
        
        return valid_neighbors;
    }
    
    unsigned int getLiveCount(vector<struct Position> cells) {
        auto count = 0;
        
        for( auto cell : cells ) {
            if( _board[cell.x][cell.y] == 1 )
                count++;
        }
        
        return count; 
    }
    
    bool checkForRule1(struct Position p) {
        if( _board[p.x][p.y] == 1 ) {
            auto live_count = getLiveCount(getNeighbors(p));
        
            if( live_count < 2 ) {
                _tempboard[p.x][p.y] = 0;
                return true;
            }
            else {
                _tempboard[p.x][p.y] = 1;
                return false;
            }
        }
        
        return false;
    }
    
    bool checkForRule2(struct Position p) {
        if( _board[p.x][p.y] == 1 ) {
            auto live_count = getLiveCount(getNeighbors(p));
            
            if( live_count == 2 || live_count == 3 ) {
                _tempboard[p.x][p.y] = 1;
                return true;
            }
        }
        
        _tempboard[p.x][p.y] = 0;
        return false;
    }
    
    bool checkForRule3(struct Position p) {
        if( _board[p.x][p.y] == 1 ) {
            auto live_count = getLiveCount(getNeighbors(p));
            if( live_count > 3 ) {
                _tempboard[p.x][p.y] = 0;
                return true;
            }
        }
        
        _tempboard[p.x][p.y] = 0;
        return false;
    }
    
    bool checkForRule4(struct Position p) {
        if( _board[p.x][p.y] == 0 ) {
            auto live_count = getLiveCount(getNeighbors(p));
            if( live_count == 3 ) {
                _board[p.x][p.y] == 1;
                return true;
            }   
        }
        
        return false;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        _board = board;
        _tempboard = board;
        
        for( auto i=0; i<board.size(); i++ ) {
            for( auto j=0; j<board[i].size(); j++ ) {
                auto res = checkForRule1({i,j});
                if( res )   continue;
                
                res = checkForRule2({i,j});
                if( res )   continue;
                
                res = checkForRule3({i,j});
                if( res )   continue;
                
                checkForRule4({i,j});
            }
        }
        
        board = _tempboard;
    }
};
