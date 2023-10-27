#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

int main()
{
    const string studentData[] =
        {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Guson,Ulysse,GUlysse@wgu.edu,32,10,10,10,SOFTWARE"};

    string courseTitle = "Scripting and Programming - Applications";
    string programLanguage = "C++";
    string studentID = "010821257";
    string name = "Guson Ulysse";

    cout << "Course Title: " << courseTitle << endl
         << "Programming Language: " << programLanguage << endl
         << "Student ID: " << studentID << endl
         << "Student Name: " << name << endl;

    Roster classRoster;

    for (int i = 0; i < 5; i++)
    {
        classRoster.parse(studentData[i]);
    }

    classRoster.printAll();

    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getID());
    }

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();

    classRoster.remove("A3");

    return 0;
}