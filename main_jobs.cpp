#include <iostream>
#include <vector>
#include <string>
#include <limits>    // std::numeric_limits
#include "application.h"
#include "employer_module.h"

using namespace std;

// ------------------------------------------------------------------
// Helper: check for duplicate application
// ------------------------------------------------------------------
bool alreadyApplied(const vector<Application>& apps, int userId, int jobId) {
    for (const Application& a : apps) {
        if (a.userId == userId && a.jobId == jobId) {
            return true;
        }
    }
    return false;
}

// ------------------------------------------------------------------
// Helper: check if a job ID exists in employer's list
// ------------------------------------------------------------------
bool jobExists(const Employer& emp, int jobId) {
    for (const Job& j : emp.jobs) {
        if (j.jobId == jobId) return true;
    }
    return false;
}

// ------------------------------------------------------------------
// Menu helpers
// ------------------------------------------------------------------
void printMainMenu() {
    cout << "\n========================================\n";
    cout << "     Smart Job Matching System          \n";
    cout << "========================================\n";
    cout << " 1. Post a Job\n";
    cout << " 2. View All Jobs\n";
    cout << " 3. Edit a Job\n";
    cout << " 4. Delete a Job\n";
    cout << " 5. Apply to a Job\n";
    cout << " 6. View All Applications\n";
    cout << " 7. View Applicants for a Job\n";
    cout << " 8. Update Application Status\n";
    cout << " 0. Exit\n";
    cout << "========================================\n";
    cout << " Enter your choice: ";
}

int getIntInput() {
    int val;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [Error] Please enter a valid number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return val;
}

// ------------------------------------------------------------------
// Main
// ------------------------------------------------------------------
int main() {
    Employer employer;
    vector<Application> applications;

    // --- Pre-load some demo data so the system isn't empty on start ---
    cout << "\n[Demo] Pre-loading sample jobs...\n";
    employer.postJob(101, "Software Engineer");
    employer.postJob(102, "Data Analyst");
    employer.postJob(103, "UI/UX Designer");

    int choice;
    do {
        printMainMenu();
        choice = getIntInput();

        switch (choice) {

        // ---- 1. Post a Job ----------------------------------------
        case 1: {
            cout << "  Enter Job ID: ";
            int id = getIntInput();
            cout << "  Enter Job Title: ";
            string title;
            getline(cin, title);
            employer.postJob(id, title);
            break;
        }

        // ---- 2. View All Jobs -------------------------------------
        case 2:
            employer.viewJobs();
            break;

        // ---- 3. Edit a Job ----------------------------------------
        case 3: {
            cout << "  Enter Job ID to edit: ";
            int id = getIntInput();
            cout << "  Enter new title: ";
            string title;
            getline(cin, title);
            employer.editJob(id, title);
            break;
        }

        // ---- 4. Delete a Job --------------------------------------
        case 4: {
            cout << "  Enter Job ID to delete: ";
            int id = getIntInput();
            employer.deleteJob(id);
            break;
        }

        // ---- 5. Apply to a Job ------------------------------------
        case 5: {
            cout << "  Enter your User ID: ";
            int uid = getIntInput();
            cout << "  Enter Job ID to apply for: ";
            int jid = getIntInput();

            if (!jobExists(employer, jid)) {
                cout << "  [Error] Job ID " << jid << " does not exist.\n";
            } else if (alreadyApplied(applications, uid, jid)) {
                cout << "  [Duplicate] User " << uid
                     << " has already applied for Job " << jid << ".\n";
            } else {
                applications.emplace_back(uid, jid);
                cout << "  [Success] Application submitted! Status: Pending\n";
            }
            break;
        }

        // ---- 6. View All Applications -----------------------------
        case 6:
            if (applications.empty()) {
                cout << "  No applications yet.\n";
            } else {
                cout << "  --- All Applications ---\n";
                for (const Application& a : applications) {
                    a.display();
                }
                cout << "  ------------------------\n";
            }
            break;

        // ---- 7. View Applicants for a Job ------------------------
        case 7: {
            cout << "  Enter Job ID: ";
            int jid = getIntInput();
            employer.viewApplicants(jid, applications);
            break;
        }

        // ---- 8. Update Application Status ------------------------
        case 8: {
            cout << "  Enter User ID: ";
            int uid = getIntInput();
            cout << "  Enter Job ID: ";
            int jid = getIntInput();
            cout << "  Enter new status (Pending / Accepted / Rejected): ";
            string ns;
            getline(cin, ns);

            bool updated = false;
            for (Application& a : applications) {
                if (a.userId == uid && a.jobId == jid) {
                    a.updateStatus(ns);
                    updated = true;
                    break;
                }
            }
            if (!updated) {
                cout << "  [Error] No application found for User "
                     << uid << " and Job " << jid << ".\n";
            }
            break;
        }

        // ---- 0. Exit ---------------------------------------------
        case 0:
            cout << "  Goodbye!\n";
            break;

        default:
            cout << "  [Error] Invalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
