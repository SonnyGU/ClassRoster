#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

using namespace std;

Roster::Roster()
{
    this->lastIndex = -1;
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int days[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    this->classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);
}

void Roster::remove(string studentID)
{
    cout << endl
         << "Attempting to remove student ID : " << studentID << endl;
    bool ifFound = false;
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (this->classRosterArray[i]->getID() == studentID)
        {
            delete this->classRosterArray[i];
            for (int k = i; k < lastIndex; ++k)
            {
                this->classRosterArray[k] = this->classRosterArray[k + 1];
            }
            lastIndex--;
            ifFound = true;
            cout << endl
                 << "Removed: " << studentID << endl;
            break;
        }
    }

    if (!ifFound)
    {
        cout << endl

             << "The student with the ID: " << studentID << " was not found." << endl
             << endl
             << "Finished";
    }
}

void Roster::printAll()
{
    cout << endl
         << "Displaying all students: " << endl;
    for (int i = 0; i <= lastIndex; i++)
    {
        Roster::classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= this->lastIndex; i++)
    {
        if (this->classRosterArray[i]->getID() == studentID)
        {
            cout << endl
                 << "Student ID: " << studentID << ", "
                 << "average days in course is: " << (this->classRosterArray[i]->getDaysTilComplete()[0] + this->classRosterArray[i]->getDaysTilComplete()[1] + this->classRosterArray[i]->getDaysTilComplete()[2]) / 3 << endl;
        }
    }
}
void Roster::printInvalidEmails()
{
    cout << endl
         << "Displaying invalid emails: " << endl;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i]->getEmail().find(' ') != string::npos || classRosterArray[i]->getEmail().find('@') == string::npos || classRosterArray[i]->getEmail().find('.') == string::npos)
        {
            cout << endl
                 << classRosterArray[i]->getEmail() << " - is invalid." << endl;
        }
    }
}

void Roster::parse(string line)
{
    stringstream ss(line);
    string holder;

    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysTilComplete[3];
    DegreeProgram degree;

    int i = 0;
    while (getline(ss, holder, ','))
    {
        switch (i)
        {
        case 0:
            studentID = holder;
            break;
        case 1:
            firstName = holder;
            break;
        case 2:
            lastName = holder;
            break;
        case 3:
            email = holder;
            break;
        case 4:
            age = stoi(holder);
            break;
        case 5:
            daysTilComplete[0] = stoi(holder);
            break;
        case 6:
            daysTilComplete[1] = stoi(holder);
            break;
        case 7:
            daysTilComplete[2] = stoi(holder);
            break;
        case 8:
            if (holder == "SECURITY")
            {
                degree = SECURITY;
            }
            else if (holder == "NETWORK")
            {
                degree = NETWORK;
            }
            else
            {
                degree = SOFTWARE;
            }
            break;
        }
        i++;
    }
    add(studentID, firstName, lastName, email, age, daysTilComplete[0], daysTilComplete[1], daysTilComplete[2], degree);
}

void Roster::printByDegreeProgram(DegreeProgram degree)
{
    cout << endl
         << "Showing students in degree program: " << degreeProgramStrings[degree] << endl;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getDegree() == degree)
        {
            this->classRosterArray[i]->print();
        }
    }
}

int Roster::getLastIndex()
{
    return lastIndex;
}

Student *Roster::getStudent(int index)
{
    if (index >= 0 && index <= lastIndex)
    {
        return classRosterArray[index];
    }
    else
    {
        return nullptr;
    }
}

Roster::~Roster()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
