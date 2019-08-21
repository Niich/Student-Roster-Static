#include <iomanip>
#include <iostream>

#include "securityStudent.h"
#include "student.h"

int SecurityStudent::GetDegreeProgram() {
   //cout << degreeProgram << endl;
   return degreeProgram;
}

void SecurityStudent::SetDegreeProgram() {
   degreeProgram = SECURITY;
}

void SecurityStudent::Print() {

   cout << setfill(' ') << left;
   // cout << classRosterArray[i]->GetStudentID() << "\t";
   cout << "First Name: " << GetFirstName() << "\t";
   cout << "Last Name: " << GetLastName() << "\t";
   // cout << classRosterArray[i]->GetEmailAddress() << "\t";
   cout << setfill('0') << right;
   cout << "Age: " << GetAge() << "\t";
   cout << "daysInCourse: ";
   cout << setw(2) << GetCompletionDates(1) << ", ";
   cout << setw(2) << GetCompletionDates(2) << ", ";
   cout << setw(2) << GetCompletionDates(3) << "\t";
   cout << "Degree Program: Security" << endl;
}

SecurityStudent::SecurityStudent() {
   SetDegreeProgram();
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress,
                                 int age, int daysInCourse1, int daysInCourse3, int daysInCourse2,
                                 degree degreeProgram)
   :Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse3, daysInCourse2,
            degreeProgram) {
   SetDegreeProgram();
}

SecurityStudent::~SecurityStudent() {

}