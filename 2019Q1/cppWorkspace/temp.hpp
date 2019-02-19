// Problem URL: https://leetcode.com/problems/minimum-falling-path-sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	// Will return start and end index of matrix;
	pair<int, int> getValidIndexRange(size_t colIndex, const vector<int>& row) {
		pair<size_t, size_t> rowRange{ 0, row.size() };

		rowRange.first = (colIndex == 0) ? 0 : colIndex + 1;
		rowRange.second = (colIndex == row.size() - 1) ? row.size() : colIndex + 2;

		return rowRange;
	}

public:
	int minFallingPathSum(vector<vector<int>>& A) {
		auto numberOfRows = A.size();
		vector<int> costs;

		if (numberOfRows == 1) {
			auto minElement = min_element(A[0].begin(), A[0].end());
			return *minElement;
		}

		for (size_t colIndex = 0; colIndex < A[0].size(); colIndex++) {
			auto subMatrixIndexes = getValidIndexRange(colIndex, A[0]);
			vector<vector<int>> subMatrix;
			
			for (size_t rIndex = 1; rIndex < A.size(); rIndex++) {
				auto startIt = A[rIndex].begin() + subMatrixIndexes.first;
				auto endIt = A[rIndex].begin() + subMatrixIndexes.second;

				subMatrix.emplace_back(vector<int>{startIt, endIt});
			}

			costs.emplace_back(minFallingPathSum(subMatrix) + A[0][colIndex]);
		}

		auto minCost = min_element(costs.begin(), costs.end());
		return *minCost;
	}
};

int main() {
	Solution s;

	vector<vector<int>> input1 = {
		{1,2,3}, {4,5,6}, {7,8,9}
	};

	// Should output 12
	cout << "Test case 1:" << s.minFallingPathSum(input1) << endl;

	return 0;
}
