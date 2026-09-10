#include <iostream>

class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

class Employee : public Workable, public Eatable {
public:
    void work() override {
        std::cout << "Employee is working" << std::endl;
    }

    void eat() override {
        std::cout << "Employee is eating" << std::endl;
    }
};

class Robot : public Workable {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }
};

int main() {
    Workable* employee = new Employee();
    employee->work();
    dynamic_cast<Eatable*>(employee)->eat();

    Workable* robot = new Robot();
    robot->work();

    delete employee;
    delete robot;

    return 0;
}