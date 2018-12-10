#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

class MySingleTon {
    private:
        MySingleTon() = default;

        static shared_ptr<MySingleTon> _instance;
        static mutex _instanceGaurd;

    public:
        static shared_ptr<MySingleTon> getInstance() {
            lock_guard<mutex> gaurd(_instanceGaurd);

            if( _instance == nullptr )
                _instance = shared_ptr<MySingleTon>(new MySingleTon());

            return _instance;
        }

        void instanceMethod() {
            cout << "[" << this << "] " << "this is a instance method of my singleton\n";
        }

        ~MySingleTon() {
            cout << "Destrctor should get called\n";
        }
};

shared_ptr<MySingleTon> MySingleTon::_instance = nullptr;
mutex MySingleTon::_instanceGaurd;

class UsageClass {
    private:
        shared_ptr<MySingleTon> _singleton;
    public:
        UsageClass(shared_ptr<MySingleTon> dep) : _singleton(dep) {
        }

        void someMethod() {
            cout << "This is going to call the instance method" << endl;
            _singleton->instanceMethod();
        }
};

void someFunction() {
    auto ptr1 {MySingleTon::getInstance()};
    auto ptr2 {MySingleTon::getInstance()};

    ptr1->instanceMethod();
    ptr2->instanceMethod();

}

int main() {    
    UsageClass cl(MySingleTon::getInstance());

    thread t1([&] {
        cl.someMethod();
        someFunction();
    });

    thread t2([]{
        UsageClass c(MySingleTon::getInstance());
        someFunction();
        c.someMethod();
    });

    t1.join();
    t2.join();
    return 0;
}
