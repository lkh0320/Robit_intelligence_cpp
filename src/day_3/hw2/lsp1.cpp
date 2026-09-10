#include <iostream>
#include <stdexcept>

class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }
    virtual ~Bird() {}
};

class Penguin : public Bird {
public:
    void fly() override {
        throw std::logic_error("Penguins cannot fly");
    }
};

int main() {
    Bird* bird = new Bird();
    bird->fly();

    Bird* penguin = new Penguin();
    penguin->fly();

    delete bird;
    delete penguin;

    return 0;
}