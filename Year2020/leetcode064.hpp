// Problem URL: https://leetcode.com/problems/minimum-path-sum/

#include <vector>
#include <map>
#include <queue>

using namespace std;

struct OriginPoint {
    int x;
    int y;
    int calValue;
};

class Solution064 {
private:
    // map<OriginPoint, int>   _dpTable;
    queue<OriginPoint>      _points;
    size_t                  _rowSize;
    size_t                  _colSize;

    vector<OriginPoint> getValiMoves(const OriginPoint& p) {
        OriginPoint down { p.x , p.y + 1 };
        OriginPoint right { p.x + 1, p.y };
        vector<OriginPoint> retValue;

        if( isValidPoint(down) ) retValue.emplace_back(down);
        if( isValidPoint(right) ) retValue.emplace_back(right);

        return retValue;
    }

    inline bool isValidPoint(const OriginPoint& pt) const {
        return (pt.x < _rowSize && pt.y < _colSize);
    }

    inline bool isEndPoint(const OriginPoint& p) const {
        if( p.x == _rowSize - 1 && p.y == _colSize - 1) return true;
        return false;
    }

    int getMinCostFromPoint(const vector<vector<int>>& inp) {
        auto minVal {0};

        while( false == _points.empty() ) {
            auto pt { _points.front() };
            _points.pop();
            auto isEnd { isEndPoint(pt) };

            if( false == isEnd ) {
                auto moves { getValiMoves(pt) };
                
                // This is where the search branching is happeing
                for(const auto& p : moves ) { 
                    auto newCalcVal = pt.calValue + inp[p.x][p.y];
                    _points.push(OriginPoint{ p.x,p.y, newCalcVal});
                }
            }
            // Updaing the mininum value
            else {
                if( minVal == 0 ) 
                    minVal = pt.calValue;
                else if( pt.calValue < minVal )
                    minVal = pt.calValue;
            }
        }
       
        return minVal;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        // Setting the bounds
        _rowSize = grid.size();
        if( _rowSize == 0 ) return 0;
        _colSize = grid[0].size();

        // setting the initial condition
        OriginPoint pt{ 0,0, grid[0][0] };
        _points.push(pt);

        // Calling the main method
        return getMinCostFromPoint(grid);      
    }
};

TEST(Solution064, basicCase) {
    vector<vector<int>> input = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    // Basic test case
    Solution064 s;
    EXPECT_EQ(s.minPathSum(input), 7);

    vector<vector<int>> empty;
    EXPECT_EQ(Solution064().minPathSum(empty), 0);
}

TEST(Solution064, TLECase) {
    vector<vector<int>> bigArray {
        {7,1,3,5,8,9,9,2,1,9,0,8,3,1,6,6,9,5},
        {9,5,9,4,0,4,8,8,9,5,7,3,6,6,6,9,1,6},
        {8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8},
        {6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4},
        {7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4},
        {9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9},
        {1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4},
        {3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2},
        {1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3},
        {5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7},
        {2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7},
        {0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9}
    };

    EXPECT_GE(Solution064().minPathSum(bigArray), 0);
}
