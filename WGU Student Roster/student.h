#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "degree.h"

using namespace std;



class Student {
private:
   string studentID;
   string firstName;
   string lastName;
   string emailAddress;
   int age = 0;
   vector<int> numDaysCompleteCourse;
   degree degreeProgram = NONE;
public:
   //getter functions
   string GetStudentID();
   string GetFirstName();
   string GetLastName();
   string GetEmailAddress();
   int GetAge();
   int GetCompletionDates(int courseNumber);

   //setter functions
   void SetStudentID(string studentIdIn);
   void SetFirstName(string firstNameIn);
   void SetLastName(string lastNameIn);
   void SetEmailAddress(string emailAddressIn);
   void SetAge(int ageIn);
   void AddCourseCompletionDays(int completionDaysIn);
   void SetDegreeProgram();


   //virtual functions
   virtual void Print() = 0;
   virtual int GetDegreeProgram() = 0;

   //constructors and destructors
   Student();
   Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse3, int daysInCourse2, degree degreeProgram);
   ~Student();
};

#endif