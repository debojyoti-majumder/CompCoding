#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class DataItem {
    private:
        int _value;
        vector<function<void(int)>> _subscribers;

    public:
        DataItem() = delete;

        explicit DataItem(int b) : _value(b) {}

        DataItem& operator=(int v) {
            if( _value != v ) {
                cout << "Data item changed. \n";
                _value = v;

                for( auto subs : _subscribers ) {
                    subs(v);
                }
            }

            return *this;
        }

        void addSubScriber(const function<void(int)>& fnc) {
            _subscribers.emplace_back(fnc);
        }        
};

int main() {
    DataItem item(0);

    // setup change detetor;
    item.addSubScriber([] (int v) {
        cout << "Subscriber 1: Value change to " << v <<"\n";
    });

    item.addSubScriber([] (int v) {
        if( v > 10 ) {
            cout << "Subscriber 2: Value is too high\n";
        }
    });

    // Change the item
    item = 10;
    item = 10;
    item = 30;
    
    return 0;
}
