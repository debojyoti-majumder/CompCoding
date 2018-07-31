#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		// Needs a stack based solutions
		vector<int> collitionStack;
		auto sz = asteroids.size();

		if (sz <= 1)
			return asteroids;

		// Now we know the size of the array must be greater than 2
		collitionStack.push_back(asteroids[0]);

		for (size_t i = 1; i < sz; i++) {
			auto item = collitionStack.back();
			auto val = asteroids[i];

			// This means it's a direction mismatch,
			// Might have collition might be opposite direction
			if (item * val < 0) {

			}
			else
				collitionStack.push_back(item);
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
