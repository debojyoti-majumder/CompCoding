// Problem URL: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Problem ID: 1277

#include <iostream>
#include <vector>
#include <set>
#include <gtest/gtest.h>

using namespace std;

typedef pair<int,int> Point;
typedef pair<int,bool> MatrixCell; // first = value second = isVisited

class SquareMatrix {
    private:
        vector<vector<MatrixCell>>&  _matrix;
        Point                       _originPoint;
        size_t                      _length;

    public:
        static vector<vector<MatrixCell>> buildMatrixCells(const vector<vector<int>>& m) {
            vector<vector<MatrixCell>> matrix;

            for( size_t i=0; i<m.size(); i++ ) {
                // The first field is for the value and the second one if it has been visited or not
                vector<MatrixCell> row;
                for( size_t j=0; j<m[0].size(); j++ )
                    row.emplace_back(MatrixCell{m[i][j], false});

                matrix.emplace_back(row);
            }

            return matrix;
        }

        SquareMatrix(vector<vector<MatrixCell>>& m) : _matrix(m) {
            _length = 0;
        }
        
        // This function defines a square matrix of size l
        void setBounds(const Point& p, size_t l) {
            _originPoint = p;
            _length = l;
        }

        // This makes the zero based indexing work correctly
        MatrixCell& getAt(int x, int y) {
            return _matrix[_originPoint.first + x][_originPoint.second + y];
        }

        // Accessor methods to work with matrix
        inline size_t getLength() const { return _length; }
        inline Point getOrigin() const { return _originPoint; }
};

class Solution 
{
private:
    int _returnValue;

    // This method would always expect a square matrix, and work on it based on that
    // a squre matrix of n an be broken into 4 sub-matrixes of size n - 1. 
    bool isAllOneInSquareMatrix(SquareMatrix& mat) {
        auto length = mat.getLength();
        auto startingPoint { mat.getOrigin() };
        auto counter {0};
        auto subMatLength { length - 1 };
        const auto subProblems { 4 };

        // This is a base case, checking against 1
        if( length == 1 ) {
            auto zeroItem { mat.getAt(0,0) };
            auto retValue { false };

            if( 1 == zeroItem.first ) {
                // We would not want to caluate a single cell twice
                if( false == zeroItem.second ) {
                    _returnValue += 1;
                    zeroItem.second = true;
                }

                retValue = true;
            }
            
            return retValue;
        }
        
        // Building the submatrixs
        Point origins[subProblems];
        origins[0] = Point{startingPoint.first, startingPoint.second};
        origins[1] = Point{startingPoint.first, startingPoint.second + 1};
        origins[2] = Point{startingPoint.first + 1, startingPoint.second};
        origins[3] = Point{startingPoint.first + 1, startingPoint.second + 1};

        // This is BFS
        for( auto i=0; i<subProblems; i++ ) {
            SquareMatrix subMat{mat};
            subMat.setBounds(origins[i], subMatLength);

            // Recusrive call
            if( isAllOneInSquareMatrix(subMat) ) counter += 1;
        }

        // Would return true if all the submatrix are true 
        return counter == 4;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        // Initialization for iretaions to be done    
        _returnValue = 0;
        auto numberOfColumns { matrix[0].size() };
        auto numberOfRows { matrix.size() };
        auto matCells { SquareMatrix::buildMatrixCells(matrix) };

        if( numberOfColumns > numberOfRows ) {
            auto difference = numberOfColumns - numberOfRows;
            auto allOnes{ true };

            // Sliding windoing through the sub matrixes
            for( int i=0; i<difference; i++ ) {
                SquareMatrix submatrix(matCells);
                submatrix.setBounds(Point{0,i}, numberOfRows);

                if( false == isAllOneInSquareMatrix(submatrix) ) {
                    allOnes = false;
                }
            }

            if( allOnes ) _returnValue += 1;
        } 
        else if( numberOfRows > numberOfColumns ) { 
            auto difference = numberOfRows - numberOfColumns;
            auto allOnes{ true };

            // Sliding with square matrix based on 
            for( int i=0; i<difference; i++ ) {
                SquareMatrix subMatrix(matCells);
                subMatrix.setBounds(Point{i,0}, numberOfColumns);

                if( false == isAllOneInSquareMatrix(subMatrix) ) allOnes = false;
            }

            // If all sub squares are 1 then the bigger square have all ones
            if( allOnes ) _returnValue +=1;
        }
        else {
            // This is the ideal case as we if it a squreMatrix
            SquareMatrix m(matCells);
            m.setBounds(Point{0,0}, numberOfRows);

            if( isAllOneInSquareMatrix(m) ) _returnValue += 1;
        }

        return _returnValue;
    }
};

TEST(Prob1277, basicCases) {
    Solution s;
    auto retValue { 0 };

    vector<vector<int>> matrix = {
        vector<int> {0,1,1,1},
        vector<int> {1,1,1,1},
        vector<int> {0,1,1,1}
    };

    vector<vector<int>> matrix2 = {
        vector<int> {0,1,0},
        vector<int> {1,1,0},
        vector<int> {1,1,0}
    };

    retValue = s.countSquares(matrix2);
    EXPECT_EQ(retValue, 7);

    retValue = s.countSquares(matrix);
    EXPECT_EQ(retValue, 15);
}
