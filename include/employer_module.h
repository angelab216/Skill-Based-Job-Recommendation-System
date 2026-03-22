#ifndef EMPLOYER_MODULE_H
#define EMPLOYER_MODULE_H

#include <string>
#include <vector>
#include "application.h"

// ------------------------------------------------------------------
// Job struct
// ------------------------------------------------------------------
struct Job {
    int         jobId;
    std::string title;
};

// ------------------------------------------------------------------
// Employer class
// ------------------------------------------------------------------
class Employer {
public:
    std::vector<Job> jobs;

    // Post a new job
    void postJob(int id, std::string title);

    // Edit an existing job's title
    void editJob(int id, std::string newTitle);

    // Delete a job by ID
    void deleteJob(int id);

    // Print all posted jobs
    void viewJobs() const;

    // Show all applicants for a specific job
    void viewApplicants(int jobId, const std::vector<Application>& applications) const;
};

#endif
