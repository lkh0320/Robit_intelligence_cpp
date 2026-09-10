#include <iostream>

class Rectangle {
protected:
    int width;
    int height;

public:
    Rectangle() : width(0), height(0) {}

    virtual void setWidth(int width) {
        this->width = width;
    }

    virtual void setHeight(int height) {
        this->height = height;
    }

    int getArea() const {
        return width * height;
    }

    virtual ~Rectangle() {}
};

class Square : public Rectangle {
public:
    void setWidth(int width) override {
        this->width = width;
        this->height = width;
    }

    void setHeight(int height) override {
        this->width = height;
        this->height = height;
    }
};

class AreaCalculator {
public:
    void calculateArea(Rectangle& rectangle) {
        rectangle.setWidth(5);
        rectangle.setHeight(4);
        std::cout << "Area: " << rectangle.getArea() << std::endl;
    }
};