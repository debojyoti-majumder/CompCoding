#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
private:
	vector<vector<int>> _triangle;
	struct Point
	{
		int x;
		int y;

		Point() : x(0), y(0) {}
		Point(int p, int q) : x(p), y(q) {}
	};
	
	struct PointCompare
	{
		bool operator() (const Point& lhs, const Point& rhs) const
		{
			if (lhs.x == rhs.x) {
				return lhs.y < rhs.y;
			}
			else
				return lhs.x < rhs.x;
		}
	};

	map<Point, int,PointCompare> _dptable;

public:
	int minimumCost(struct Point startingPoint) {
		// This is a base case for the recusive solution
		if (startingPoint.x == _triangle.size() - 1) {
			return _triangle[startingPoint.x][startingPoint.y];
		}

		auto item = _dptable.find(startingPoint);
		if (item != _dptable.end()) {
			return item->second;
		}

		// Setting the adjacent points
		Point p1(startingPoint.x + 1, startingPoint.y);
		Point p2(startingPoint.x + 1, startingPoint.y + 1);

		// Making the recursive calls
		int cost = min(_triangle[startingPoint.x][startingPoint.y] + minimumCost(p1), 
				       _triangle[startingPoint.x][startingPoint.y] + minimumCost(p2));
		
		_dptable.insert(make_pair(startingPoint, cost));
		return cost;
	}

	int minimumTotal(vector<vector<int>>& triangle) {
		_triangle.clear();
		_triangle = triangle;

		Point p(0, 0);
		return minimumCost(p);
	}
};

int main()
{
	vector<vector<int>> input;
	Solution s;

	vector<int> line1 = { 2 };
	vector<int> line2 = { 3,4 };
	vector<int> line3 = { 6,5,7 };
	vector<int> line4 = { 4,1,8,3 };

	input.push_back(line1);
	input.push_back(line2);
	input.push_back(line3);
	input.push_back(line4);

	// Expected output 11
	cout << s.minimumTotal(input) << endl;
	return 0;
}