// Problem URL: http://adventofcode.com/2017/day/2

#include "FileInput.hpp"
#include <vector>
#include <algorithm>
#include <tuple>

class ChecksumCalc {
	private:
		tuple<int,int> getMinAndMax(vector<int> row) {
			long mx, lw;

			// Covering base case
			if (row.size() == 0)
				return std::make_tuple(0,0);

			mx = row[0], lw = row[0];
			for (auto item : row) {
				if (item > mx) mx = item;
				if (item < lw) lw = item;
			}

			return std::make_tuple(mx, lw);
		}
	public:
		long getCheckSum(vector<vector<int>> matrix) {
			long sum = 0;

			for (auto row : matrix) {
				auto minMax = getMinAndMax(row);
				sum += (std::get<0>(minMax) - std::get<1>(minMax));
			}

			return sum;
		}
};

void testFunc() {
	FileInput inp("input.txt");
	ChecksumCalc sol;

	cout << sol.getCheckSum(inp.getListVector()) << endl;
}
