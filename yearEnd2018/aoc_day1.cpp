// Advent of code day 1: http://adventofcode.com/2017/day/1

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class SameDigitSum {
private:
	long _sum;

	void addToSum(char ch) {
		auto m = ch - '0';
		_sum += m;
	}

public:
	long getSum(string s) {
		_sum = 0;
		size_t input_length = s.length();
		
		// Will need atleast two character 
		if (input_length < 2)
			return 0;

		for (size_t i = 0; i < input_length; i++) {
			if (i != input_length - 1) {
				if (s[i] == s[i + 1]) addToSum(s[i]);
			}
			else {
				if (s[i] == s[0])	addToSum(s[i]);
			}
		}

		return _sum;
	}
};

void testProgram() {
	SameDigitSum s;

	cout << s.getSum("1122") << endl;	// Should output 3
	cout << s.getSum("1111") << endl;	// Should return 4
	cout << s.getSum("1234") << endl;	// Should return 0
	cout << s.getSum("91212129") << endl;	// Should return 9;
}
