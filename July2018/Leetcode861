// Problem URL: https://leetcode.com/problems/score-after-flipping-matrix/description/

#include <iostream>
#include <vector>

using namespace std;

struct SumInfo {
    int num;                        // Row or col number
    enum SumType {row, col} type;   // Is it row or col
    int sum;
};

class Solution {
    private:
        vector<vector<int>> _matrix;
        size_t rows;
        size_t cols;

        vector<SumInfo> getSumInfo() {
            vector<SumInfo> infos;

            for(size_t i=0; i<rows; i++) {
                int sum = 0;
                for( auto m : _matrix[i] )
                    sum += m;
                
                SumInfo inf{(int)i,SumInfo::SumType::row,sum};
                infos.push_back(inf);
            }

            for(size_t i=0; i<cols; i++) {
                int sum = 0;
                for(size_t j=0; j<rows; j++)
                    sum += _matrix[j][i];
                
                infos.push_back(SumInfo{(int)i,SumInfo::SumType::col,sum});
            }

            return infos;
        }

    public:
        int matrixScore(vector<vector<int>>& A) {
            _matrix = A;
            rows = A.size();
            if( rows == 0 ) return 0;
            cols = A[0].size();
            
            auto sums(getSumInfo());

            return (int)sums.size();
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> matxrix{
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };
    Solution s;
    cout << s.matrixScore(matxrix) << endl;
    return 0;
}
