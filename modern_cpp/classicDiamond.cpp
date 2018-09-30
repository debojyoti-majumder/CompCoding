#include <iostream>

using namespace std;

class Base {
    public:
        int a;
};

class Derived1 : virtual public Base {
    public:
        int b;

        Derived1() {
            this->a = 10;
            this->b = 20;
        }

        friend ostream& operator<<(ostream& out, const Derived1& obj) {
            out << "[" << obj.a << " " << obj.b; "]";
            return out;
        }
};

class Derived2 : virtual public Base {
    public:
        int c;
    
    Derived2() {
        this->a = 15;
        this->c = 25;
    }
    
    friend ostream& operator<<(ostream& out, const Derived2& obj) {
        out << "[" << obj.a << " " << obj.c; "]";
        return out;
    }    
};

class Everything : public Derived2, public Derived1 {
    public:
        int getSum() {
            cout << "Super Funny: " << this->a << endl;
            return this->a + this->b + this->c;
        }
};

int main() {
    Everything e;
    cout << e.getSum() << endl;
    return 0;
}
