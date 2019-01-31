#include <iostream>
#include <functional>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Observable {
    private:
        const T& _container;
        vector<function<void(T)>> _subscribers;

    protected:
        void notify() {
            for(auto fn : _subscribers) {
                fn(_container);
            }
        }

    public:
        Observable() = delete;

        Observable(const T& obj) : _container(obj) {

        }

        void addSubscriber(function<void(T)> func) {
            _subscribers.emplace_back(func);
        }

        Observable<T>& operator=(const Observable<T>& rhs) {
            changeValue(rhs._container);
            notify();
            return *(this);
        }

        virtual void changeValue(const T& rhs) = 0; 
};


class Parameter : public Observable<Parameter> {
    private:
        int     _value;
        string  _units;
    public:
        Parameter() : Observable<Parameter>(*this) {
            _value = 0;
            _units = "db";
        }

        Parameter(int p) : Observable<Parameter>(*this), _value(p) , _units("untis") {}

        friend ostream& operator<<(ostream& out, const Parameter& p) {
            out << p._value << " " << p._units;
            return out;
        }

        void changeValue(const Parameter& p) override {
            _value = p._value;
            _units = p._units;
        }
};

int main() {
    Parameter p1 , p2(10);

    p1.addSubscriber([](Parameter p) {
        cout << "First Subscribers:" << p << "\n";
    });

    p1.addSubscriber([](Parameter p) {
        cout << "Second Subscribers:" << p << "\n";
    });

    cout << p1 << "\n";
    p1 = p2;
    cout << p1 << "\n";
    return 0;
}
