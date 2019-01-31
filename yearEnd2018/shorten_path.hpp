#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<string> getInternalPresentation(const vector<string>& tokens) {
		vector<string> retValue;

		for (auto token : tokens) {
			// Zero size does not count			
			if (token.length()) {
				if (token.compare("..") == 0) {
					// Pop if not empty
					if (!retValue.empty())
						retValue.pop_back();
				}
				else if (token.compare(".") == 0)
					retValue;		// Just Instrrcting to do nothing
				else
					retValue.push_back(token);
			}
		}

		return retValue;
	}

public:
	string simplifyPath(string path) {
		string simplified_path = "";
		istringstream inpStr(path);
		string token;
		vector<string> tokens;

		// Tokenzing based on path seperator
		while (getline(inpStr, token, '/')) {
			tokens.push_back(token);
		}

		// Getting the actual items
		auto pathItems = getInternalPresentation(tokens);

		if (pathItems.size() == 0)
			return "/";

		for (auto item : pathItems) {
			simplified_path += "/";
			simplified_path += item;
		}

		return simplified_path;
	}
};

int testSimplyfy() {
	Solution s;
	// Test case 0: Should output "/"
	cout << s.simplifyPath("") << endl;


	// Test case 1: Should output "/c"
	cout << s.simplifyPath("/a/./b/../../c/") << endl;

	// Test case 2: "/home/" => "/home"
	cout << s.simplifyPath("/home/") << endl;

	// Test case 3: "/.."
	cout << s.simplifyPath("/..") << endl;
	return 0;
}
