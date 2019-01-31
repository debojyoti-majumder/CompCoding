#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

using namespace std;

template<typename T>
void printIteratable(const T& items) {
	cout << "[";

	for(const auto& item : items)
		cout << item << " ";

	cout << "]" << endl;
}

template<typename T>
void quickRemove(vector<T>& container,  typename vector<T>::iterator it) {
	if( it != end(container) ) {
		*it = move(container.back());
		container.pop_back();
	}
}


void removeFunctiontesting() {
	vector<int> items {1,2,3,4,4,4,5,6};
	printIteratable(items);

	int p;
	cin >> p; 

	// Removing item p
	auto itemToberemoved = remove(begin(items), end(items), p);
	items.erase(itemToberemoved);
	printIteratable(items);

	auto isOdd = [](int value) { 
		return (value % 2);
	};

	// Removing all the Odd numbers
	auto conditionalRemove = remove_if(begin(items), end(items), isOdd);
	items.erase(conditionalRemove);
	printIteratable(items);

	// Removing a specific item
	cin >> p;
	auto foundItem = find(begin(items), end(items), p);
	quickRemove(items, foundItem);
	printIteratable(items);

	return;
}

void sortedVectorOperation() {
	vector<int> numbers;
	int p;

	for( int i=0; i<5; i++ ) {
		cin >> p;

		// This would add item in the array in sorted manner
		auto lBound = lower_bound(begin(numbers), end(numbers), p);
		numbers.insert(lBound, p);
		printIteratable(numbers);
	}

	cout << "Enter index to access:";
	cin >> p;

	try {
		auto num = numbers.at(p);	
		cout << num << "\n";
	}
	catch(exception) {
		cout << "Out of index operation" << endl;
	}	
}


struct TaskStruct {
	int prority;
	string taskName;

	friend bool operator<(const TaskStruct& r1, const TaskStruct& r2) {
		return r1.prority < r2.prority;
	}
};

int main() {
	
	priority_queue<TaskStruct> taskQueue;

	for(int i=0; i<5; i++) {
		TaskStruct t;

		cin >> t.prority;
		cin >> t.taskName;

		taskQueue.push(t);
	}

	while( !taskQueue.empty() ) {
		auto task = taskQueue.top();

		cout << task.taskName << endl;
		taskQueue.pop();
	}

	return 0;
}
