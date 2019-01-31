#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

struct Shape {
public:
	virtual string str() const = 0;
	virtual ~Shape() = default;
};

struct Circle : public Shape {
private:
	int radius;
public:
	explicit Circle(int r) : radius(r) {}
	string str() const override {
		ostringstream oss;
		oss << "This is a circle with radius" << radius;

		return oss.str();
	}
};

struct Suqare : public Shape {
private:
	int width;
public:
	explicit Suqare(int w) : width(w) {}
	string str() const override {
		ostringstream oss;
		oss << "This is a square with width" << width;

		return oss.str();
	}
};

// We are able to create a colored shape without changing the Shape object, this is a example of dynamic decerator. 
// Useful when we don't have the source code for the "Shape" class
struct ColoredDecorator : public Shape {
private:
	Shape& shape;
	string color;

public:
	ColoredDecorator(Shape& s, string col) : shape(s), color(col) {}
	string str() const override {
		ostringstream oss;
		oss << shape.str() << " with color" << color;

		return oss.str();
	}
};

int main() {
	Suqare s1{ 2 };
	Circle c1{ 5 };

	ColoredDecorator redSquare{ s1, "red" };
	ColoredDecorator greenCircle{ c1, "green" };

	cout << redSquare.str() << endl;
	cout << greenCircle.str() << endl;
	return 0;
}
