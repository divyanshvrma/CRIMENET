
#include <iostream>
#include <fstream>
#include <sstream>
#include "case.h"

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

bool loadCases(vector<Case>& cases)
{
    ifstream file("cases.txt");

    // No file means there are no complaints yet.
    if (!file.is_open())
        return true;

    cases.clear();

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string idText, title, description, officerText, status;

        if (!getline(ss, idText, '|') ||
            !getline(ss, title, '|') ||
            !getline(ss, description, '|') ||
            !getline(ss, officerText, '|') ||
            !getline(ss, status))
        {
            continue;
        }

        try
        {
            int id = stoi(idText);
            int officerId = stoi(officerText);

            cases.push_back(
                Case(id, title, description, officerId, status)
            );
        }
        catch (...)
        {
            // Ignore malformed records.
        }
    }

    file.close();
    return true;
}

bool saveCases(const vector<Case>& cases)
{
    ofstream file("cases.txt");

    if (!file.is_open())
    {
        cout << "Error: Could not save cases.txt\n";
        return false;
    }

    for (Case c : cases)
    {
        file << c.getCaseId() << '|'
             << c.getTitle() << '|'
             << c.getDescription() << '|'
             << c.getAssignedOfficerId() << '|'
             << c.getStatus() << '\n';
    }

    file.close();
    return true;
}

int generateNextCaseId(const vector<Case>& cases)
{
    int highestId = 1000;

    for (Case c : cases)
    {
        if (c.getCaseId() > highestId)
            highestId = c.getCaseId();
    }

    return highestId + 1;
}
