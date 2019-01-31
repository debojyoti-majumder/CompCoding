#include <vector>

#ifndef _HELPER_FUNC
#define _HELPER_FUNC

template<typename T>
void printVectorItems(std::vector<T> items) {
        std::cout << "[";
        
        for(auto item : items) {
            std::cout << item;
            if( item != *(items.end() - 1 )) 
                std::cout << ",";
        }

        std::cout << "]" << std::endl;

}

#endif
