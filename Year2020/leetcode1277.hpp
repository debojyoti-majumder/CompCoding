// Problem URL: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Problem ID: 1277

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int,int> Point;

class SquareMatrix {
    private:
        const vector<vector<int>>&  _matrix;
        Point                       _originPoint;
        size_t                      _length;

    public:
        // This is container to be used from the caller
        SquareMatrix(const vector<vector<int>>& m) : _matrix(m) {}
        SquareMatrix(const SquareMatrix&) = default;

        // This function defines a square matrix of size l
        void setBounds(const Point& p, size_t l) {
            _originPoint = p;
            _length = l;
        }

        // This makes the zero based indexing work correctly
        int getAt(int x, int y) const {
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
    bool isAllOneInSquareMatrix(const SquareMatrix& mat) {
        auto length = mat.getLength();
        auto startingPoint { mat.getOrigin() };
        auto counter {0};
        auto subMatLength { length - 1 };
        const auto subProblems { 4 };

        // This is a base case
        if( length == 1 ) return mat.getAt(0,0) == 1;
        
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

        if( numberOfColumns > numberOfRows ) {
            auto difference = numberOfColumns - numberOfRows;
            auto allOnes{ true };

            // Sliding windoing through the sub matrixes
            for( int i=0; i<difference; i++ ) {
                SquareMatrix submatrix(matrix);
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
                SquareMatrix subMatrix(matrix);
                subMatrix.setBounds(Point{i,0}, numberOfColumns);

                if( false == isAllOneInSquareMatrix(subMatrix) ) allOnes = false;
            }

            // If all sub squares are 1 then the bigger square have all ones
            if( allOnes ) _returnValue +=1;
        }
        else {
            // This is the ideal case as we if it a squreMatrix
            SquareMatrix m(matrix);
            m.setBounds(Point{0,0}, numberOfRows);

            if( isAllOneInSquareMatrix(m) ) _returnValue += 1;
        }

        return _returnValue;
    }
};

void runTestCases() {
    //Input: matrix =
    //    [
    //        [0, 1, 1, 1],
    //        [1, 1, 1, 1],
    //        [0, 1, 1, 1]
    //    ]
    //       Output : 15
    //           Explanation :
    //           There are 10 squares of side 1.
    //           There are 4 squares of side 2.
    //           There is  1 square of side 3.
    //           Total number of squares = 10 + 4 + 1 = 15.


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
    if (7 == retValue)
        cout << "Test 2 Pased\n";
    else
        cout << "Test 2 Failed\n";

   retValue = s.countSquares(matrix);
    if (15 == retValue)
        cout << "Test 1 Pased\n";
    else
        cout << "Test 1 Failed\n";    
}

int main(int, char**) {
    cout << "Running for leet code\n";
    runTestCases();

    return 0;
}
