#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include "../models/case.h"
#include "PoliceOfficer.h"

using namespace std;

PoliceOfficer::PoliceOfficer()
    : officerId(0), name(""), rank(""), username(""),
      password(""), available(false) {}

PoliceOfficer::PoliceOfficer(int id, string officerName,
                             string officerRank, string officerUsername,
                             bool officerAvailable)
    : officerId(id), name(officerName), rank(officerRank),
      username(officerUsername), password(""),
      available(officerAvailable) {}

PoliceOfficer::PoliceOfficer(int id, string officerName,
                             string officerRank, string officerUsername,
                             string officerPassword, bool officerAvailable)
    : officerId(id), name(officerName), rank(officerRank),
      username(officerUsername), password(officerPassword),
      available(officerAvailable) {}

void PoliceOfficer::displayOfficer()
{
    cout << "\nOfficer ID: " << officerId
         << "\nName: " << name
         << "\nRank: " << rank
         << "\nUsername: " << username
         << "\nAvailability: " << (available ? "Available" : "Unavailable")
         << "\n";
}

int PoliceOfficer::getOfficerId() { return officerId; }
string PoliceOfficer::getName() { return name; }
string PoliceOfficer::getRank() { return rank; }
string PoliceOfficer::getUsername() { return username; }
string PoliceOfficer::getPassword() { return password; }
bool PoliceOfficer::isAvailable() { return available; }

void PoliceOfficer::setAvailability(bool value)
{
    available = value;
}

bool loadOfficers(vector<PoliceOfficer>& officers)
{
    ifstream file("officers.txt");

    if (!file.is_open())
        return false;

    officers.clear();
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string idText, officerName, officerRank;
        string officerUsername, officerPassword, availableText;

        if (!getline(ss, idText, '|') ||
            !getline(ss, officerName, '|') ||
            !getline(ss, officerRank, '|') ||
            !getline(ss, officerUsername, '|') ||
            !getline(ss, officerPassword, '|') ||
            !getline(ss, availableText))
            continue;

        try
        {
            int id = stoi(idText);
            bool isAvailable = (availableText == "1");

            officers.emplace_back(id, officerName, officerRank,
                                  officerUsername, officerPassword,
                                  isAvailable);
        }
        catch (...)
        {
            continue;
        }
    }

    return true;
}

bool saveOfficers(const vector<PoliceOfficer>& officers)
{
    ofstream file("officers.txt");

    if (!file.is_open())
        return false;

    // Use a non-const reference because the existing getters are not const.
    for (auto& officer : const_cast<vector<PoliceOfficer>&>(officers))
    {
        file << officer.getOfficerId() << '|'
             << officer.getName() << '|'
             << officer.getRank() << '|'
             << officer.getUsername() << '|'
             << officer.getPassword() << '|'
             << (officer.isAvailable() ? 1 : 0) << '\n';
    }

    return file.good();
}

void PoliceOfficer::showDashboard()
{
    vector<Case> cases;
    loadCases(cases);

    int choice = 0;

    do
    {
        cout << "\n========== POLICE OFFICER DASHBOARD ==========\n";
        cout << "1. View Officer Profile\n";
        cout << "2. View Assigned Cases\n";
        cout << "3. Search Case by ID\n";
        cout << "4. Update Case Status\n";
        cout << "5. View All Cases\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
        {
            displayOfficer();
        }
        else if (choice == 2)
        {
            cout << "\n========== ASSIGNED CASES ==========\n";
            bool found = false;

            for (auto& c : cases)
            {
                if (c.getAssignedOfficerId() == officerId)
                {
                    c.displayCase();
                    found = true;
                }
            }

            if (!found)
                cout << "No cases assigned to you.\n";
        }
        else if (choice == 3)
        {
            int searchId;
            cout << "Enter Case ID: ";

            if (!(cin >> searchId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid case ID.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool found = false;

            for (auto& c : cases)
            {
                if (c.getCaseId() == searchId)
                {
                    c.displayCase();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Case not found.\n";
        }
        else if (choice == 4)
        {
            int updateId;
            cout << "Enter Case ID to update: ";

            if (!(cin >> updateId))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid case ID.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool found = false;

            for (auto& c : cases)
            {
                if (c.getCaseId() == updateId)
                {
                    if (c.getAssignedOfficerId() != officerId)
                    {
                        cout << "You can only update cases assigned to you.\n";
                        found = true;
                        break;
                    }

                    string newStatus;
                    cout << "Enter new status (Open / Under Investigation / Closed): ";
                    getline(cin, newStatus);

                    string oldStatus = c.getStatus();
                    c.setStatus(newStatus);

                    if (saveCases(cases))
                        cout << "Case status updated successfully.\n";
                    else
                    {
                        c.setStatus(oldStatus);
                        cout << "Could not save case changes.\n";
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Assigned case not found.\n";
        }
        else if (choice == 5)
        {
            cout << "\n========== ALL CASES ==========\n";

            if (cases.empty())
                cout << "No cases available.\n";
            else
                for (auto& c : cases)
                    c.displayCase();
        }
        else if (choice == 0)
        {
            cout << "Logging out...\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);
}