#include <iostream>

using namespace std;

class Rectangle {
    protected:
        unsigned int _width;
        unsigned int _height;
    public:
        Rectangle(unsigned int w, unsigned int h) : _width(w), _height(h) {

        }

        int getHeight() const {
            return _height;
        }

        virtual void setHeight(unsigned int h) {
            _height = h;
        }

        unsigned int getWidth() const {
            return _width;
        }

        virtual void setWidth(unsigned int w) {
            _width = w;
        }

        long getArea() {
            return _width * _height;
        }
};

class Square : public Rectangle {
    public:
        // This is how I am calling the base class ctor
        Square(int s) : Rectangle(s,s) {

        }

        void setHeight(unsigned int h) override {
            cout << "Setting height in square" << endl; 
            _height = _width = h;
        }

        void setWidth(unsigned int w) override {
            cout << "Setting width in square" << endl;
            _height = _width = w;
        }
};

// A factory would be a possible solution. Unsing composition might be a better idea and inheritance
// or adding an interface with IShape with area
class ShapeFactory {
    Rectangle* createReactAngle() {
        return new Rectangle{10,20};
    }

    Square* createSquare() {
        return new Square{10};
    }
};

// This test will break the liskovs substitution principle. When the Squere(which is the derived class)
// is substituted with the Rectangle(which is base class)
void unitTestForRect(Rectangle& r) {
    auto w = r.getWidth();
    r.setHeight(10);

    auto area = r.getArea(); 
    cout << "Area Got:" << area << " Expected:" << w*10 << endl;
}

int main() {
    Rectangle r{12,3};
    Square s{20};

    unitTestForRect(r);
    unitTestForRect(s);

    return 0;
}
