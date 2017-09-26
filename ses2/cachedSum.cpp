#include <vector>

using namespace std;

struct DataPoint {
	int data;
	int sum;

	DataPoint() : data(0), sum(0) {}
};

class NumMatrix {
private:
	vector<vector<DataPoint>> _computeMatrix;

public:
	NumMatrix(vector<vector<int>> matrix) {
		for (auto row : matrix) {
			auto sum = 0;
			vector<DataPoint> datarow;

			for (auto item : row) {
				DataPoint d;

				d.data = item;
				sum += item;
				d.sum = sum;

				datarow.push_back(d);
			}

			_computeMatrix.push_back(datarow);
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;

		for (auto i = row1; i <= row2; i++){
			auto m = _computeMatrix[i][col1];
			auto n = _computeMatrix[i][col2];

			sum += (n.sum - (m.sum - m.data));
		}

		return sum;
	}
};
