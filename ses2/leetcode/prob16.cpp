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
		cout << beginWord << "," << endWord << currentIndex << endl;

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
			// This is the cabdidate word to find
			auto item = beginWord;
			item[currentIndex - 1] = option;

			// The word needs to be in the dictinoary
			auto foundWord = find(wordList.begin(), wordList.end(), item);
			if (foundWord == wordList.end())
				continue;
			
			int val = ladderLength(item, endWord, wordList, currentIndex);
			if (val != 0)
				editValues.push_back(1 + val);
		}
		
		// Means there are on paths for the current index
		if (editValues.size() == 0)
			return ladderLength(beginWord, endWord, wordList, currentIndex);

		
		auto val = min_element(editValues.begin(), editValues.end());
		return *val;
	}
};

int main() {
	Solution s1, s2;

	vector<string> p1{ "hot","dot","dog","lot","log","cog" };
	vector<string> p2{ "hot","dot","dog","lot","log" };

	cout << s1.ladderLength("hit", "cog", p1) << endl;			// Should output 5
	cout << s2.ladderLength("hit", "cog", p2) << endl;			// Should output 0

	return 0;
}
