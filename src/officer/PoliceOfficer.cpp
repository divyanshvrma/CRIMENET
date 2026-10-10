#include <iostream>
#include "PoliceOfficer.h"

using namespace std;

PoliceOfficer::PoliceOfficer()
{
    officerId = 0;
    name = "";
    rank = "";
    username = "";
    available = false;
}

PoliceOfficer::PoliceOfficer(int id, string officerName, string officerRank,
                             string officerUsername, bool officerAvailable)
{
    officerId = id;
    name = officerName;
    rank = officerRank;
    username = officerUsername;
    available = officerAvailable;
}

void PoliceOfficer::displayOfficer()
{
    cout << "Officer ID: " << officerId << endl;
    cout << "Name: " << name << endl;
    cout << "Rank: " << rank << endl;
    cout << "Username: " << username << endl;

    if (available)
    {
        cout << "Availability: Available" << endl;
    }
    else
    {
        cout << "Availability: Not Available" << endl;
    }
}

int PoliceOfficer::getOfficerId()
{
    return officerId;
}

string PoliceOfficer::getName()
{
    return name;
}

string PoliceOfficer::getRank()
{
    return rank;
}

string PoliceOfficer::getUsername()
{
    return username;
}

bool PoliceOfficer::isAvailable()
{
    return available;
}