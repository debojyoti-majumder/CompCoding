// Problem URL: https://leetcode.com/problems/my-calendar-i/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <map>
#include <bitset>

using namespace std;

class MyCalendar {
private:
	vector<pair<int,int>> _bookings;
	
	bool isInConflict(const pair<int, int>& booking1, const pair<int, int>& booking2) {
		// For the start condition
		if ((booking1.first >= booking2.first && booking1.first<booking2.second) || (booking1.second>booking2.first && booking1.second <= booking2.second))
			return true;
		if ((booking2.first >= booking1.first && booking2.first < booking1.second) || (booking2.second > booking1.first && booking2.second <= booking1.second))
			return true;

		return false;
	}

public:
	bool book(int start, int end) {
		auto retVal = true;
		pair<int, int> requestedBooking(start, end);

		// Wrong input
		if (start > end)
			return false;

		// Base case
		if (_bookings.size() == 0) {
			_bookings.push_back(make_pair(start, end));
			return true;
		}

		for (auto bk : _bookings) {
			if (isInConflict(bk, requestedBooking)) {
				retVal = false;
				break;
			}
		}

		if (retVal)
			_bookings.push_back(make_pair(start, end));

		return retVal;
	}
};


int main() {
	MyCalendar m;

	cout << m.book(10, 20) << endl;		// returns true
	cout << m.book(15, 25) << endl;		// returns false
	cout << m.book(20, 30) << endl;		// returns true
	cout << m.book(8, 12) << endl;		// returns false

	// Expected output: 1 1 0 0 1 0 1 1 1 0
	MyCalendar c;
	vector<pair<int, int>> inp{ {47,50 }, { 33,41 }, { 39,45 }, { 33,42 }, { 25,32 }, { 26,35 }, { 19,25 }, { 3,8 }, { 8,13 }, { 18,27 } };
	for (auto a : inp) {
		cout << c.book(a.first, a.second) << " ";
	}
	cout << endl;

	return 0;
}
