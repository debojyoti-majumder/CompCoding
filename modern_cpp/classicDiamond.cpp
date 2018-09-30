// This is an example of virtual base class, where the compiler gets confused becuase of multiple inhertinece and about which 
// base class copy should be saved. The "virtual" keyword tell the compiler to only keep on copy of the base class to 
// void ambiguation.

// In the this exmaple of "Everything" class inheritence has been done from mutitple base class the order of the inheritence 
// determines the output of the program. 

// In this perticular exmaple the base class copy of the right most item has been saved.

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
