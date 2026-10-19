
#ifndef CASE_H
#define CASE_H

#include <string>
#include <vector>
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

// Persistent case storage
bool loadCases(vector<Case>& cases);
bool saveCases(const vector<Case>& cases);
int generateNextCaseId(const vector<Case>& cases);

#endif
