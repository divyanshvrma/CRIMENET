
#ifndef CASE_H
#define CASE_H

#include <string>
using namespace std;

class Case
{
private:
    int caseId;
    string title;
    string description;
    int assignedOfficerId;
    string status;

public:
    Case();
    Case(int id, string caseTitle, string caseDescription,
         int officerId, string caseStatus);

    void displayCase();

    int getCaseId();
    string getTitle();
    string getDescription();
    int getAssignedOfficerId();
    string getStatus();

    void setStatus(string newStatus);
};

#endif
