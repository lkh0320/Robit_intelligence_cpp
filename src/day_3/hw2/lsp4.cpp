#include <iostream>

class Shape {
public:
    virtual int getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getArea() const override {
        return width * height;
    }
};

class Square : public Shape {
private:
    int side;

public:
    Square(int side) : side(side) {}

    int getArea() const override {
        return side * side;
    }
};

class AreaCalculator {
public:
    void calculateArea(const Shape& shape) {
        std::cout << "Area: " << shape.getArea() << std::endl;
    }
};

int main() {
    AreaCalculator calculator;

    Shape* rectangle = new Rectangle(5, 4);
    calculator.calculateArea(*rectangle);

    Shape* square = new Square(5);
    calculator.calculateArea(*square);

    delete rectangle;
    delete square;

    return 0;
}