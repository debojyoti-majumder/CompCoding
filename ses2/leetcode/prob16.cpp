// Problem URL: https://leetcode.com/problems/word-ladder/description/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <map>
#include <bitset>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList, int currentIndex = 0) {
		vector<int> editValues;

		auto it = find(wordList.begin(), wordList.end(), endWord);
		if (it == wordList.end())
			return 0;
		
		if (currentIndex == endWord.length())
			return 0;

		set<char> editOptions;
		for (auto wd : wordList) {
			if( wd[currentIndex] != beginWord[currentIndex])
				editOptions.insert(wd[currentIndex]);
		}

		currentIndex++;
		for (auto option : editOptions) {
			auto item = beginWord;
			item[currentIndex] = option;

			int val = ladderLength(item, endWord, wordList, currentIndex);
			if (val != 0)
				editValues.push_back(val);
		}

		
		auto val = min_element(editValues.begin(), editValues.end());
		return *val;
	}
};

int main() {
	Solution s1, s2;

	cout << s1.ladderLength("hit", "cog", { "hot","dot","dog","lot","log","cog" });		// Should output 5
	cout << s2.ladderLength("hit", "cog", { "hot","dot","dog","lot","log" });			// Should output 0

	return 0;
}
