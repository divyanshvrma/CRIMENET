#include <iostream>
#include <string>
#include "Admin.h"

using namespace std;

void Admin::showDashboard()
{
    int choice;

    while (true)
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "          ADMIN DASHBOARD" << endl;
        cout << "========================================" << endl;
        cout << "1. Manage Users" << endl;
        cout << "2. Manage Police Officers" << endl;
        cout << "3. Manage Cases" << endl;
        cout << "4. View Reports" << endl;
        cout << "5. Logout" << endl;
        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                manageUsers();
                break;

            case 2:
                manageOfficers();
                break;

            case 3:
                cout << "Manage Cases selected." << endl;
                break;

            case 4:
                cout << "View Reports selected." << endl;
                break;

            case 5:
                cout << "Logging out..." << endl;
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Admin::addUser()
{
    int userId;
    string username;
    string role;
    string password;

    cout << endl;
    cout << "========== ADD USER ==========" << endl;

    cout << "Enter User ID: ";
    cin >> userId;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter Role: ";
    cin >> role;

    User newUser(userId, username, password, role);

    users.push_back(newUser);

    cout << endl;
    cout << "User added successfully!" << endl;
}

void Admin::viewUsers()
{
    cout << endl;
    cout << "========== VIEW USERS ==========" << endl;

    if (users.empty())
    {
        cout << "No users found." << endl;
        return;
    }

    for (int i = 0; i < users.size(); i++)
    {
        cout << endl;
        users[i].displayUser();
    }
}

void Admin::manageUsers()
{
    int choice;

    do
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "            USER MANAGEMENT" << endl;
        cout << "========================================" << endl;

        cout << "1. Add User" << endl;
        cout << "2. View Users" << endl;
        cout << "3. Search User" << endl;
        cout << "4. Delete User" << endl;
        cout << "5. Back" << endl;

        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addUser();
                break;

            case 2:
                viewUsers();
                break;

            case 3:
            {
                int userId;
                bool found = false;

                cout << endl;
                cout << "========== SEARCH USER ==========" << endl;
                cout << "Enter User ID: ";
                cin >> userId;

                for (int i = 0; i < users.size(); i++)
                {
                    if (users[i].getUserId() == userId)
                    {
                        cout << endl;
                        cout << "User found!" << endl;
                        cout << endl;

                        users[i].displayUser();

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << endl;
                    cout << "User not found." << endl;
                }

                break;
            }

            case 4:
            {
                int userId;
                bool found = false;

                cout << endl;
                cout << "========== DELETE USER ==========" << endl;
                cout << "Enter User ID: ";
                cin >> userId;

                for (int i = 0; i < users.size(); i++)
                {
                    if (users[i].getUserId() == userId)
                    {
                        users.erase(users.begin() + i);

                        cout << endl;
                        cout << "User deleted successfully!" << endl;

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << endl;
                    cout << "User not found." << endl;
                }

                break;
            }

            case 5:
                cout << "Returning to Admin Dashboard..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 5);
}

void Admin::manageOfficers()
{
    int choice;

    do
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "       POLICE OFFICER MANAGEMENT" << endl;
        cout << "========================================" << endl;

        cout << "1. Add Police Officer" << endl;
        cout << "2. View Police Officers" << endl;
        cout << "3. Search Police Officer" << endl;
        cout << "4. Delete Police Officer" << endl;
        cout << "5. Back" << endl;

        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addOfficer();
                break;

            case 2:
                viewOfficers();
                break;

            case 3:
            {
                int officerId;
                bool found = false;

                cout << endl;
                cout << "========== SEARCH POLICE OFFICER ==========" << endl;
                cout << "Enter Officer ID: ";
                cin >> officerId;

                for (int i = 0; i < officers.size(); i++)
                {
                    if (officers[i].getOfficerId() == officerId)
                    {
                        cout << endl;
                        cout << "Officer found!" << endl;
                        cout << endl;

                        officers[i].displayOfficer();

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << endl;
                    cout << "Officer not found." << endl;
                }

                break;
            }

            case 4:
                cout << "Delete Police Officer selected." << endl;
                break;

            case 5:
                cout << "Returning to Admin Dashboard..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 5);
}

void Admin::addOfficer()
{
    int officerId;
    string name;
    string rank;
    string username;
    int availabilityChoice;

    cout << endl;
    cout << "========== ADD POLICE OFFICER ==========" << endl;

    cout << "Enter Officer ID: ";
    cin >> officerId;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Rank: ";
    cin >> rank;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Is the officer available? (1 = Yes, 0 = No): ";
    cin >> availabilityChoice;

    bool available = (availabilityChoice == 1);

    PoliceOfficer newOfficer(
        officerId,
        name,
        rank,
        username,
        available
    );

    officers.push_back(newOfficer);

    cout << endl;
    cout << "Police officer added successfully!" << endl;
}

void Admin::viewOfficers()
{
    cout << endl;
    cout << "========== VIEW POLICE OFFICERS ==========" << endl;

    if (officers.empty())
    {
        cout << "No police officers found." << endl;
        return;
    }

    for (int i = 0; i < officers.size(); i++)
    {
        cout << endl;
        officers[i].displayOfficer();
    }
}