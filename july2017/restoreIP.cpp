// validIp.cpp : Defines the entry point for the console application.
// Problem url: https://leetcode.com/problems/restore-ip-addresses/description/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> resotred_ips;

		return resotred_ips;
	}
};

int main()
{
	Solution s;
	auto ips = s.restoreIpAddresses("25525511135");

	// Should show ["255.255.11.135", "255.255.111.35"]
	for (auto ip : ips)
		cout << ip << endl;

	return 0;
}

