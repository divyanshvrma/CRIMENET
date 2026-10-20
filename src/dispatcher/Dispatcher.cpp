
#include <iostream>
#include "Dispatcher.h"

using namespace std;

void Dispatcher::showDashboard()
{
    int choice = 0;

    do
    {
        cout << "\n========== DISPATCHER DASHBOARD ==========\n";
        cout << "1. View Cases (coming soon)\n";
        cout << "2. Register New Case (coming soon)\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                cout << "Case viewing will be connected in the next step.\n";
                break;

            case 2:
                cout << "Case registration will be connected in the next step.\n";
                break;

            case 3:
                cout << "Logging out from Dispatcher account...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);
}
