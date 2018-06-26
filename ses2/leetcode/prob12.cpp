// Problem URL: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
	vector<string> getTreeVector(const string& inputString) {
		int length = inputString.length();
		char* input = new char[length];
		strcpy_s(input, length, inputString.c_str());
		const char* deli = ",";
		char* tok = nullptr;
		vector<string> treeArray;

		do {
			tok = strtok(input, deli);
			treeArray.push_back(tok);
		} while (tok != nullptr);

		return treeArray;
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
