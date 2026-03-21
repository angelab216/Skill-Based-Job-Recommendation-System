#include "../include/user.h"
#include <fstream>
#include <iostream>

User::User(int id, std::string username, std::string password, std::string role)
    : id(id), username(username), password(password), role(role) {}

int User::getId() const { return id; }
std::string User::getUsername() const { return username; }
std::string User::getRole() const { return role; }

bool User::authenticate(std::string& inputPassword) const {
    return password == inputPassword;
}

void User::saveToFile(std::ofstream& out) const {
    out << id << "," << username << "," << password << "," << role;
}

void User::loadFromFile(std::ifstream& in) {
    char comma;
    in >> id >> comma >> username >> comma >> password >> comma >> role;
}