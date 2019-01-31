// Url link to follow: https://www.youtube.com/channel/UCEOGtxYTB6vo6MQ-WQ9W_nQ

// TODO 1: Add singleton class for console output
// TODO 2: Add logger capability to either to file to console may be stratagy pattern
// TODO 3: Overload the streaming operator
// TODO 4: Add mutex and scoped gaurd in the file

#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <random>
#include <atomic>
#include <mutex>

using namespace std;

std::atomic<unsigned int> atomicJobsLeft(10);

unsigned int jobsLeft = 10;

void myfunction() {
    cout << "This is a thread function" << endl;
}

void multiThreadCreation() {
    vector<shared_ptr<thread>> workerThreads;

    for(int i=0; i<10; i++) {
        auto t = make_shared<thread>(myfunction);;
        workerThreads.push_back(t);
    }

    // This more like wait for all objects
    for( auto& t : workerThreads ) 
        if( t->joinable()) t->join();

}

class SleepClass {  
    private:
        int _sleepFor;
    public:
        explicit SleepClass(int m) : _sleepFor(m) {

        }

        // This is the functor opearator for the thread construction
        void operator()() {
            this_thread::sleep_for(chrono::seconds(_sleepFor));
            
            // Indicate the jobs is done
            atomicJobsLeft--;
            jobsLeft--;
            
            // Verbose output
            cout << this_thread::get_id() <<" Done!! Jobs left " << atomicJobsLeft << " " << jobsLeft << endl;
        }
};

void functorRandomWaitThreading() {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1.0, 10.0);
    
    vector<shared_ptr<thread>> workerThreads;
    
    for(auto i=0; i<10; i++) {
        auto randomNumber = dist(mt);

        SleepClass c(randomNumber);
        workerThreads.push_back(make_shared<thread>(c));    
    }

    for(auto& t: workerThreads) {
        t->join();
    }    
}

int main() {
    functorRandomWaitThreading();
    return 0;
}
