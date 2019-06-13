#include <vector>
#include <algorithm>

using namespace std;

namespace Codewars {

    int claculateSum(const vector<int>&  items) {
        int sum { 0 };
        for(const auto& num : items) 
            sum += num;
            
        return sum;
    }

    class TaskPoolManager {
        private:
            vector<int> _slots;

        public:
            explicit TaskPoolManager(int n) : _slots(n,0) {
            }

            bool addToPool(int n) {
                auto isAdded { false };
                for( size_t i=0; i<_slots.size(); i++ ) {
                    // This means we have found an empty slot
                    if( _slots[i] == 0 ) {
                        _slots[i] = n;
                        isAdded = true;
                        break;
                    }
                }

                return isAdded;
            }

            int getQueueCost() {
                auto minValue { *min_element(_slots.begin(), _slots.end()) };
                for( size_t i=0; i<_slots.size(); i++ )
                    _slots[i] -= minValue;

                return minValue;
            }

            int getExitCost() {
                return *max_element(_slots.begin(), _slots.end());
            }
    };

    // Problem URL: https://www.codewars.com/kata/57b06f90e298a7b53d000a86/train/cpp
    long queueTime(vector<int> customers,int n) {
        auto queueLength { customers.size() };

        // Base cases
        if( customers.size() == 0 ) return 0;
        if( n == 1 ) return claculateSum(customers);
        if( queueLength <= (size_t) n ) {
            auto it { max_element(customers.begin(), customers.end()) };
            return *it;
        }

        TaskPoolManager mgr(n);
        auto waitTime { 0 };

        while( customers.size() ) {
            auto head { customers.begin() };
            auto isAdded { mgr.addToPool(*head) };

            if( isAdded ) {
                customers.erase(head);
            }
            else {
                waitTime += mgr.getQueueCost();
            }
        }

        waitTime+= mgr.getExitCost();
        return waitTime;
    }
} 