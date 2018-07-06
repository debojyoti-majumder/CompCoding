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
	vector<pair<int, int>> _bookings;

public:
	bool book(int start, int end) {
		auto retVal = true;
		auto requestedDuration = end - start;

		for (auto bookingPair : _bookings) {
			auto bookedForTime = bookingPair.second - bookingPair.first;
			
		}

		// This is to confirm bookings
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
	
	return 0;
}
