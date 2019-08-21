#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <string>
#include <vector>
#include "student.h"
#include "degree.h"

using namespace std;

class SecurityStudent : public Student {
private:
   degree degreeProgram;

public:
   //getter fuctions
   int GetDegreeProgram();
   //setter fuctions
   void SetDegreeProgram();
   void Print();

   //constructors and destructors
   SecurityStudent();
   //probably need to remove this since i think they expect me to update each item seperatly in the Roster:: functions
   SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse3, int daysInCourse2, degree degreeProgram);
   ~SecurityStudent();

};

#endif