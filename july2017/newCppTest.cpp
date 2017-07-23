// elevenTest1.cpp : The purpose of this file is to find new features of new C++ standard
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
class MyVectorProcessor 
{
	private:
		vector<T> _mainVector;

	public:
		MyVectorProcessor() = delete;

		MyVectorProcessor(vector<T> arg) {
			// TODO: Make STL "copy" method
			for (auto item : arg)
				_mainVector.push_back(item);
		}
		
		vector<T> filterVector(std::function<bool(T)> filterFunction) {
			vector<T> returnItem;

			for( auto item : _mainVector ) {
				// Invoking the filter function
				if( filterFunction(item) )
					returnItem.push_back(item);
			}

			// Returning a copy of filtered version
			return returnItem;
		}
};

int main()
{
	auto numbers = vector<int>{ 2,6,5,-9,3,-2 };
	MyVectorProcessor<int> vecProc(numbers);

	// Simple example of lamda
	int positives = count_if(numbers.begin(), numbers.end(), [](int num) {
		return num > 0;
	});

	cout << "Positive numbers:" << positives;

	// Defining the filtering function
	auto filterFunction = [](int data) {
		return data > 0;
	};

	// Passing the method to the filtering function
	auto filterItem = vecProc.filterVector(filterFunction);
	for (auto item : filterItem)
		cout << item << endl;

    return 0;
}

