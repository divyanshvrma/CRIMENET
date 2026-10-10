#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
private:
    int userId;
    string username;
    string password;
    string role;

public:
    User();
    User(int id, string uname, string pass, string userRole);

    void displayUser();

    int getUserId();
    string getUsername();
    string getRole();
};

#endif