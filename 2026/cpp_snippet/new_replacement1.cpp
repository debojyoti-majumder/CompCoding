// A very basic demonstation of how we can create an Arena and use
// new replacement to create objects which works as any other standard object.

// Follow up 1 : May be a memory mapped file and some with some persisted
// values

// Follow up 2: Make the object creation generic and use templates

#include <iostream>
#include <string>
#include <new>

class Arena {
private:
    uint8_t* buffer;
    const size_t capacity;
    size_t offset;
 
public:
    explicit Arena(size_t sz) : capacity(sz), offset(0) {
        buffer = new uint8_t[sz];
    }

    ~Arena() {
        delete[] buffer;
    }

    // Avoiding copy from different arena objects
    Arena(const Arena&) = delete;
    Arena& operator=(const Arena&) = delete;

    // If the client requires memory then this function is called
    void* alloc(size_t sz) {
        if (offset + sz > capacity) {
            throw std::bad_alloc();
        }

        void *current = &buffer[offset];

        offset += sz;
        return current;
    }

    void reset() {
        offset = 0;
    }
};

// An arena of 40 KB
static Arena globalArena(1024 * 40);

struct Point3D {
    int x,y,z;

    Point3D() {
        x = y = z = 0;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point3D& obj) {
        out << "[" << obj.x << "," 
            << obj.y << "," 
            << obj.z <<"]";

        return out;
    }
};

void basicUsage() {
    std::cout << "Using a very basic usage";

    void *rawMem = globalArena.alloc(sizeof(Point3D));
    Point3D* newPoint = new(rawMem) Point3D{};

    // Printing out newly allocated obj
    newPoint->x = 90;
    std::cout << *newPoint << std::endl;

    rawMem = globalArena.alloc(sizeof(Point3D));
    Point3D* secPoint = new(rawMem)Point3D{};
    secPoint->y = 8;
    std::cout << *secPoint << std::endl;
}

int main(int, char**) {
    std::cout << "Hello, from arena!\n";
    basicUsage();
}
