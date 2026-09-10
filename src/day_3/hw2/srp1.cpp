#include <iostream>
#include <string>

class User {
private:
    std::string name;
    std::string email;

public:
    User(const std::string& name, const std::string& email)
        : name(name), email(email) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};

class UserService {
public:
    void saveUser(const User& user) {
        std::cout << "User saved to database: " << user.getName() << std::endl;
    }

    void sendWelcomeEmail(const User& user) {
        std::cout << "Welcome email sent to: " << user.getEmail() << std::endl;
    }

    void logUserActivity(const User& user) {
        std::cout << "Logging activity for user: " << user.getName() << std::endl;
    }
};