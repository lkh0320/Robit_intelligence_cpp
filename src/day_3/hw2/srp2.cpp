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

class UserRepository {
public:
    void saveUser(const User& user) {
        std::cout << "User saved to database: " << user.getName() << std::endl;
    }
};

class EmailService {
public:
    void sendWelcomeEmail(const User& user) {
        std::cout << "Welcome email sent to: " << user.getEmail() << std::endl;
    }
};

class UserActivityLogger {
public:
    void logUserActivity(const User& user) {
        std::cout << "Logging activity for user: " << user.getName() << std::endl;
    }
};

class UserService {
private:
    UserRepository userRepository;
    EmailService emailService;
    UserActivityLogger userActivityLogger;

public:
    void registerUser(const User& user) {
        userRepository.saveUser(user);
        emailService.sendWelcomeEmail(user);
        userActivityLogger.logUserActivity(user);
    }
};