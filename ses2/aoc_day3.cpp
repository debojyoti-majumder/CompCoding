#include "stdafx.h"
#include <iostream>
#include <vector>

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

public:
	SprialHelper() : _x(0), _y(0), _direction(1) {
		vector<int> m(1);
		m[0] = 1;

		_matrix.push_back(m);
	}

	int getDistance(int num) {
		// Generating the matrix
		for (auto i = 2; i < num; i++) {
			putItem(i);
		}

		return 0;
	}
};

int main() {
	SprialHelper h;
	cout << h.getDistance(23) << endl;

	return 0;
}
