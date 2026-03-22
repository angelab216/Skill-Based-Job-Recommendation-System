#include "employer_module.h"
#include <iostream>
#include <algorithm>   // std::find_if

// Post a new job; prevents duplicate job IDs
void Employer::postJob(int id, std::string title) {
    for (const Job& j : jobs) {
        if (j.jobId == id) {
            std::cout << "  [Error] Job ID " << id << " already exists.\n";
            return;
        }
    }
    jobs.push_back({id, title});
    std::cout << "  [Job Posted] ID: " << id << " | Title: " << title << "\n";
}

// Edit the title of an existing job
void Employer::editJob(int id, std::string newTitle) {
    for (Job& j : jobs) {
        if (j.jobId == id) {
            std::cout << "  [Job Edited] ID: " << id
                      << " | '" << j.title << "' -> '" << newTitle << "'\n";
            j.title = newTitle;
            return;
        }
    }
    std::cout << "  [Error] Job ID " << id << " not found.\n";
}

// Delete a job by its ID
void Employer::deleteJob(int id) {
    for (auto it = jobs.begin(); it != jobs.end(); ++it) {
        if (it->jobId == id) {
            std::cout << "  [Job Deleted] ID: " << id
                      << " | Title: " << it->title << "\n";
            jobs.erase(it);
            return;
        }
    }
    std::cout << "  [Error] Job ID " << id << " not found.\n";
}

// Print all currently posted jobs
void Employer::viewJobs() const {
    if (jobs.empty()) {
        std::cout << "  No jobs posted yet.\n";
        return;
    }
    std::cout << "  --- Job Listings ---\n";
    for (const Job& j : jobs) {
        std::cout << "  Job ID: " << j.jobId
                  << " | Title: " << j.title << "\n";
    }
    std::cout << "  --------------------\n";
}

// Show all applicants for a given job
void Employer::viewApplicants(int jobId,
                               const std::vector<Application>& applications) const {
    std::cout << "  --- Applicants for Job ID " << jobId << " ---\n";
    bool found = false;
    for (const Application& app : applications) {
        if (app.jobId == jobId) {
            app.display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "  No applicants yet.\n";
    }
    std::cout << "  ------------------------------\n";
}
