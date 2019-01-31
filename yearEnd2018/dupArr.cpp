// Problem Url: https://leetcode.com/problems/contains-duplicate/description/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {

public:
    bool containsDuplicate(vector<int>& nums) {
		set<int> unique_numbers;
		bool ret_value = false;

		for(auto item : nums ) {
			auto ret = unique_numbers.insert(item);
			
			if( ret.second == false ) {
				ret_value = true;
				break;
			}
		}

		return ret_value;
    }
};

int main() {
	vector<int> v1{1,2,3};
	vector<int> v2{10,20,30,40,50,10};

	Solution s;
	cout << s.containsDuplicate(v1) << endl;
	cout << s.containsDuplicate(v2) << endl;

	return 0;
}