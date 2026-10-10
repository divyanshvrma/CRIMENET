#include <iostream>
#include "User.h"

using namespace std;

User::User()
{
    userId = 0;
    username = "";
    password = "";
    role = "";
}

User::User(int id, string uname, string pass, string userRole)
{
    userId = id;
    username = uname;
    password = pass;
    role = userRole;
}

void User::displayUser()
{
    cout << "User ID: " << userId << endl;
    cout << "Username: " << username << endl;
    cout << "Role: " << role << endl;
}

int User::getUserId()
{
    return userId;
}

string User::getUsername()
{
    return username;
}

string User::getRole()
{
    return role;
}