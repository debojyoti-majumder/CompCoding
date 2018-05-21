// Problem URL: http://adventofcode.com/2017/day/3

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class SprialHelper {
private:
	unsigned int _x, _y, _cellsLeft;
	unsigned int _direction;
	vector<vector<int>> _matrix;
	
	bool allocateIfNeeded() {
		if (_cellsLeft == 0) {
			switch (_direction)
			{
			case 1: {
				for (auto& p : _matrix) {
					p.push_back(-1);
					_cellsLeft++;
				}
				_x++;
				break;
			}

			case 2: {
				vector<int> p(_matrix[_y].size());
				_cellsLeft += p.size();
				_matrix.insert(_matrix.begin(), p);
				_y = 0;
				break;
			}

			case 3: {
				for (auto& p : _matrix) {
					p.insert(p.begin(), -1);
					_cellsLeft++;
				}
				_x = 0;
				break;
			}

			case 4: {
				vector<int> p(_matrix[_y].size());
				_cellsLeft += p.size();
				_matrix.push_back(p);
				_y++;
				break;
			}

			default:
				break;
			}
			return true;
		}
		else
			return false;
	}

	void updateXY() {
		switch (_direction) {
		case 1:
			_x++;
			break;

		case 2:
			_y--;
			break;

		case 3:
			_x--;
			break;

		case 4:
			_y++;
			break;

		default:
			break;
		}
	}

	void changeDirection() {
		_direction++;
		if (_direction == 5)
			_direction = 1;
	}

	void putItem(int num) {
		auto allocated = allocateIfNeeded();
		
		if (allocated) {
			_matrix[_y][_x] = num;
			changeDirection();
		}
		else {
			updateXY();
			_matrix[_y][_x] = num;
		}

		_cellsLeft--;
	}

	void print() {
		for (const auto& row : _matrix) {
			for (const auto& itm : row) {
				cout << setfill('0') << setw(2) << itm << " ";
			}

			cout << endl;
		}
	}

	int getRoundedSize(int sz) {
		if (sz % 2 == 0) {
			return (sz / 2) - 1;
		}
		else
			return (sz / 2);
	}

	int getDiff(int x, int y) {
		auto p = x - y;
		if (p < 0)
			p = p * -1;


		return p;
	}

public:
	SprialHelper() : _x(0), _y(0), _direction(1) {
		vector<int> m(1);
		m[0] = 1;

		_matrix.push_back(m);
	}

	int getDistance(int num) {
		// Generating the matrix
		for (auto i = 2; i <= num; i++) {
			putItem(i);
		}

		return getDiff(_x,getRoundedSize(_matrix[0].size())) + getDiff(_y, getRoundedSize(_matrix.size()));
	}
};

int main() {
	SprialHelper h1,h2,h3,h4;

	cout << h2.getDistance(12) << endl;
	cout << h1.getDistance(23) << endl;
	cout << h3.getDistance(1024) << endl;
	cout << h4.getDistance(277678) << endl;
	return 0;
}
