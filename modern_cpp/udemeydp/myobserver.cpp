#include <iostream>
#include <functional>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class DataItem {
    private:
        T& _value;
        vector<function<void(T)>> _subscribers;

    public:
        DataItem() = delete;

        explicit DataItem(T& b) : _value(b) {}

        DataItem& operator=(T v) {
            if( _value != v ) {
                cout << "Data item changed. \n";
                _value = v;

                for( auto subs : _subscribers ) {
                    subs(v);
                }
            }

            return *this;
        }

        void addSubScriber(const function<void(T)>& fnc) {
            _subscribers.emplace_back(fnc);
        }        
};

int main() {
    int i=0;
    DataItem<int> item(i);

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

    string stringData("Debojyoti");
    DataItem<string> stringItem(stringData);

    stringItem.addSubScriber([](string v) {
        cout << "String changed:" << v << "\n";
    });

    stringItem = "ABCD";
    return 0;
}
