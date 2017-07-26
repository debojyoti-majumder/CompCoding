// addBin.cpp : https://leetcode.com/problems/add-binary/#/description
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
	public:
		string addBinary(string a, string b) {
			string retString("");
			string upper_item, lower_item;

			// making proper operator
			if (a.length() > b.length()) {
				upper_item = a;
				lower_item = b;
			}
			else {
				upper_item = b;
				lower_item = a;
			}

			// Add zero padding
			int diff = upper_item.length() - lower_item.length();
			int carry_bit = 0;

			for (int i = 0; i < diff; i++)
				lower_item = "0" + lower_item;

			// both string are of same length
			for (int i = upper_item.length()-1; i >=0 ; i--) {
				int digit_1 = upper_item[i] - 48;
				int digit_2 = lower_item[i] - 48;

				int sum = digit_1 + digit_2 + carry_bit;
				switch (sum) {
					case 0:
						carry_bit = 0;
						retString = "0" + retString;
						break;

					case 1:
						carry_bit = 0;
						retString = "1" + retString;
						break;

					case 2:
						carry_bit = 1;
						retString = "0" + retString;
						break;

					case 3:
						carry_bit = 1;
						retString = "1" + retString;
						break;
				}
			}

			if (carry_bit)
				retString = "1" + retString;

			return retString;
	}
};

int main()
{
	Solution s;
	// Should out put "100"
	cout << s.addBinary("11", "1") << endl;
    
	cout << s.addBinary("11000011", "01") << endl;
	return 0;
}

