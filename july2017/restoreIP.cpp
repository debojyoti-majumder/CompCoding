// validIp.cpp : Defines the entry point for the console application.
// Problem url: https://leetcode.com/problems/restore-ip-addresses/description/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<string> restoreIpAddresses(string s,int ipblocks = 4) {
			vector<string> resotred_ips;
			int len = s.length();
			int substr_index = len > 3 ? 3 : len;

			// Handling the invalid cases
			if (len > 3 * ipblocks && len < ipblocks)
				return resotred_ips;

			// This is the base case
			if (ipblocks == 1) {
				int v = atoi(s.c_str());
				if (v <= 255)
					resotred_ips.push_back(s);

				return resotred_ips;
			}

			vector<string> options;
			string temp("");

			for (int i = 0; i < substr_index; i++) {
				temp += s[i];
				int v = atoi(temp.c_str());

				if (v <= 255) {
					options.push_back(temp);
				}
			}

			for (auto option : options) {
				string sub_str(s.begin() + option.length(),s.end());
				auto res = restoreIpAddresses(sub_str, ipblocks - 1);
				
				for (auto m : res)
					if (m.length() > 0) resotred_ips.push_back(option + "." + m);
			}

			return resotred_ips;
		}
};

int main()
{
	Solution s;

	// Should show ["255.255.11.135", "255.255.111.35"]
	auto ips = s.restoreIpAddresses("25525511135");
	for (auto ip : ips)
		cout << ip << endl;

	// Should show ["0.0.0.0"]
	ips = s.restoreIpAddresses("0000");
	for (auto ip : ips)
		cout << ip << endl;

	return 0;
}

