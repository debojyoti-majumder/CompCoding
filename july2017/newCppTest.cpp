// elevenTest1.cpp : Testing out new C++ capabilities
// Link to follow: https://stackoverflow.com/questions/13592847/c11-observer-pattern-signals-slots-events-change-broadcaster-listener-or

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

template <typename T>
class MyVectorProcessor 
{
	private:
		std::vector<T> _mainVector;

	public:
		MyVectorProcessor() = delete;

		MyVectorProcessor(std::vector<T> arg) {
			// TODO: Make STL "copy" method
			for (auto item : arg)
				_mainVector.push_back(item);
		}
		
		std::vector<T> filterVector(std::function<bool(T)> filterFunction) {
			std::vector<T> returnItem;

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

	auto input_strings = vector<string>{ "Debojyoti", "Some", "Small", "Big string again" };
	MyVectorProcessor<string> my_string_vec(input_strings);

	// Using my Library on string
	auto stringFilter = [](string data) {
		return data.length() > 6;
	};
	auto filtered_strings = my_string_vec.filterVector(stringFilter);
	for (auto item : filtered_strings)
		cout << item << endl;

    return 0;
}
