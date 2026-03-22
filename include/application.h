#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

class Application {
public:
    int userId;
    int jobId;
    std::string status;

    // Constructor: sets status to "Pending" by default
    Application(int userId, int jobId);

    // Update the application status
    void updateStatus(std::string newStatus);

    // Display application info
    void display() const;
};

#endif
