#include <iomanip>
#include <iostream>

#include "softwareStudent.h"
#include "student.h"

int SoftwareStudent::GetDegreeProgram() {
   //cout << degreeProgram << endl;
   return degreeProgram;
}

void SoftwareStudent::SetDegreeProgram() {
   degreeProgram = SOFTWARE;
}

void SoftwareStudent::Print() {

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
   cout << "Degree Program: Software" << endl;
}

SoftwareStudent::SoftwareStudent() {
   SetDegreeProgram();
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse3, int daysInCourse2, degree degreeProgram)
   : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse3, daysInCourse2, degreeProgram) {
   SetDegreeProgram();
}

SoftwareStudent::~SoftwareStudent() {

}