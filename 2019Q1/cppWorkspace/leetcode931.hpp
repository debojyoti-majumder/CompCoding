// Problem URL: https://leetcode.com/problems/minimum-falling-path-sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int>> _matrix;
	size_t              _rowIndex;

	// Will return start and end index of matrix;
	pair<size_t, size_t> getValidIndexRange() {
		pair<size_t, size_t> arrayBound{ -1,-1 };

		arrayBound.first = (_rowIndex > 0) ? _rowIndex - 1 : _rowIndex;
		arrayBound.second = (_rowIndex < _matrix[0].size() - 1) ? _rowIndex + 1 : _rowIndex;

		return arrayBound;
	}

public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int minWeight = 0;

		// Some safe checking
		if (A.size() == 0)
			return minWeight;

		// Intilizing the states
		_matrix = A;
		pair<size_t, size_t> subArrayPos{ 0, _matrix[0].size() - 1};

		for (size_t row = 0; row < _matrix.size(); row++) {
			auto matrixRow{ _matrix[row] };
			auto minElement = min_element(matrixRow.begin() + subArrayPos.first, 
								matrixRow.begin() + subArrayPos.second + 1);

			// Adding the mininum weight
			minWeight += *minElement;

			// Getting the next index for the next row
			_rowIndex = minElement - matrixRow.begin();
			subArrayPos = getValidIndexRange();
		}

		return minWeight;
	}
};

int main() {
	Solution s;

	vector<vector<int>> input1 = { {1,2,3}, {4,5,6}, {7,8,9} };
	vector<vector<int>> input2 = { {3,2,1}, {4,5,6}, {7,8,9} };
	vector<vector<int>> input3 = { {17,82}, {1, -44 } };
	vector<vector<int>> input4 = { {-80,-13,22},{83,94,-5},{73,-48,61} };

	cout << "Test case 1:" << s.minFallingPathSum(input1) << endl;		// Should output 12
	cout << "Test case 2:" << s.minFallingPathSum(input2) << endl;		// Should output 13
	cout << "Test case 3:" << s.minFallingPathSum(input3) << endl;		// Should output -27
	cout << "Test case 4:" << s.minFallingPathSum(input4) << endl;		// Should output -66

	return 0;
}
