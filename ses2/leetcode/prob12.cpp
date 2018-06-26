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
		
		typedef struct _TreeNode {
			string symbol;
			bool hasLeft;
			bool hasRight;

			_TreeNode(string s) : symbol(s), hasLeft(false), hasRight(false) {}
		}TreeNode;

		vector<TreeNode> validationVector;

		for (auto symbol : preOrderVector) {
			TreeNode nd(symbol);

			if (!validationVector.empty()) {
				TreeNode& item = validationVector.back();
				
				if (item.hasLeft == false)
					item.hasLeft = true;
				else {
					item.hasRight = true;
					validationVector.pop_back();
				}

				if (symbol.compare("#") != 0) {
					validationVector.push_back(nd);
				}
			}
			else {
				validationVector.push_back(nd);
			}
		}

		return validationVector.size() == 0 ? true : false;
	}
};

int main() {
	Solution s;
	
	// Should out put true
	cout << "Test case 1:" << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
	
	// Should output false
	cout << "Test case 2:" << s.isValidSerialization("1, #") << endl;

	// Should output false
	cout << "Test case 3:" << s.isValidSerialization("9,#,#,1") << endl;
	return 0;
}
