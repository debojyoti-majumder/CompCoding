// Problem URL: https://leetcode.com/problems/shopping-offers/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
	bool isOfferApplicable(const vector<int>& offer, const vector<int>& need) {
		return true;
	}

public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		auto isNonZero = find_if(needs.begin(), needs.end(), [](int val) {
			return val != 0;
		});

		// Base case
		if (isNonZero == needs.end())
			return 0;

		vector<int> shoppingValues;

		// Going through each offer
		for (const auto& offer : special) {
			if (offer.size() - 1 != needs.size())
				throw "Bad state";

			if (isOfferApplicable(offer, needs)) {
				// Reducing the need
				auto newNeed{ needs };
				for (size_t i = 0; i < newNeed.size(); i++) {

				}

				// Recursive call
				shoppingValues.emplace_back(shoppingOffers(price, special, newNeed));
			};
		}

		// Returning the minimum element
		auto minElem = min_element(shoppingValues.cbegin(), shoppingValues.cend());
		return minElem == shoppingValues.end() ? -1 : *minElem;
	}
};

int main() {
	Solution s;
	vector<int> itemCost{ 2,5 };
	vector<int> itemNeed{ 3,2 };
	vector<vector<int>> offers{
		{3,0,5},
		{1,2,10}
	};

	auto ret = s.shoppingOffers(itemCost, offers, itemNeed);
	cout << ret << endl;

	return 0;
}
