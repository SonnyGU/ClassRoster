#include <iostream>
#include <string>
#include <array>
#include <string>
#include "student.h"

using namespace std;

// default constructor
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    this->daysTillComplete[0] = 0;
    this->daysTillComplete[1] = 0;
    this->daysTillComplete[2] = 0;
    this->degree = SOFTWARE;
}

// constructor with parameters
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysTillComplete[], DegreeProgram degree)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    std::copy(daysTillComplete, daysTillComplete + 3, this->daysTillComplete);
    this->degree = degree;
}

// getters
string Student::getID() const
{
    return this->studentID;
}

string Student::getFirstName() const
{
    return this->firstName;
}

string Student::getLastName() const
{
    return this->lastName;
}

string Student::getEmail() const
{
    return this->email;
}

int Student::getAge() const
{
    return this->age;
}

int *Student::getDaysTilComplete()
{
    return this->daysTillComplete;
}
DegreeProgram Student::getDegree()
{
    return this->degree;
}

// Setters
void Student::setID(string id)
{
    this->studentID = id;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmail(string email)
{
    this->email = email;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysTilComplete(int *daysTilComplete)
{
    for (int i = 0; i < num; i++)
    {
        this->daysTillComplete[i] = daysTillComplete[i];
    }
}

void Student::setDegree(DegreeProgram degree)
{
    this->degree = degree;
}

void Student::print()
{
    cout << endl
         << this->getID() << '\t'
         << "First Name: " << this->getFirstName() << '\t'
         << "Last Name: " << this->getLastName() << '\t'
         << "Age: " << this->getAge() << '\t'
         << "Days in course: {"
         << this->getDaysTilComplete()[0] << ","
         << this->getDaysTilComplete()[1] << ","
         << this->getDaysTilComplete()[2] << "}\t"
         << "Degree Program: " << degreeProgramStrings[getDegree()]
         << endl;
}
