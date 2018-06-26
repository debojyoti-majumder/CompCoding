// Problem URL: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
	vector<string> getTreeVector(const string& inputString) {
		vector <string> tokens;

		stringstream check1(inputString);
		string intermediate;

		while (getline(check1, intermediate, ',')){
			tokens.push_back(intermediate);
		}

		return tokens;
	}

public:
	bool isValidSerialization(string preorder) {
		bool isValid = false;
		auto preOrderVector(getTreeVector(preorder));
		size_t sz = preOrderVector.size();

		return isValid;
	}
};

int main() {
	Solution s;
	
	// Should out put true
	cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
	
	// Should output false
	cout << s.isValidSerialization("1, #") << endl;

	// Should output false
	cout << s.isValidSerialization("9,#,#,1") << endl;
	return 0;
}
