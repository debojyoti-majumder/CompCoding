/*
    Problem URL:    https://leetcode.com/problems/score-after-flipping-matrix/description/
    Problem Id:     861
    Issue Id:       27

    Related Problems:
        https://leetcode.com/problems/three-equal-parts/
        https://leetcode.com/problems/patching-array/
        https://leetcode.com/problems/jump-game-ii/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void flipRowIfRequired(vector<int>& row) {
        vector<int> flippedVector;
        for( const auto& num : row ) {
            if( num == 0 )
                flippedVector.emplace_back(1);
            else
                flippedVector.emplace_back(0);
        }

        auto unflippedValue { calculateVector(row) };
        auto flippedValue { calculateVector(flippedVector) };

        if( flippedValue > unflippedValue )
            row = flippedVector;
    }

    void flipColumIfRequired(vector<vector<int>>& A, size_t colNumber) {
        auto rowSize { A.size() };
        auto oneCount { 0 };
        auto zeroCount { 0 };

        for( size_t i=0; i<rowSize; i++ ) {
            if( A[i][colNumber] == 1 )
                oneCount++;
            else
                zeroCount++;    
        }

        // Then swaping is required
        if( zeroCount > oneCount ) {
            for( size_t i=0; i<rowSize; i++ )
                A[i][colNumber] = !A[i][colNumber];
        }
    }

    int getScore(const vector<vector<int>>& vec) {
        auto sum{ 0 };
        for( const auto& item : vec )
            sum += calculateVector(item);

        return sum;
    }

    int calculateVector(const vector<int>& vec) {
        auto sz { (int) vec.size() };
        int counter { 0 };
        int value = 0;

        for( int i=sz-1; i>=0; i-- ) {
            value += (int) (vec[i] * pow(2,counter));
            counter++;
        }

        return value;
    }

public:
    int matrixScore(vector<vector<int>>& A) {
        // Some basic cases
        if( A.size() == 0 ) return 0;
        
        // Flipping the rows first
        for( auto& row : A ) flipRowIfRequired(row);

        // Flipping the columns
        auto colSize { A[0].size() };
        for( size_t i=0; i<colSize; i++ ) flipColumIfRequired(A, i);

        return getScore(A);      
    }
};

int test861() {
    Solution s;    

    // Should output 39
    vector<vector<int>> mat1 {
        {0,0,1,1}, {1,0,1,0}, {1,1,0,0}
    };
    cout << s.matrixScore(mat1) << endl;

    return 0;
}
