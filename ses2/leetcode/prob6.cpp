// Problem URL: https://leetcode.com/problems/find-k-closest-elements/description/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	bool isNeeded(int number, int range, int x) {
		int sub = abs(x - number);
		return sub <= range ? true : false;
	}
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> retItem;
		bool bOrgfound = false;
		
		for (auto item : arr) {
			if (item == x)
				bOrgfound = true;

			if (isNeeded(item, k, x))
				retItem.push_back(item);
		}

		if (false == bOrgfound) {
			vector<int> v(arr.begin(), arr.begin() + k);
			return v;
		}

		// Needs to be trimed
		if (retItem.size() > k) {
			auto it = find(retItem.begin(), retItem.end(), x);
			int index = it - retItem.begin();
			
			// have enough item to pick from left
			if (index >= k - 1) {
				vector<int> m;
				for (int i = index - k + 1; i <= index ; ++i)
					m.push_back(retItem[i]);

				return m;
			}
			else {
				vector<int> m;
				int toRight = k;
				int i = 0;
				for (i = 0; i <= index; i++) {
					m.push_back(retItem[i]);
					toRight--;
				}
				for (int j = 0; j < toRight; j++)
					m.push_back(retItem[i + j]);

				return m;
			}
		}

		return retItem;
	}
};

template<typename T>
void printItems(vector<T> vec) {
	for (auto p : vec)
		cout << p << " ";
	cout << endl;
}

int main() {
	vector<int> nums{ 1, 2, 3, 4, 5, 6 };
	Solution s;

	// Should output 1,2,3
	auto ret = s.findClosestElements(nums, 3, 2);
	printItems(ret);

	// Should output [1,2,3,4]
	ret = s.findClosestElements(nums, 4, -1);
	printItems(ret);

	//vector<int> n{ 0, 1, 2, 2, 2, 3, 6, 8, 8, 9 };
	//ret = s.findClosestElements(n, 5, 9);
	// printItems(ret);

	vector<int> p{ -1,-2,-3,-4,-5 };
	ret = s.findClosestElements(p, 2, -3);
	printItems(ret);
	return 0;
}

