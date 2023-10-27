#ifndef student_h
#define student_h

#include <iostream>
#include <array>
#include "degree.h"

using namespace std;

class Student
{
public:
    static const int num = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysTillComplete[num];
    DegreeProgram degree;

public:
    Student(); // default constructor
    // constructor defined
    Student(string studentID, string firstName, string lastName, string email, int age, int daysTillComplete[3], DegreeProgram degree);

    // Getters
    string getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int *getDaysTilComplete();
    DegreeProgram getDegree();

    // setter
    void setID(string id);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysTilComplete(int *daysTilComplete);
    void setDegree(DegreeProgram degree);

    void print();
};

#endif