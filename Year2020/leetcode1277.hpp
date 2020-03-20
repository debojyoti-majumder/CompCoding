// Problem URL: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Problem ID: 1277

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    private:
        const vector<vector<int>>& _matrix;
        int startX, startY;
        size_t length;

    public:
        // This is container to be used from the caller
        Matrix(const vector<vector<int>>& m) : _matrix(m) {}
        
        // This function defines a square matrix of size l
        void setBounds(int x, int y, size_t l) {
            startX = x;
            startY = y;
            length = l;
        }

        // This makes the zero based indexing work correctly
        int getAt(int x, int y) {
            return 0;
        }
};

class Solution 
{
private:
    int _returnValue;

    bool isAllOneInSquareMatrix(const Matrix& mat) {
        mat;
        return true;
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

            for( int i=0; i<difference; i++ ) {
                Matrix submatrix(matrix);
                submatrix.setBounds(0, i, numberOfColumns - 1);

                if( false == isAllOneInSquareMatrix(submatrix) ) {

                }
            }

            if( allOnes ) _returnValue += 1;
        } 
        else if( numberOfRows > numberOfColumns ) { 
        }
        else {
            // This is the ideal case as we if it a squreMatrix
            Matrix m(matrix);
            m.setBounds(0,0,numberOfRows);

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
    
    vector<vector<int>> matrix = {
        vector<int> {0,1,1,1},
        vector<int> {1,1,1,1},
        vector<int> {0,1,1,1}
    };

    Solution s;
    auto retValue{ s.countSquares(matrix) };
    if (15 == retValue)
        cout << "Test 1 Pased\n";
    else
        cout << "Test 1 Failed\n";

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
}

int main(int, char**) {
    cout << "Running for leet code\n";
    runTestCases();

    return 0;
}
