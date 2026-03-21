#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
protected:
    int id;
    std::string username;
    std::string password;
    std::string role;

public:
    User(int id = 0, std::string username = "", std::string password = "", std::string role = "");
    virtual ~User() {}

    // Getters
    int getId() const;
    std::string getUsername() const;
    std::string getRole() const;

    // Authentication
    bool authenticate(std::string& inputPassword) const;

    // Virtual menu
    virtual void displayMenu() = 0;

    // File handling
    virtual void saveToFile(std::ofstream& out) const;
    virtual void loadFromFile(std::ifstream& in);
};

#endif