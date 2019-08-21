#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include "student.h"
#include "degree.h"

class Roster {
private:
   Student* classRosterArray[5] = {nullptr};
   int FindEmptyArrayItem();
public:
   void Add(Student* studentObj, int arrLocation);
   void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
            int daysInCourse2, int daysInCourse3, degree degreeProgram);
   void Remove(string studentID);
   void PrintAll();
   void PrintByDegreeProgram(int degreeProgram);
   void PrintDaysInCourse(string studentID);
   void PrintInvalidEmails();

   ~Roster();
};

#endif