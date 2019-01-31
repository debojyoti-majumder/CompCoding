// Problem URL: https://leetcode.com/problems/nth-magical-number/description/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
	private:
		static long modulo;

	public:
		int nthMagicalNumber(int N, int A, int B) {
			pair<int, int> items(A, B);
			set<int> results;

			results.insert(A);
			results.insert(B);
			int index = 0;

			while (index < N) {
				auto it = results.begin();
				advance(it, index);
				auto i = *it;

				if (i % A == 0)
					results.insert((i + A) % Solution::modulo);

				if (i % B == 0)
					results.insert((i + B) % Solution::modulo);

				index++;
			}

			// Returuning the n element 
			auto it = results.begin();
			advance(it, N-1);
			return *it;
		}
};

long Solution::modulo =(long) pow(10, 9) + 7;

int main() {
	Solution s;
	
	cout << s.nthMagicalNumber(4, 2, 3) << endl;	// Should return 6
	cout << s.nthMagicalNumber(5, 2, 4) << endl;	// Should output 10
	cout << s.nthMagicalNumber(3, 6, 4) << endl;	// Should output 8
	// Should output 6 
	cout << s.nthMagicalNumber(2, 7, 3) << endl;	

	// Getting time limit error
	cout << s.nthMagicalNumber(1000000000, 40000, 40000);
	
	return 0;
}
