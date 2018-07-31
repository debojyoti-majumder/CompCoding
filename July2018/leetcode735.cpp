#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	pair<int, int> getPossitiveNegativeCount(const vector<int>& arr) {
		pair<int, int> countValues(0,0);

		for (auto a : arr) {
			if (a > 0)
				countValues.first += 1;
			else
				countValues.second += 1;
		}

		return countValues;
	}
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		auto posAndNegs = getPossitiveNegativeCount(asteroids);
		auto sz = asteroids.size();

		// First is posisitive count, second is negative count
		if (posAndNegs.first == 0 || posAndNegs.second == 0)
			return asteroids;
		
		// Check for symetry
		int leftMinusCounter = 0;
		for (size_t i = 0; i < sz; i++) {
			if (asteroids[i] < 0)
				leftMinusCounter++;
			else 
				break;
		}

		if (leftMinusCounter == posAndNegs.first)
			return asteroids;

		// Getting the collition point
		for (size_t i = 0; i < sz - 1; i++) {
			auto item_1 = asteroids[i];
			auto item_2 = asteroids[i + 1];
			auto temp = item_1 * item_2;
			
			// Means there is sign mismatch, hence collition
			if (temp < 0) {
				auto abs_1 = abs(item_1);
				auto abs_2 = abs(item_2);

				if (abs_1 == abs_2) {
					asteroids.erase(asteroids.begin() + i);
					asteroids.erase(asteroids.begin() + i);
				}
				else if( abs_1 < abs_2 ) {
					asteroids.erase(asteroids.begin() + i);
				}
				else {
					asteroids.erase(asteroids.begin() + i + 1);
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

	// Should output {-2,-2,-2,1}
	auto ans5(s.asteroidCollision(vector<int>{-2, -2, -2, 1}));
	printEnumuarle(ans5);

	return 0;
}
