// Good example of multi treading and memory management

#include <iostream>
#include <thread>
#include <vector>
#include <memory>

using namespace std;

void myfunction() {
    cout << "This is a thread function" << endl;
}

int main() {
    vector<shared_ptr<thread>> workerThreads;

    for(int i=0; i<10; i++) {
        auto t = make_shared<thread>(myfunction);;
        workerThreads.push_back(t);
    }

    // This more like wait for all objects
    for( auto& t : workerThreads ) 
        t->join();

    return 0;
}
