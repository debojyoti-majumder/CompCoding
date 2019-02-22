// Problem URL: https://leetcode.com/problems/minimum-falling-path-sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<size_t, size_t> MatrixLocation;

class Solution {
private:
	vector<vector<int>> _matrix;
	size_t _rowSize;
	size_t _colSize;

	vector<MatrixLocation> getPossiblePaths(MatrixLocation currentLocation) {
		vector<MatrixLocation> possiblePath;
		auto nextRow = currentLocation.first + 1;

		possiblePath.emplace_back(MatrixLocation{ nextRow,currentLocation.second });
		
		// For item on the right
		if (currentLocation.second >= 1)
			possiblePath.emplace_back(MatrixLocation{ nextRow, currentLocation.second - 1 });

		// For the item on the right
		if (currentLocation.second < _colSize - 2)
			possiblePath.emplace_back(MatrixLocation{ nextRow, currentLocation.second + 1 });

		return possiblePath;
	}

	int getMinCost(const vector<MatrixLocation>& paths) {
		vector<int> costs;
		
		// This is to handle empty inputs, all paths will have same first index
		if (paths.size() == 0) return 0;
		auto depth = paths[0].first;

		if (depth != _rowSize - 1) {
			for (const auto& point : paths) {
				// Cacluting the lower path cost
				auto newPath{ getPossiblePaths(point) };
				auto cost = getMinCost(newPath);

				// Adding the cost of the node also
				cost += _matrix[point.first][point.second];
				costs.emplace_back(cost);
			}
		}
		else {
			// This is the base case
			for (const auto& point : paths)
				costs.emplace_back(_matrix[point.first][point.second]);
		}

		auto minValue = min_element(costs.begin(), costs.end());
		return *minValue;
	};

public:
	int minFallingPathSum(vector<vector<int>>& A) {
		_matrix = A;
		_rowSize = _matrix.size();
		if (_rowSize == 0)
			return 0;
		_colSize = _matrix[0].size();

		// Intilizing the paths, the intial path can start from any point
		vector<MatrixLocation> firstrowPaths;
		for (size_t sz = 0; sz < A[0].size(); sz++) {
			firstrowPaths.emplace_back(MatrixLocation{ 0,sz });
		}

		return getMinCost(firstrowPaths);
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
