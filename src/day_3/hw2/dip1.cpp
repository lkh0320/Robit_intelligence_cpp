#include <iostream>

class Fan {
public:
    void spin() {
        std::cout << "Fan is spinning" << std::endl;
    }

    void stop() {
        std::cout << "Fan is stopping" << std::endl;
    }
};

class Switch {
private:
    Fan* fan;

public:
    Switch(Fan* fan) : fan(fan) {}

    void turnOn() {
        fan->spin();
    }

    void turnOff() {
        fan->stop();
    }
};