#include <iostream>
#include <vector>

int main() {
    int all_items[] = {90,9,67,89,8,78,9};

    std::vector<int> v(all_items, all_items + sizeof(all_items)/sizeof(int));
    std::cout << "C++ 11 Working good" << std::endl;
    
    for(auto it=v.begin(); it!=v.end(); ++it)
        std::cout << "Number :" << *it << std::endl;

    return 0;
}