
#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
#include <vector>

using namespace std;

class PoliceOfficer
{
private:
    int officerId;
    string name;
    string rank;
    string username;
    string password;
    bool available;

public:
    PoliceOfficer();

    PoliceOfficer(int id, string officerName, string officerRank,
                  string officerUsername, bool officerAvailable);

    PoliceOfficer(int id, string officerName, string officerRank,
                  string officerUsername, string officerPassword,
                  bool officerAvailable);

    void displayOfficer();

    int getOfficerId();
    string getName();
    string getRank();
    string getUsername();
    string getPassword();

    bool isAvailable();
    void setAvailability(bool value);

    void showDashboard();
};

bool loadOfficers(vector<PoliceOfficer>& officers);
bool saveOfficers(const vector<PoliceOfficer>& officers);

#endif
