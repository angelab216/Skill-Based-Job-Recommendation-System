#include "application.h"
#include <iostream>

// Constructor initializes userId, jobId, and sets status to "Pending"
Application::Application(int userId, int jobId) {
    this->userId = userId;
    this->jobId  = jobId;
    this->status = "Pending";
}

// Update the status of the application
void Application::updateStatus(std::string newStatus) {
    status = newStatus;
    std::cout << "  [Status Updated] User " << userId
              << "'s application for Job " << jobId
              << " is now: " << status << "\n";
}

// Display a single application record
void Application::display() const {
    std::cout << "  User ID: " << userId
              << " | Job ID: " << jobId
              << " | Status: " << status << "\n";
}
