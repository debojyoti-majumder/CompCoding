// Problem URL: https://leetcode.com/problems/nth-magical-number/description/

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
	private:
		set<int>		_results;
		pair<int,int>	_multipliers;

		vector<int> perfromMultiplication(const vector<int>& nums) {
			vector<int> ret;

			for (auto n : nums) {
				auto v1 = n * _multipliers.first;
				auto v2 = n * _multipliers.second;

				auto res1 = _results.insert(v1);
				auto res2 = _results.insert(v2);

				if (res1.second)
					ret.push_back(v1);

				if (res2.second)
					ret.push_back(v2);
			}

			return ret;
		}

	public:
		int nthMagicalNumber(int N, int A, int B) {
			
			vector<int> lastAddedNumber;
			_multipliers.first = A;
			_multipliers.second = B;
			
			_results.clear();
			_results.insert(A);
			_results.insert(B);

			lastAddedNumber.push_back(A);
			lastAddedNumber.push_back(B);
			
			while (_results.size() < (size_t)N) {
				auto item = perfromMultiplication(lastAddedNumber);
				lastAddedNumber = item;
			}

			auto it = _results.begin();
			advance(it, N - 1);
			return *it;
		}
};

int main() {
	Solution s;
	
	cout << s.nthMagicalNumber(4, 2, 3) << endl;	// Should return 6
	cout << s.nthMagicalNumber(5, 2, 4) << endl;	// Should output 10

	return 0;
}
