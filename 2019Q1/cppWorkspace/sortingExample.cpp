#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(const vector<T>& container) {
    for(auto const& str: container)
        cout << str << " ";

    cout << endl;
}

int main(int, char**) {
    vector<string> outStrings {"BACD","Mcafee an Intel company", "Harman a Samsung Company", "VMware"};
    
    // Original list of items
    printVector(outStrings);
    
    //Defaul sorting 
    sort(outStrings.begin(), outStrings.end());
    printVector(outStrings);

    // User defined sorting
    sort(outStrings.begin(), outStrings.end(), [](const string& obj1, const string obj2){
        return obj1.length() < obj2.length();
    });
    printVector(outStrings);

    return 0;
}
