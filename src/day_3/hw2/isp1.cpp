#include <iostream>
#include <stdexcept>

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual ~Worker() {}
};

class Employee : public Worker {
public:
    void work() override {
        std::cout << "Employee is working" << std::endl;
    }

    void eat() override {
        std::cout << "Employee is eating" << std::endl;
    }
};

class Robot : public Worker {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }

    void eat() override {
        throw std::logic_error("Robots do not eat");
    }
};

int main() {
    Worker* employee = new Employee();
    employee->work();
    employee->eat();

    Worker* robot = new Robot();
    robot->work();
    robot->eat();

    delete employee;
    delete robot;

    return 0;
}