
#include <iostream>
#include "PoliceOfficer.h"
using namespace std;

PoliceOfficer::PoliceOfficer()
{
    officerId = 0;
    name = "";
    rank = "";
    username = "";
    available = true;
}

PoliceOfficer::PoliceOfficer(int id, string officerName,
                             string officerRank,
                             string officerUsername,
                             bool officerAvailable)
{
    officerId = id;
    name = officerName;
    rank = officerRank;
    username = officerUsername;
    available = officerAvailable;
}

void PoliceOfficer::displayOfficer()
{
    cout << "\nOfficer ID: " << officerId
         << "\nName: " << name
         << "\nRank: " << rank
         << "\nUsername: " << username
         << "\nAvailability: "
         << (available ? "Available" : "Unavailable")
         << endl;
}

int PoliceOfficer::getOfficerId() { return officerId; }
string PoliceOfficer::getName() { return name; }
string PoliceOfficer::getRank() { return rank; }
string PoliceOfficer::getUsername() { return username; }
bool PoliceOfficer::isAvailable() { return available; }

void PoliceOfficer::setAvailability(bool value)
{
    available = value;
}
