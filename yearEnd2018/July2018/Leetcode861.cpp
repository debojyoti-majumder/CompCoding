// Problem URL: https://leetcode.com/problems/score-after-flipping-matrix/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct SumInfo {
    int num;                        // Row or col number
    enum SumType {row, col} type;   // Is it row or col
    int sum;
};

class Solution {
    private:
        vector<vector<int>> _matrix;
        int _cost;
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

        void toggleMatrix(const SumInfo& inf) {
            if( inf.type == SumInfo::SumType::row ) {
                // Toggle row
                for( int i=0; i<cols; i++ ) {
                    if( _matrix[inf.num][i] == 0 )
                        _matrix[inf.num][i] == 1;
                    else
                        _matrix[inf.num][i] == 0;
                }
            }
            else {
                // Toggle column
                for( int i=0; i<rows; i++ ) {
                    if( _matrix[i][inf.num] == 0 )
                        _matrix[i][inf.num] = 1;
                    else
                        _matrix[i][inf.num] = 0;
                }
            }
        }

        int computeCost() {
            int sum = 0;

            for(auto r : _matrix) {
                string str;
                for( auto v : r ) {
                    if( v == 0 ) 
                        str +="0";
                    else
                        str +="1";
                }

                bitset<32> bitwiseData(str);
                sum += bitwiseData.to_ulong();
            }

            return sum;
        }

    public:
        int matrixScore(vector<vector<int>>& A) {
            _matrix = A;
            _cost = 0;
            rows = A.size();
            if( rows == 0 ) return 0;
            cols = A[0].size();
            
            while(true) {
                auto sums(getSumInfo());
                auto minItem = min_element(sums.begin(), sums.end(),[](SumInfo& item1, SumInfo& item2) {
                    return item1.sum < item2.sum;
                });

                toggleMatrix(*minItem);
                auto cst = computeCost();

                if(cst < _cost )
                    break;
                
                _cost = cst;
            }

            return _cost;
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
