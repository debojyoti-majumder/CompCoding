// Fails on this input 10 2 4 2 6 1 7 8 9 2 1
// Hacker rank url https://www.hackerrank.com/challenges/candies

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int adjHighAdjust(const vector<int>& kidratings, int i) {
	if ( kidratings[i] > kidratings[i - 1])
		return 2;
	else if ( kidratings[i] > kidratings[i + 1] )
		return 1;
	else
		return 0;
}

vector<int> getCandyAssignment(const vector<int>& kidratings) {
	vector<int> candies;

	// Intializing values with zero
	for (auto p : kidratings)
		candies.push_back(0);

	for (size_t i = 1; i<kidratings.size() - 1; i++) {
		int code = adjHighAdjust(kidratings, i);
		switch (code) {
		case 1:
			candies[i] = candies[i + 1] + 1;
			break;

		case 2:
			candies[i] = candies[i - 1] + 1;
			break;

		default:
			candies[i] = 1;
		}
	}

	return candies;
}

int main() {
	int numofKids;
	cin >> numofKids;
	vector<int> ratings;

	ratings.push_back(0);
	for (int i = 0; i < numofKids; i++) {
		int temp;
		cin >> temp;
		ratings.push_back(temp);
	}
	ratings.push_back(0);

	ratings[0] = ratings[1];
	ratings[numofKids] = ratings[numofKids - 1];

	auto assignment = getCandyAssignment(ratings);
	int sum = 0;

	assignment.erase(assignment.begin());
	assignment.pop_back();

	for (auto item : assignment)
		sum += item;

	cout << sum;

	return 0;
}
