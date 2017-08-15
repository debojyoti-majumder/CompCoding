#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    auto numbers = vector<int>{4, 7, 9, -4, -5};
    
    auto positives = std::count_if(numbers.begin(), numbers.end(),
        [](const int p){
            return p > 0;
        });
    
    cout << positives << endl;
    return 0;
}
