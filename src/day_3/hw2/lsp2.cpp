#include <iostream>

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

class Bird {
public:
    void eat() {
        std::cout << "Bird is eating" << std::endl;
    }
    virtual ~Bird() {}
};

class Sparrow : public Bird, public Flyable {
public:
    void fly() override {
        std::cout << "Sparrow is flying" << std::endl;
    }
};

class Penguin : public Bird {
};

int main() {
    Bird* sparrow = new Sparrow();
    sparrow->eat();
    dynamic_cast<Flyable*>(sparrow)->fly();

    Bird* penguin = new Penguin();
    penguin->eat();

    delete sparrow;
    delete penguin;

    return 0;
}