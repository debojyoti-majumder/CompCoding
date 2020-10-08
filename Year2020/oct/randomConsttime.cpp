// URL: https://leetcode.com/problems/insert-delete-getrandom-o1/

#include "pch.h"
#include <iostream>
#include <random>

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
public:
    /** Initialize your data structure here. */
    RandomizedVector() {

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

void testRandomSet() {
    auto randomSource = new RandomizedSet();

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
            cout << randomSource->getRandom();
        }
    }

    cout << endl;
}

void testRandomVector() {
    auto randomSource = new RandomizedVector();

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
            cout << randomSource->getRandom() << " ";
        }
    }

    cout << endl;
}

int main() {
    std::cout << "Hello World!\n"; 
    return 0;
}
