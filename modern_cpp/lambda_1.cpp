#include <iostream>
#include <functional>

using namespace std;

// x will be passed by the client
template<typename T>
void templated_function(T x) {
    cout << "Step 1" << endl;

    // Calling the functor
    x();

    cout << "Final step" << endl;
}

// This is older way of specifing callbacks
class MyFunctor {
    int x = 0;          // C++11 speciifc
public:
    void operator() () {
        cout << "Display interal state" << x << endl;
    }
};

int main() {
    MyFunctor ftor;

    templated_function(ftor);
    return 0;
}
