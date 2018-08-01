#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		// Needs a stack based solutions
		vector<int> collitionStack;
		auto sz = asteroids.size();

		if (sz <= 1)
			return asteroids;

		for (size_t i = 0; i < sz; i++) {
			auto t = asteroids[i];
			if (t >= 0) {
				collitionStack.push_back(t);
			}
			else if (false == collitionStack.empty()) {
				auto p = collitionStack.back();
				
				// If negative then there is a collition
				if (p * t < 0) {
					auto item_1 = abs(p);
					auto item_2 = abs(t);

					if (item_1 > item_2) {
						// Remove Item 2
					}
					else if (item_2 < item_1) {
						// Remove item 1;
					}
					else {
						// Remove item 1 and 2
					}
				}
			}
		}

		return asteroidCollision(asteroids);
	}
};


template <typename T>
void printEnumuarle( T arr ) {
	cout << "[ ";
	
	for (auto a : arr)
		cout << a << " ";

	cout << "]" << endl;
}

int main() {
	Solution s;
	
	auto ans1(s.asteroidCollision(vector<int>{ 5, 10, -5 }));
	printEnumuarle(ans1);

	auto ans2(s.asteroidCollision(vector<int>{8,-8}));
	printEnumuarle(ans2);

	auto ans3(s.asteroidCollision(vector<int>{ 10,2,-5 }));
	printEnumuarle(ans3);

	auto ans4(s.asteroidCollision(vector<int>{ -1,-2,5,1 }));
	printEnumuarle(ans4);

	// Should output {-2, -2, -2, 1}
	auto ans5(s.asteroidCollision(vector<int>{-2, -2, -2, 1}));
	printEnumuarle(ans5);

	auto ans6(s.asteroidCollision(vector<int>{-2, -2, 2, -1}));
	printEnumuarle(ans6);

	return 0;
}
