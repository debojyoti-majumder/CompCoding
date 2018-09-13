// Problem URL: https://leetcode.com/problems/battleships-in-a-board/description/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	struct Point {
		int x;
		int y;

		Point() : x(-1), y(-1) {

		}

		Point(int row, int col) : x(row), y(col) {

		}
	};

	using BattleShip = vector<Point>;
	vector<BattleShip> battleShips;

	// This functions is not working
	bool updateBattleShip(const Point& p, BattleShip& ship) {
		bool addPoint = false;

		for (auto& point : ship) {
			if (point.x == p.x && (point.y == p.y + 1 || point.y == p.y - 1 )) {
				addPoint = true;
				break;
			}

			if (point.y == p.y && (point.x == p.x + 1 || point.x == p.x - 1)) {
				addPoint = true;
				break;
			}
		}

		if (addPoint)
			ship.push_back(p);

		return addPoint;
	}

	void addPointToBattleShips(const Point& p) {
		auto isNewBattelShip = true;

		for (auto& b : battleShips) {
			isNewBattelShip = !updateBattleShip(p, b);
		}

		if (isNewBattelShip) {
			BattleShip b{ p };
			battleShips.push_back(b);
		}
	}

public:
	int countBattleships(vector<vector<char>>& board) {
		if (board.size() == 0)
			return 0;

		// Init cases
		vector<Point> xPoints;
		size_t row = board.size();
		size_t col = board[0].size();
		battleShips.clear();

		// Make a list of points which has 'X'
		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				if (board[i][j] == 'X')
					xPoints.push_back(Point{ (int)i,(int)j });
			}
		}

		for (auto& p : xPoints) {
			addPointToBattleShips(p);
		}

		return battleShips.size();
	}
};

int main() {
	vector<vector<char>> bd{ {'X', '.', '.', 'X'}, { '.', '.', '.', 'X'}, { '.', '.', '.', 'X' }};
	Solution s;
	
	// Should output 2
	cout << s.countBattleships(bd) << endl; 

	return 0;
}
