// elevenTest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	auto numbers = vector<int>{ 2,6,5,-9,3,-2 };
	
	// Simple example of lamda
	int positives = count_if(numbers.begin(), numbers.end(), [](int num) {
		return num > 0;
	});

	cout << "Positive numbers:" << positives;
    return 0;
}

