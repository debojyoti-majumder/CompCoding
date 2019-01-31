// keyPadProb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<char, vector<char>> getValidMoves() {
	map<char, vector<char>> ret_map;

	ret_map.insert(make_pair('A', vector<char>{'B','D'}));
	ret_map.insert(make_pair('B', vector<char>{'A', 'C', 'E'}));
	ret_map.insert(make_pair('C', vector<char>{'B', 'F'}));
	ret_map.insert(make_pair('D', vector<char>{'A', 'E', 'G'}));
	ret_map.insert(make_pair('E', vector<char>{'B', 'D', 'F', 'H'}));
	ret_map.insert(make_pair('F', vector<char>{'C', 'E', 'I'}));
	ret_map.insert(make_pair('G', vector<char>{'H','D'}));
	ret_map.insert(make_pair('H', vector<char>{'E', 'G', 'I', 'J'}));
	ret_map.insert(make_pair('I', vector<char>{'H','F'}));
	ret_map.insert(make_pair('J', vector<char>{'H'}));

	return ret_map;
}

vector<string> getMovesfor(map<char, vector<char>>& validMoves, int count) {
	if( count == 1 ) {
		vector<string> ret;

		ret.push_back("A");
		ret.push_back("B");
		ret.push_back("C");
		ret.push_back("D");
		ret.push_back("E");
		ret.push_back("F");
		ret.push_back("G");
		ret.push_back("H");
		ret.push_back("I");
		ret.push_back("J");
		
		return ret;
	}

	auto prevMoves = getMovesfor(validMoves ,count - 1);
	vector<string> moves;

	for (auto move : prevMoves) {
		// Get the last item
		auto last_item = move[move.length() - 1];
		auto valid_moves = validMoves[last_item];

		for (auto valid_move : valid_moves) {
			string action(move + valid_move);

			// Add only if it does not exsists
			//auto it = find(moves.begin(), moves.end(), action);
			//if( it == moves.end() )
				moves.push_back(action);
		}

		// Same with pressing the button twice
		auto self_action = move + last_item;
		//auto it2 = find(moves.begin(), moves.end(), self_action);
		//if( it2 == moves.end() )
			moves.push_back(self_action);
	}

	return moves;
}

int combinationCounts(int level) {
	// Just to safegaurd
	if (level <= 0)
		return level;

	auto validMoves = getValidMoves();
	auto moves = getMovesfor(validMoves, level);

	return ((int) moves.size());
}

int main()
{
	cout << combinationCounts(1) << endl;
	cout << combinationCounts(2) << endl;
    return 0;
}

