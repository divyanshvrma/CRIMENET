
#include <iostream>
#include "User.h"
using namespace std;

User::User()
{
    userId = 0;
    name = "";
    username = "";
    password = "";
    role = "";
}

User::User(int id, string userName, string loginName,
           string loginPassword, string userRole)
{
    userId = id;
    name = userName;
    username = loginName;
    password = loginPassword;
    role = userRole;
}

void User::displayUser()
{
    cout << "\nUser ID: " << userId
         << "\nName: " << name
         << "\nUsername: " << username
         << "\nRole: " << role << endl;
}

int User::getUserId() { return userId; }
string User::getName() { return name; }
string User::getUsername() { return username; }
string User::getPassword() { return password; }
string User::getRole() { return role; }
