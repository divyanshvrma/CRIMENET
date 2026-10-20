#include <iostream>
#include <limits>
#include <string>
#include "Admin.h"

using namespace std;

Admin::Admin()
{
    loadOfficers(officers);
    loadCases(cases);
}

void Admin::dashboard()
{
    int choice = 0;

    do
    {
        cout << "\n========== CRIMENET ADMIN DASHBOARD ==========\n";
        cout << "1. Manage Users\n";
        cout << "2. Manage Police Officers\n";
        cout << "3. Manage Cases\n";
        cout << "4. View Reports\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice)
        {
            case 1: manageUsers(); break;
            case 2: manageOfficers(); break;
            case 3: manageCases(); break;
            case 4: viewReports(); break;
            case 5: cout << "Logging out...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

void Admin::showDashboard()
{
    dashboard();
}

// ================= USER MANAGEMENT =================

void Admin::manageUsers()
{
    int choice = 0;

    do
    {
        cout << "\n========== USER MANAGEMENT ==========\n";
        cout << "1. Add User\n";
        cout << "2. View Users\n";
        cout << "3. Search User\n";
        cout << "4. Delete User\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1: addUser(); break;
            case 2: viewUsers(); break;
            case 3: searchUser(); break;
            case 4: deleteUser(); break;
            case 5: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

void Admin::addUser()
{
    int id;
    string name, username, password, role;

    cout << "Enter User ID: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID.\n";
        return;
    }

    for (auto& user : users)
    {
        if (user.getUserId() == id)
        {
            cout << "User ID already exists.\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    cout << "Enter Role (Admin/Dispatcher/Officer): ";
    getline(cin, role);

    users.emplace_back(id, name, username, password, role);
    cout << "User added successfully.\n";
}

void Admin::viewUsers()
{
    if (users.empty())
    {
        cout << "No users found.\n";
        return;
    }

    for (auto& user : users)
        user.displayUser();
}

void Admin::searchUser()
{
    int id;
    cout << "Enter User ID to search: ";

    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID.\n";
        return;
    }

    for (auto& user : users)
    {
        if (user.getUserId() == id)
        {
            user.displayUser();
            return;
        }
    }

    cout << "User not found.\n";
}

void Admin::deleteUser()
{
    int id;
    cout << "Enter User ID to delete: ";

    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID.\n";
        return;
    }

    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (it->getUserId() == id)
        {
            users.erase(it);
            cout << "User deleted successfully.\n";
            return;
        }
    }

    cout << "User not found.\n";
}

// ================= POLICE OFFICER MANAGEMENT =================

void Admin::manageOfficers()
{
    int choice = 0;

    do
    {
        cout << "\n========== POLICE OFFICER MANAGEMENT ==========\n";
        cout << "1. Register Police Officer\n";
        cout << "2. View Police Officers\n";
        cout << "3. Search Police Officer\n";
        cout << "4. Delete Police Officer\n";
        cout << "5. Back\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1: addOfficer(); break;
            case 2: viewOfficers(); break;
            case 3: searchOfficer(); break;
            case 4: deleteOfficer(); break;
            case 5: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

void Admin::addOfficer()
{
    int id;
    string name, rank, username, password;
    char availability;

    cout << "Enter Officer ID: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID.\n";
        return;
    }

    if (id <= 0)
    {
        cout << "Officer ID must be positive.\n";
        return;
    }

    for (auto& officer : officers)
    {
        if (officer.getOfficerId() == id)
        {
            cout << "Officer ID already exists.\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Rank: ";
    getline(cin, rank);
    cout << "Enter Username: ";
    getline(cin, username);

    if (username.empty() || username.find('|') != string::npos)
    {
        cout << "Invalid username. Do not use '|'.\n";
        return;
    }

    for (auto& officer : officers)
    {
        if (officer.getUsername() == username)
        {
            cout << "Username already exists.\n";
            return;
        }
    }

    cout << "Set Officer Password: ";
    getline(cin, password);

    if (password.empty() || password.find('|') != string::npos)
    {
        cout << "Invalid password. Do not use '|'.\n";
        return;
    }

    cout << "Available? (y/n): ";
    if (!(cin >> availability))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.\n";
        return;
    }

    bool available = (availability == 'y' || availability == 'Y');

    officers.emplace_back(id, name, rank, username, password, available);

    if (saveOfficers(officers))
    {
        cout << "Police officer registered successfully.\n";
        cout << "The officer can now log in with these credentials.\n";
    }
    else
    {
        officers.pop_back();
        cout << "Error saving officer credentials to officers.txt.\n";
    }
}

void Admin::viewOfficers()
{
    if (officers.empty())
    {
        cout << "No police officers registered.\n";
        return;
    }

    for (auto& officer : officers)
        officer.displayOfficer();
}

void Admin::searchOfficer()
{
    int id;
    cout << "Enter Officer ID to search: ";

    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID.\n";
        return;
    }

    for (auto& officer : officers)
    {
        if (officer.getOfficerId() == id)
        {
            officer.displayOfficer();
            return;
        }
    }

    cout << "Police officer not found.\n";
}

void Admin::deleteOfficer()
{
    int id;
    cout << "Enter Officer ID to delete: ";

    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid ID.\n";
        return;
    }

    for (auto it = officers.begin(); it != officers.end(); ++it)
    {
        if (it->getOfficerId() == id)
        {
            PoliceOfficer deletedOfficer = *it;
            officers.erase(it);

            if (saveOfficers(officers))
            {
                cout << "Police officer deleted successfully.\n";
            }
            else
            {
                officers.push_back(deletedOfficer);
                cout << "Could not save changes; deletion cancelled.\n";
            }
            return;
        }
    }

    cout << "Police officer not found.\n";
}

// ================= CASE MANAGEMENT =================

void Admin::manageCases()
{
    int choice = 0;

    do
    {
        cout << "\n========== CASE MANAGEMENT ==========\n";
        cout << "1. Add Case\n";
        cout << "2. View Cases\n";
        cout << "3. Search Case\n";
        cout << "4. Update Case Status\n";
        cout << "5. Delete Case\n";
        cout << "6. Back\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1: addCase(); break;
            case 2: viewCases(); break;
            case 3: searchCase(); break;
            case 4: updateCaseStatus(); break;
            case 5: deleteCase(); break;
            case 6: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}

void Admin::addCase()
{
    int id, officerId;
    string title, description;

    cout << "Enter Case ID: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid case ID.\n";
        return;
    }

    if (id <= 0)
    {
        cout << "Case ID must be positive.\n";
        return;
    }

    for (auto& c : cases)
    {
        if (c.getCaseId() == id)
        {
            cout << "Case ID already exists.\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Case Title: ";
    getline(cin, title);

    cout << "Enter Case Description: ";
    getline(cin, description);

    cout << "Enter Assigned Officer ID (0 for unassigned): ";
    if (!(cin >> officerId))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid officer ID.\n";
        return;
    }

    if (officerId != 0)
    {
        bool found = false;

        for (auto& officer : officers)
        {
            if (officer.getOfficerId() == officerId)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Officer ID not found. Register the officer first.\n";
            return;
        }
    }

    cases.emplace_back(id, title, description, officerId, "Open");

    if (saveCases(cases))
    {
        cout << "Case added successfully.\n";
    }
    else
    {
        cases.pop_back();
        cout << "Error saving case data.\n";
    }
}

void Admin::viewCases()
{
    if (cases.empty())
    {
        cout << "No cases found.\n";
        return;
    }

    for (auto& c : cases)
        c.displayCase();
}

void Admin::searchCase()
{
    int id;

    cout << "Enter Case ID to search: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid case ID.\n";
        return;
    }

    for (auto& c : cases)
    {
        if (c.getCaseId() == id)
        {
            c.displayCase();
            return;
        }
    }

    cout << "Case not found.\n";
}

void Admin::updateCaseStatus()
{
    int id;
    string status;

    cout << "Enter Case ID to update: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid case ID.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto& c : cases)
    {
        if (c.getCaseId() == id)
        {
            cout << "Enter new status (Open/Under Investigation/Closed): ";
            getline(cin, status);

            string oldStatus = c.getStatus();
            c.setStatus(status);

            if (saveCases(cases))
            {
                cout << "Case status updated successfully.\n";
            }
            else
            {
                c.setStatus(oldStatus);
                cout << "Could not save status update.\n";
            }
            return;
        }
    }

    cout << "Case not found.\n";
}

void Admin::deleteCase()
{
    int id;

    cout << "Enter Case ID to delete: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid case ID.\n";
        return;
    }

    for (auto it = cases.begin(); it != cases.end(); ++it)
    {
        if (it->getCaseId() == id)
        {
            Case deletedCase = *it;
            cases.erase(it);

            if (saveCases(cases))
            {
                cout << "Case deleted successfully.\n";
            }
            else
            {
                cases.push_back(deletedCase);
                cout << "Could not save changes; deletion cancelled.\n";
            }
            return;
        }
    }

    cout << "Case not found.\n";
}

// ================= REPORTS =================

void Admin::viewReports()
{
    cout << "\n========== CRIMENET REPORTS ==========\n";
    cout << "Total registered users: " << users.size() << '\n';
    cout << "Total registered police officers: " << officers.size() << '\n';
    cout << "Total cases: " << cases.size() << '\n';

    int openCases = 0;
    int closedCases = 0;
    int underInvestigation = 0;
    int unassignedCases = 0;

    for (auto& c : cases)
    {
        if (c.getStatus() == "Open")
            ++openCases;
        else if (c.getStatus() == "Closed")
            ++closedCases;
        else if (c.getStatus() == "Under Investigation")
            ++underInvestigation;

        if (c.getAssignedOfficerId() == 0)
            ++unassignedCases;
    }

    cout << "Open cases: " << openCases << '\n';
    cout << "Cases under investigation: " << underInvestigation << '\n';
    cout << "Closed cases: " << closedCases << '\n';
    cout << "Unassigned cases: " << unassignedCases << '\n';
}