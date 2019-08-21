#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "student.h"

using namespace std;

//getter functions
string Student::GetStudentID() {
   return studentID;
}

string Student::GetFirstName() {
   return firstName;
}

string Student::GetLastName() {
   return lastName;
}

string Student::GetEmailAddress() {
   return emailAddress;
}

int Student::GetAge() {
   return age;
}

int Student::GetCompletionDates(int courseNumer) {
   int courseDays = -1;
   courseDays = numDaysCompleteCourse.at(courseNumer - 1);
   return courseDays;
}

//int Student::GetDegreeProgram() {
// If I create this def even as an empty function I get an error: 
// error C4716:  'Student::GetDegreeProgram': must return a value.
// however if I delete, comment it out or make it return void it will work. 
// Since The directions require a virtual function but not a void i would rather 
// return int so i can use the result in other places vs just printing to screen.
//}

//setter functions
void Student::SetStudentID(string studentIdIn) {
   //cout << "setting studentID";
   studentID = studentIdIn;
}

void Student::SetFirstName(string firstNameIn) {
   firstName = firstNameIn;
}

void Student::SetLastName(string lastNameIn) {
   lastName = lastNameIn;
}

void Student::SetEmailAddress(string emailAddressIn) {
   emailAddress = emailAddressIn;
}

void Student::SetAge(int ageIn) {
   age = ageIn;
}

void Student::AddCourseCompletionDays(int completionDaysIn) {
   numDaysCompleteCourse.push_back(completionDaysIn);
}

void Student::SetDegreeProgram() {
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3, degree degreeProgram) {
   SetStudentID(studentID);
   SetFirstName(firstName);
   SetLastName(lastName);
   SetEmailAddress(emailAddress);
   SetAge(age);
   AddCourseCompletionDays(daysInCourse1);
   AddCourseCompletionDays(daysInCourse2);
   AddCourseCompletionDays(daysInCourse3);
}


Student::Student() {
}

Student::~Student() {
}
