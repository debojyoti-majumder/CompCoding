// URL: https://leetcode.com/problems/insert-delete-getrandom-o1/

#include "pch.h"

#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

#define ARR_SIZE 10000

// TODO 1: Create a hand written hash function for an array
// TODO 2: 

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return 0;
    }
};

class RandomizedVector {
private:
    vector<int>     _numbers;
    random_device   _rd;
    mt19937         _generator;

public:
    /** Initialize your data structure here. */
    RandomizedVector() : _generator(_rd()) {
        
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // Over time this would take some time
        auto it = find(_numbers.begin(), _numbers.end(), val);
        
        if (it == _numbers.end()) {
            _numbers.push_back(val);
            return true;
        }
        else
            return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> dist(0, _numbers.size() - 1);
        auto randomIndex = dist(_generator);

        return _numbers[randomIndex];
    }
};

vector<int> testRandomSet() {
    auto randomSource = new RandomizedSet();
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    vector<int> returnValue;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, ARR_SIZE);

    for (int i = 0; i < 3000; i++) {
        int number = distribution(generator);
        randomSource->insert(number);

        if (i % 5 == 0) {
            randomSource->remove(number);
        }

        if (i % 10 == 0) {
            auto n{ randomSource->getRandom() };
            returnValue.emplace_back(n);
        }
    }

    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Time difference = " << chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[mcs]" << endl;

    return returnValue;
}

vector<int> testRandomVector() {
    auto randomSource = new RandomizedVector();
    chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    vector<int> returnValue;
    
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, ARR_SIZE);

    for (int i = 0; i < 30000; i++) {
        int number = distribution(generator);
        randomSource->insert(number);

        if (i % 5 == 0) {
            randomSource->remove(number);
        }

        if (i % 10 == 0) {
            auto n{ randomSource->getRandom() };
            returnValue.emplace_back(n);
        }
    }

    chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Time difference with naive impl = " << chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[mcs]" << std::endl;

    return returnValue;
}

int main() {
    testRandomSet();
    testRandomVector();

    return 0;
}
