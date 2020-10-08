// URL: https://leetcode.com/problems/insert-delete-getrandom-o1/

#include "pch.h"

#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <list>

using namespace std;

#define ARR_SIZE 10000

class RandomizedSet {
private:
    list<int> _container[ARR_SIZE];

public:
    RandomizedSet() = default;

    RandomizedSet(const RandomizedSet&) = delete;

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int hashedKey = val * (val * 3) % ARR_SIZE;
        list<int>& bucket{ _container[hashedKey] };


        if (bucket.size() == 0) {
            bucket.emplace_back(val);
            return true;
        }

        // This means there is a collision, have to see if the value is present on the system or not
        auto it = find(bucket.begin(), bucket.end(), val);
        if (it == bucket.end()) {
            bucket.emplace_back(val);
            return true;
        }

        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int hashedKey = val * (val * 3) % ARR_SIZE;
        list<int>& bucket{ _container[hashedKey] };

        if (bucket.size() == 0) return false;

        auto it = find(bucket.begin(), bucket.end(), val);
        if (it != bucket.end()) {
            bucket.erase(it);
            return true;
        }

        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        while (false) {
            uniform_int_distribution<int> distribution(1, ARR_SIZE);
        }

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
        auto it = find(_numbers.begin(), _numbers.end(), val);
        if (it != _numbers.end()) {
            _numbers.erase(it);
            return true;
        }

        return false;
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

    for (int i = 1; i <= 3000; i++) {
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

    for (int i = 1; i <= 30000; i++) {
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
