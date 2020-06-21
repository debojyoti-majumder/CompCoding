// Problem URL: https://leetcode.com/problems/minimum-falling-path-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<size_t, size_t> MatrixLocation;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		return h1 ^ h2;
	}
};

class Solution {
private:
	vector<vector<int>> _matrix;
	size_t _rowSize;
	size_t _colSize;
	unordered_map<MatrixLocation,int,pair_hash> _valueLookup;

	vector<MatrixLocation> getPossiblePaths(MatrixLocation currentLocation) {
		vector<MatrixLocation> possiblePath;
		auto nextRow = currentLocation.first + 1;

		possiblePath.emplace_back(MatrixLocation{ nextRow,currentLocation.second });
		
		// For the item on left
		if (currentLocation.second >= 1)
			possiblePath.emplace_back(MatrixLocation{ nextRow, currentLocation.second - 1 });

		// For the item on the right
		if (currentLocation.second < _colSize - 1)
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
				auto it = _valueLookup.find(point);
				int cost;

				if( it == _valueLookup.end() ) {
					// Cacluting the lower path cost if lookup failed
					auto newPath{ getPossiblePaths(point) };
					cost = getMinCost(newPath);

					// Adding to the cache
					_valueLookup.insert(make_pair(point, cost));
				}
				else {
					cost = it->second;
				}

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

int testSolution() {
	Solution s;

	vector<vector<int>> input1 = { {1,2,3}, {4,5,6}, {7,8,9} };
	vector<vector<int>> input2 = { {3,2,1}, {4,5,6}, {7,8,9} };
	vector<vector<int>> input3 = { {17,82}, {1, -44 } };
	vector<vector<int>> input4 = { {-80,-13,22},{83,94,-5},{73,-48,61} };
	
	vector<vector<int>> tleInput = {
		{-19,-1,-96,48,-94,36,16,55,-42,37,-59,6,-32,96,95,-58,13,-34,94,85},
		{17,44,36,-29,84,80,-34,50,-99,64,13,91,-27,25,-36,57,20,98,-100,-72},
		{-92,-75,86,90,-4,90,64,56,50,-63,10,-15,90,-66,-66,32,-69,-78,1,60},
		{21,51,-47,-43,-14,99,44,90,8,11,99,-62,57,59,69,50,-69,32,85,13},
		{-28,90,12,-18,23,61,-55,-97,6,89,36,26,26,-1,46,-50,79,-45,89,86},
		{-85,-10,49,-10,2,62,41,92,-67,85,86,27,89,-50,77,55,22,-82,-94,-98},
		{-50,53,-23,55,25,-22,76,-93,-7,66,-75,42,-35,-96,-5,4,-92,13,-31,-100},
		{-62,-78,8,-92,86,69,90,-37,81,97,53,-45,34,19,-19,-39,-88,-75,-74,-4},
		{29,53,-91,65,-92,11,49,26,90,-31,17,-84,12,63,-60,-48,40,-49,-48,88},
		{100,-69,80,11,-93,17,28,-94,52,64,-86,30,-9,-53,-8,-68,-33,31,-5,11},
		{9,64,-31,63,-84,-15,-30,-10,67,2,98,73,-77,-37,-96,47,-97,78,-62,-17},
		{-88,-38,-22,-90,54,42,-29,67,-85,-90,-29,81,52,35,13,61,-18,-94,61,-62},
		{-23,-29,-76,-30,-65,23,31,-98,-9,11,75,-1,-84,-90,73,58,72,-48,30,-81},
		{66,-33,91,-6,-94,82,25,-43,-93,-25,-69,10,-71,-65,85,28,-52,76,25,90},
		{-3,78,36,-92,-52,-44,-66,-53,-55,76,-7,76,-73,13,-98,86,-99,-22,61,100},
		{-97,65,2,-93,56,-78,22,56,35,-24,-95,-13,83,-34,-51,-73,2,7,-86,-19},
		{32,94,-14,-13,-6,-55,-21,29,-21,16,67,100,77,-26,-96,22,-5,-53,-92,-36},
		{60,93,-79,76,-91,43,-95,-16,74,-21,85,43,21,-68,-32,-18,18,100,-43,1},
		{87,-31,26,53,26,51,-61,92,-65,17,-41,27,-42,-14,37,-46,46,-31,-74,23},
		{-67,-14,-20,-85,42,36,56,9,11,-66,-59,-55,5,64,-29,77,47,44,-33,-77} 
	};

	cout << "Test case 1:" << s.minFallingPathSum(input1) << endl;		// Should output 12
	cout << "Test case 2:" << s.minFallingPathSum(input2) << endl;		// Should output 13
	cout << "Test case 3:" << s.minFallingPathSum(input3) << endl;		// Should output -27
	cout << "Test case 4:" << s.minFallingPathSum(input4) << endl;		// Should output -66
	cout << "TLE Error:" << s.minFallingPathSum(tleInput) << endl;

	return 0;
}
