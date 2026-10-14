
#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "../models/User.h"
#include "../models/Case.h"
#include "../officer/PoliceOfficer.h"

using namespace std;

class Admin
{
private:
    vector<User> users;
    vector<PoliceOfficer> officers;
    vector<Case> cases;

    void manageUsers();
    void addUser();
    void viewUsers();
    void searchUser();
    void deleteUser();

    void manageOfficers();
    void addOfficer();
    void viewOfficers();
    void searchOfficer();
    void deleteOfficer();

    void manageCases();
    void addCase();
    void viewCases();
    void searchCase();
    void updateCaseStatus();
    void deleteCase();

    void viewReports();

public:
    Admin();

    void dashboard();
    void showDashboard();
};

#endif
