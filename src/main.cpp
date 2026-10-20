#include <iostream>
#include <string>
#include <vector>
#include "admin/Admin.h"
#include "officer/PoliceOfficer.h"
#include "dispatcher/Dispatcher.h"

using namespace std;

int main()
{
    int choice;

    while (true)
    {
        cout << "\n========================================\n";
        cout << "              CRIMENET\n";
        cout << " Police Case and FIR Management System\n";
        cout << "========================================\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1)
        {
            string username, password;

            cout << "\n------------- LOGIN -------------\n";
            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            // Admin Login
            if (username == "admin" && password == "admin123")
            {
                cout << "\nLogin successful!\n";
                cout << "Role: Admin\n";

                Admin admin;
                admin.showDashboard();
            }

            // Dispatcher Login
            else if (username == "dispatcher" && password == "disp123")
            {
                cout << "\nLogin successful!\n";
                cout << "Role: Dispatcher\n";

                Dispatcher dispatcher;
                dispatcher.showDashboard();
            }

            // Police Officer Login
            else
            {
                vector<PoliceOfficer> officers;
                loadOfficers(officers);

                bool loggedIn = false;

                for (auto& officer : officers)
                {
                    if (officer.getUsername() == username &&
                        officer.getPassword() == password)
                    {
                        cout << "\nLogin successful!\n";
                        cout << "Role: Police Officer\n";

                        officer.showDashboard();
                        loggedIn = true;
                        break;
                    }
                }

                if (!loggedIn)
                {
                    cout << "\nInvalid username or password.\n";
                }
            }
        }
        else if (choice == 2)
        {
            cout << "\nExiting CRIMENET...\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}