#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "../models/User.h"
#include "../officer/PoliceOfficer.h"

class Admin
{
private:
    std::vector<User> users;
    std::vector<PoliceOfficer> officers;

public:
    void showDashboard();

    void manageUsers();
    void addUser();
    void viewUsers();

    void manageOfficers();
    void addOfficer();
    void viewOfficers();
};

#endif