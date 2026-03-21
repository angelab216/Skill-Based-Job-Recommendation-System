#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "user.h"
#include <vector>
#include <string>

class Candidate : public User {
private:
    std::vector<std::string> skills;
    std::vector<int> appliedJobs;
    int profileStrength;

public:
    Candidate(int id = 0, std::string username = "", std::string password = "", std::string role = "candidate");
    void addSkill(const std::string& skill);
    void viewJobs() const; // will need job data later
    void applyForJob(int jobId);
    void viewSkillGap(int jobId);
    int calculateProfileStrength() const;

    void displayMenu() override;
    void saveToFile(std::ofstream& out) const override;
    void loadFromFile(std::ifstream& in) override;
};

#endif