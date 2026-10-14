
#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
using namespace std;

class PoliceOfficer
{
private:
    int officerId;
    string name;
    string rank;
    string username;
    bool available;

public:
    PoliceOfficer();

    PoliceOfficer(int id, string officerName, string officerRank,
                  string officerUsername, bool officerAvailable);

    void displayOfficer();

    int getOfficerId();
    string getName();
    string getRank();
    string getUsername();
    bool isAvailable();

    void setAvailability(bool value);
};

#endif
