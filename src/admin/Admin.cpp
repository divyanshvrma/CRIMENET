

#include <iostream>

#include <limits>

#include <string>

#include "Admin.h"



using namespace std;



Admin::Admin() {}



// ================= ADMIN DASHBOARD =================



void Admin::dashboard()

{

    int choice;



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



// ================= USER MANAGEMENT =================



void Admin::manageUsers()

{

    int choice;



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

    cin >> id;



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

    cin >> id;



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

    cin >> id;



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



// ================= OFFICER MANAGEMENT =================



void Admin::manageOfficers()

{

    int choice;



    do

    {

        cout << "\n========== POLICE OFFICER MANAGEMENT ==========\n";

        cout << "1. Add Police Officer\n";

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

    string name, rank, username;

    char availability;



    cout << "Enter Officer ID: ";

    cin >> id;



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



    cout << "Available? (y/n): ";

    cin >> availability;



    bool available = (availability == 'y' || availability == 'Y');



    officers.emplace_back(id, name, rank, username, available);

    cout << "Police officer added successfully.\n";

}



void Admin::viewOfficers()

{

    if (officers.empty())

    {

        cout << "No police officers found.\n";

        return;

    }



    for (auto& officer : officers)

        officer.displayOfficer();

}



void Admin::searchOfficer()

{

    int id;

    cout << "Enter Officer ID to search: ";

    cin >> id;



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

    cin >> id;



    for (auto it = officers.begin(); it != officers.end(); ++it)

    {

        if (it->getOfficerId() == id)

        {

            officers.erase(it);

            cout << "Police officer deleted successfully.\n";

            return;

        }

    }



    cout << "Police officer not found.\n";

}



// ================= CASE MANAGEMENT =================



void Admin::manageCases()

{

    int choice;



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

    string title, description, status;



    cout << "Enter Case ID: ";

    cin >> id;



    for (auto& c : cases)

    {

        if (c.getCaseId() == id)

        {

            cout << "Case ID already exists.\n";

            return;

        }

    }



    cout << "Enter Assigned Officer ID (0 for unassigned): ";

    cin >> officerId;



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

            cout << "Officer ID not found. Case not added.\n";

            return;

        }

    }



    cin.ignore(numeric_limits<streamsize>::max(), '\n');



    cout << "Enter Case Title: ";

    getline(cin, title);



    cout << "Enter Case Description: ";

    getline(cin, description);



    status = "Open";



    cases.emplace_back(id, title, description, officerId, status);

    cout << "Case added successfully.\n";

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

    cin >> id;



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



    cout << "Enter Case ID: ";

    cin >> id;



    for (auto& c : cases)

    {

        if (c.getCaseId() == id)

        {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');



            cout << "Enter new status (Open/Under Investigation/Closed): ";

            getline(cin, status);



            c.setStatus(status);

            cout << "Case status updated.\n";

            return;

        }

    }



    cout << "Case not found.\n";

}



void Admin::deleteCase()

{

    int id;

    cout << "Enter Case ID to delete: ";

    cin >> id;



    for (auto it = cases.begin(); it != cases.end(); ++it)

    {

        if (it->getCaseId() == id)

        {

            cases.erase(it);

            cout << "Case deleted successfully.\n";

            return;

        }

    }



    cout << "Case not found.\n";

}



// ================= REPORTS =================



void Admin::viewReports()

{

    int choice;



    do

    {

        cout << "\n========== CRIMENET REPORTS ==========\n";

        cout << "1. User Report\n";

        cout << "2. Police Officer Report\n";

        cout << "3. Case Statistics\n";

        cout << "4. Officer-wise Case Report\n";

        cout << "5. Overall System Summary\n";

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

            case 1:

                cout << "\nTotal Users: " << users.size() << endl;

                viewUsers();

                break;



            case 2:

                cout << "\nTotal Police Officers: "

                     << officers.size() << endl;

                viewOfficers();



                {

                    int availableCount = 0;



                    for (auto& officer : officers)

                    {

                        if (officer.isAvailable())

                            availableCount++;

                    }



                    cout << "Available Officers: "

                         << availableCount << endl;

                    cout << "Unavailable Officers: "

                         << officers.size() - availableCount << endl;

                }

                break;



            case 3:

                {

                    int openCount = 0;

                    int closedCount = 0;

                    int otherCount = 0;



                    for (auto& c : cases)

                    {

                        if (c.getStatus() == "Open")

                            openCount++;

                        else if (c.getStatus() == "Closed")

                            closedCount++;

                        else

                            otherCount++;

                    }



                    cout << "\nTotal Cases: " << cases.size()

                         << "\nOpen Cases: " << openCount

                         << "\nClosed Cases: " << closedCount

                         << "\nOther Status Cases: " << otherCount

                         << endl;

                }

                break;



            case 4:

                if (officers.empty())

                {

                    cout << "No officers registered.\n";

                    break;

                }



                for (auto& officer : officers)

                {

                    int assigned = 0;



                    cout << "\nOfficer ID: " << officer.getOfficerId()

                         << " | Name: " << officer.getName() << endl;



                    for (auto& c : cases)

                    {

                        if (c.getAssignedOfficerId() ==

                            officer.getOfficerId())

                        {

                            assigned++;

                            cout << "  Case ID: " << c.getCaseId()

                                 << " | Title: " << c.getTitle()

                                 << " | Status: " << c.getStatus()

                                 << endl;

                        }

                    }



                    cout << "Total Assigned Cases: " << assigned << endl;

                }

                break;



            case 5:

                cout << "\n========== SYSTEM SUMMARY ==========\n";

                cout << "Total Users: " << users.size() << endl;

                cout << "Total Police Officers: "

                     << officers.size() << endl;

                cout << "Total Cases: " << cases.size() << endl;

                break;



            case 6:

                break;



            default:

                cout << "Invalid choice.\n";

        }

    } while (choice != 6);

}


// Compatibility wrapper: main.cpp calls showDashboard(), while the
// existing admin menu implementation is named dashboard().
void Admin::showDashboard()
{
    dashboard();
}
