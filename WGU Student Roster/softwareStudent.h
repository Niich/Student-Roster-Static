#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <string>
#include <vector>
#include "student.h"
#include "degree.h"

using namespace std;

class SoftwareStudent : public Student {
private:
   degree degreeProgram;

public:
   //getter fuctions
   int GetDegreeProgram();
   //setter fuctions
   void SetDegreeProgram();
   void Print();

   //constructors and destructors
   SoftwareStudent();
   //probably need to remove this since i think they expect me to update each item seperatly in the Roster:: functions
   SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse3, int daysInCourse2, degree degreeProgram);
   ~SoftwareStudent();

};

#endif