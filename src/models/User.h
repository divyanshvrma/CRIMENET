
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    int userId;
    string name;
    string username;
    string password;
    string role;

public:
    User();
    User(int id, string userName, string loginName,
         string loginPassword, string userRole);

    void displayUser();

    int getUserId();
    string getName();
    string getUsername();
    string getPassword();
    string getRole();
};

#endif
