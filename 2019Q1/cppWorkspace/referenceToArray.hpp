#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
const int totalCount {10};

struct UserData {
    string name;
    int objectId;

    UserData() {
        static int count;
        count = count + 1;
        stringstream ss;
        ss << "User " << count;
        
        name = ss.str();
        objectId = count;
    }

    ~UserData() {
        cout << "Object " << objectId << " freed" << endl;
    }
};

UserData* simpleAllocator(int num) {
    return new UserData[num];
}

UserData (*staticAllocator())[totalCount] {
    static UserData m[totalCount];
    return &m;
}

UserData (&staticReferenceAllocator())[totalCount] {
    static UserData m[totalCount];
    return m;
}

void simpleUsage(int num = 10) {
    auto userCollection = simpleAllocator(num);

    for(auto i=0; i<num; i++)
        cout << userCollection[i].name << endl;

    delete[] userCollection;
}

int main(int argc, char** argv) {
    simpleUsage();
    auto items { staticAllocator() };
    cout << items[2]->name  << "<--------------------" << endl;

    auto reffItem { staticReferenceAllocator() };
    cout << reffItem[2].name << "<--------------------" << endl;

    return 0;
}