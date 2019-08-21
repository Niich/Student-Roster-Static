#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <string>
#include <vector>
#include "student.h"
#include "degree.h"

using namespace std;

class NetworkStudent : public Student {
private:
   degree degreeProgram;

public:
   //getter fuctions
   int GetDegreeProgram();
   //setter fuctions
   void SetDegreeProgram();
   void Print();

   //constructors and destructors
   NetworkStudent();
   //probably need to remove this since i think they expect me to update each item seperatly in the Roster:: functions
   NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse3, int daysInCourse2, degree degreeProgram);
   ~NetworkStudent();

};

#endif