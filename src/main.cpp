#include <iostream>
#include <string>
#include "admin/Admin.h"
using namespace std;

int main()
{
    int choice;

    cout << "========================================" << endl;
    cout << "              CRIMENET" << endl;
    cout << " Police Case and FIR Management System" << endl;
    cout << "========================================" << endl;

    cout << endl;
    cout << "1. Login" << endl;
    cout << "2. Exit" << endl;

    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string username;
        string password;

        cout << endl;
        cout << "------------- LOGIN -------------" << endl;

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

       if (username == "admin" && password == "admin123")
{
    cout << endl;
    cout << "Login successful!" << endl;
    cout << "Role: Admin" << endl;

    Admin admin;
    admin.showDashboard();
}
        else if (username == "dispatcher" && password == "disp123")
        {
            cout << endl;
            cout << "Login successful!" << endl;
            cout << "Role: Dispatcher" << endl;
        }
        else if (username == "officer" && password == "off123")
        {
            cout << endl;
            cout << "Login successful!" << endl;
            cout << "Role: Police Officer" << endl;
        }
        else
        {
            cout << endl;
            cout << "Invalid username or password." << endl;
        }
    }
    else if (choice == 2)
    {
        cout << endl;
        cout << "Exiting CRIMENET..." << endl;
    }
    else
    {
        cout << endl;
        cout << "Invalid choice." << endl;
    }

    return 0;
}