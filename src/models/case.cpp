
#include <iostream>
#include "Case.h"
using namespace std;

Case::Case()
{
    caseId = 0;
    title = "";
    description = "";
    assignedOfficerId = 0;
    status = "Open";
}

Case::Case(int id, string caseTitle, string caseDescription,
           int officerId, string caseStatus)
{
    caseId = id;
    title = caseTitle;
    description = caseDescription;
    assignedOfficerId = officerId;
    status = caseStatus;
}

void Case::displayCase()
{
    cout << "\nCase ID: " << caseId
         << "\nTitle: " << title
         << "\nDescription: " << description
         << "\nAssigned Officer ID: " << assignedOfficerId
         << "\nStatus: " << status << endl;
}

int Case::getCaseId() { return caseId; }
string Case::getTitle() { return title; }
string Case::getDescription() { return description; }
int Case::getAssignedOfficerId() { return assignedOfficerId; }
string Case::getStatus() { return status; }

void Case::setStatus(string newStatus)
{
    status = newStatus;
}
