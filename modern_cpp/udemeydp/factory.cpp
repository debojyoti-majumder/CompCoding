#include <iostream>
#include <cmath>
#include <memory>

using namespace std;

enum class PointType { Polar, Cartatian };

class BadPoint {
    private:
        float _x, _y;
    public:
        BadPoint(float x, float y) : _x(x), _y(y) {}
    
        friend ostream& operator<< (ostream& os, const BadPoint& p) {
            os << "X:" << p._x << " Y:" << p._y;
            return os;
        }

        ~BadPoint() {
            cout << "Point has been deleted" << endl;
        }
};

class PointFactory {
    public:
        static unique_ptr<BadPoint> buildCertatinaPoint(float x, float y) {
            return make_unique<BadPoint>(x,y);
        }

        static unique_ptr<BadPoint> buildPolarPoint(float x, float y) {
            return make_unique<BadPoint>(x * sin(y), x * cos(y));
        }
};

void processPoint(const BadPoint& p) {
    cout << p << "\t\t";
}

int main() {
    // BadPoint p1{2,0.7,PointType::Polar};
    // BadPoint p2{2,5, PointType::Cartatian};

    auto p1 = PointFactory::buildCertatinaPoint(2,5);
    auto p2 = PointFactory::buildPolarPoint(2,0.7);

    cout << *p1 << endl;
    cout << *p2 << endl;

    return 0;
}
