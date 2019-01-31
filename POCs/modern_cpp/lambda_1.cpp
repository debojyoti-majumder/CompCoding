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

void proper_template_function(function<int(string)> func) {
    cout << "Int value from string :" << func("hello world") << endl;
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

    // Older way of invoking a callback
    templated_function(ftor);

    // Lambdas can be passed to the same templated function
    templated_function([](){
        cout << "Un named function" << endl;
    });

    proper_template_function([](string m){
        return m.length() - 1;
    });

    proper_template_function([](string m){
        return 0;
    });

    return 0;
}
