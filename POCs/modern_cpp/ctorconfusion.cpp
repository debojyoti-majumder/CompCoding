#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class InitparamConfusion {
    int _x, _y;
    float _a, _b;

    public:
        explicit InitparamConfusion(int m) : _x(m) {
            cout << "This is the old constructor" << endl;
        }

        InitparamConfusion(const InitparamConfusion& rhs) {
            cout << "This is the copy ctor" << endl;
        }

        InitparamConfusion(initializer_list<string> strArgs) {
            cout << "This is new cotr with string args" << endl;
            auto sz = strArgs.size();

            if( sz < 2 ) throw string{"This is bad"};
            for( auto p : strArgs )
                cout << p << " ";
            cout << endl;
        }

        InitparamConfusion(initializer_list<int> args) {
            cout << "This is new init ctor with int" << endl;
            auto sz = args.size();
            for( auto e : args ) {
                cout << e << " ";
            }
            cout << endl;

            if( sz == 1 ) {
                _x = *(args.begin());
                _y = 0;
            }
            else {
                _x = *(args.begin());
                _y = *(args.begin() + 1);
            }
        }

        operator string() const {
            cout << "This is the conversion opeartor in action" << endl;
            stringstream ss;
            ss << "[x=" << _x << ", y=" << _y;
            ss << "]";

            return ss.str();            
        }
        
        void printValues() {
            cout << _x << " " << _y << endl;
        }
};

class MyVector {
    private:
        vector<int> _container;

    public:
        MyVector(int n) {
            cout << "Ctro number 1" << endl;

            for(int i=0; i<n; i++) {
                _container.push_back(10);
            }
        }

        MyVector(int n, int initValue) {
            cout << "Ctro number 2" << endl;
            for(int i=0; i<n; i++) {
                _container.push_back(initValue + 1);
            }
        }

        MyVector(initializer_list<int> items) {
            cout << "Ctro number 3" << endl;
            for(auto it : items ) {
                _container.push_back(it + 10);
            }
        }

        void printValues() {
            cout << "[";
            for( auto m : _container )
                cout << m << ",";
            cout << "]" << endl;
        }
};
int main(int argc, char const *argv[]) {
    
    // InitparamConfusion c1(1);
    // InitparamConfusion c2{2};
    InitparamConfusion c3{1,6,7,3};
    InitparamConfusion c4(c3);
    InitparamConfusion c5{c4, c4};
    string str("abc");

    // c1.printValues();
    // c2.printValues();
    // c3.printValues();
    // c4.printValues();
    // c5.printValues();

    MyVector v1(10);
    MyVector v2(5,-9);
    MyVector v3{23,7,8,0,67};
    MyVector tricky{30,31};

    // str = (string) c3;
    // cout << str << endl;

    v1.printValues();
    v2.printValues();
    v3.printValues();
    tricky.printValues();
    
    return 0;
}
