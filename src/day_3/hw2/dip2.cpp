#include <iostream>

class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Switchable() {}
};

class Fan : public Switchable {
public:
    void turnOn() override {
        std::cout << "Fan is spinning" << std::endl;
    }

    void turnOff() override {
        std::cout << "Fan is stopping" << std::endl;
    }
};

class Switch {
private:
    Switchable* device;

public:
    Switch(Switchable* device) : device(device) {}

    void turnOn() {
        device->turnOn();
    }

    void turnOff() {
        device->turnOff();
    }
};