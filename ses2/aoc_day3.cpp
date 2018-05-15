#include <vector>
#include <iostream>

using namespace std;

class SpiralHelper {
	private:
		// Holds the current size of the squere matrix
		unsigned int _currentSize;
		
		// 1 - RIGHT, 2 - TOP,3 - LEFT, 4 - BOTTOM
		unsigned int _currentDirection;
		
		// Matrix to be returned
		vector<vector<int>>	_spiralMatrix;

		// Matrix location cursor
		unsigned int _x, _y;

		int getMinDistance(const vector<vector<int>>& matrix) {
			return 0;
		}

		bool isFull(int currNumber) {
			if(_x == _spiralMatrix[0].size() - 1 || _x == 0 )
				return true;
			if (_y == _spiralMatrix[0].size() - 1 || _y == 0)
				return true;

			return false;
		}

		void putItem(int num) {
			auto toAdd = isFull(num);
			
			// Need to change direction
			if (toAdd) {
				_currentDirection += 1;
				_currentDirection = _currentDirection % 4;
			}

			switch (_currentDirection) {
				// Add column to right
				case 1:
					if (toAdd) {
						for (auto p : _spiralMatrix)
							p.push_back(-1);
					}

					_x++;
					break;

				case 2: {
					if (toAdd) {
						vector<int> p(_spiralMatrix[0].size());
						_spiralMatrix.insert(_spiralMatrix.begin(), p);
					}

					_y--;
					break;
				}

				case 3:
					if( toAdd ) {
						for (auto p : _spiralMatrix)
							p.insert(p.begin(), -1);
					}
					
					_x--;
					break;

				case 4:{
					if( toAdd ) {
						vector<int> p(_spiralMatrix[0].size);
						_spiralMatrix.push_back(p);
					}

					_y++;
					break;
				}
			}
		}

		vector<vector<int>> generateMatrix(int number) {
			vector<int> m(1);

			_spiralMatrix.clear();
			_spiralMatrix.push_back(m);
			
			for (auto i = 2; i < number; i++) {
				putItem(i);
			}

			return _spiralMatrix;

		}

	public:
		SpiralHelper() : _currentDirection(0), _x(0), _y(0) {}

		int getDistance(int number) {
			return getMinDistance(generateMatrix(number));
		}
};
