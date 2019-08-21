#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "degree.h"
#include "networkStudent.h"
#include "roster.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"


using namespace std;

const string studentData[] = {
 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Nicholas,Boone,nboone8@WGU.edu,30,2,11,2,SOFTWARE"
};

int main() {

   // Print my info
   cout << "Course: Scripting and Programming - Applications – C867" << endl;
   cout << "Language used: C++" << endl;
   cout << "Student ID: 001218448" << endl;
   cout << "Name: Nicholas Boone" << endl << endl;;

   Roster liveClassRoster;
   int lengthOfArray = (sizeof(studentData) / sizeof(*studentData));
   int loopCount = 0;

   while (loopCount < lengthOfArray) {// Loop throught each string and create a specialStudent object and add it to the roster array

      // create vars to hold the info we get from the string.
      // we need to do this because we cant create the student item till we know what degree program they are in.
      string tmpStudentID, tmpFirstName, tmpLastName, tmpEmailAddress;
      int tmpAge = 0;
      vector<int> numDaysCompleteCourse;
      degree tmpDegree = SOFTWARE;
      istringstream inSS;
      string itemHolder;
      int postition = 0;

      inSS.str(studentData[loopCount]); // breakdown the string into each item we want to record on the student object
      while (getline(inSS, itemHolder, ',')) {

         switch (postition) {
         case 0:// item 0 is studentID                    
            tmpStudentID = itemHolder;
            postition++;
            break;
         case 1:// item 1 is First Name                    
            tmpFirstName = itemHolder;
            postition++;
            break;
         case 2:// item 2 is Last Name                    
            tmpLastName = itemHolder;
            postition++;
            break;
         case 3:// item 3 is Email                    
            tmpEmailAddress = itemHolder;
            postition++;
            break;
         case 4:// item 4 is Age                    
            tmpAge = stoi(itemHolder, nullptr, 10);
            postition++;
            break;
         case 5:// item 5,6,7 all add course durations
         case 6:
         case 7:
            numDaysCompleteCourse.push_back(stoi(itemHolder, nullptr, 10));
            postition++;
            break;
         case 8:// item 8 is the degree program
            // this is the easyest way i could think of to convert the "str" to "degree".
            if (itemHolder == "SECURITY") {
               tmpDegree = degree::SECURITY;
            }
            else if (itemHolder == "NETWORK") {
               tmpDegree = degree::NETWORKING;
            }
            else if (itemHolder == "SOFTWARE") {
               tmpDegree = degree::SOFTWARE;
            }
            break;
         default:
            break;
         }
      }
      //Add each student to the array
      liveClassRoster.Add(tmpStudentID, tmpFirstName, tmpLastName, tmpEmailAddress, tmpAge, numDaysCompleteCourse.at(0), numDaysCompleteCourse.at(1), numDaysCompleteCourse.at(2), tmpDegree);
      loopCount++;
   }

   // print all the info required for class

   liveClassRoster.PrintAll();

   liveClassRoster.PrintInvalidEmails();

   cout << endl << "Students average days in class:" << endl;
   for (int i = 1; i < 6; i++) {
      string studentID = "A" + to_string(i);
      liveClassRoster.PrintDaysInCourse(studentID);
   }

   liveClassRoster.PrintByDegreeProgram(SOFTWARE);

   cout << endl << "Remove student from array:" << endl;
   liveClassRoster.Remove("A2");
   liveClassRoster.Remove("A2");

   string userIn = "";
   while (userIn != "exit" && userIn != "Exit" && userIn != "EXIT") {
      cout << "\rType Exit and press enter when done: ";
      cin >> userIn;
   }
   return 0;
};

//************************
//Roster class definitions
//************************

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree degreeProgram) {

   int arrayLocation = FindEmptyArrayItem();

   switch (degreeProgram) {
   case 0:
      //SoftwareStudent
      classRosterArray[arrayLocation] = new SoftwareStudent;
      classRosterArray[arrayLocation]->SetStudentID(studentID);
      classRosterArray[arrayLocation]->SetFirstName(firstName);
      classRosterArray[arrayLocation]->SetLastName(lastName);
      classRosterArray[arrayLocation]->SetEmailAddress(emailAddress);
      classRosterArray[arrayLocation]->SetAge(age);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse1);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse2);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse3);
      classRosterArray[arrayLocation]->SetDegreeProgram();
      //Student(studentID, firstName, firstName, firstName, age, daysInCourse1, daysInCourse3, daysInCourse3, degreeProgram);
      break;
   case 1:
      //SecurityStudent
      classRosterArray[arrayLocation] = new SecurityStudent;
      classRosterArray[arrayLocation]->SetStudentID(studentID);
      classRosterArray[arrayLocation]->SetFirstName(firstName);
      classRosterArray[arrayLocation]->SetLastName(lastName);
      classRosterArray[arrayLocation]->SetEmailAddress(emailAddress);
      classRosterArray[arrayLocation]->SetAge(age);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse1);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse2);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse3);
      classRosterArray[arrayLocation]->SetDegreeProgram();
      break;
   case 2:
      //NetworkStudent
      classRosterArray[arrayLocation] = new NetworkStudent;
      classRosterArray[arrayLocation]->SetStudentID(studentID);
      classRosterArray[arrayLocation]->SetFirstName(firstName);
      classRosterArray[arrayLocation]->SetLastName(lastName);
      classRosterArray[arrayLocation]->SetEmailAddress(emailAddress);
      classRosterArray[arrayLocation]->SetAge(age);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse1);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse2);
      classRosterArray[arrayLocation]->AddCourseCompletionDays(daysInCourse3);
      classRosterArray[arrayLocation]->SetDegreeProgram();
      break;
   default:
      cout << "not a valid degree program" << endl;
      break;
   }
   //SoftwareStudent firstStudent(studentID,firstName,firstName,firstName,age,daysInCourse1,daysInCourse3,daysInCourse3,degreeProgram);

}

void Roster::Remove(string studentID) {

   int i = 0;
   bool removeResult = false;
   while (i < 5) {
      if (classRosterArray[i] != nullptr) { // check to see if there is an object in that slot of the array.
          //loop through all students looking for an ID match
         if (classRosterArray[i]->GetStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            removeResult = true;
         }
      }
      i++;
   }
   if (removeResult == true) {
      cout << "Account \"" << studentID << "\" successfully removed" << endl;
   }
   else {
      cout << "Account \"" << studentID << "\" could not be found" << endl;
   }



}

void Roster::PrintAll() {
   cout << "All student info:" << endl;
   for (int i = 0; i < 5; i++) { // loop through the array of 5 items, dereferance the pointer and call the get funcions for all the information
      cout << i + 1 << "\t";
      classRosterArray[i]->Print();
   }
}

void Roster::PrintByDegreeProgram(int degreeProgram) {
   int i = 0;
   bool foundResult = false;
   cout << endl << "Degree program search results:" << endl;
   while (i < 5) {
      if (classRosterArray[i] != nullptr) { // check to see if there is an object in that slot of the array.
          //loop through all students looking for an ID match
         if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
            foundResult = true;
         }
      }
      i++;
   }
   if (foundResult == false) {
      cout << "No students could be found for this degree program" << endl;
   }

}

void Roster::PrintDaysInCourse(string studentID) {
   //FIXME: add other student info to this so its easyer to see what student has what average. and formating
   int i = 0;
   double totDays = 0.0;
   while (classRosterArray[i]->GetStudentID() != studentID) { //loop through all students looking for an ID match
      i++; // we are only counting in this loop so we can use the number later
   }

   for (int a = 1; a <= 3; a++) { // loop through all 3 class day counts
      totDays = totDays + classRosterArray[i]->GetCompletionDates(a); //add all the days to total days
   }
   cout << "Average days per class for " << studentID << ":\t" << totDays / 3.0 << endl; //devide total by 3 since that is the number of classes
}

void Roster::PrintInvalidEmails() {
   cout << endl << "Invalid emails:" << endl;
   for (int i = 0; i < 5; i++) { // loop through all 5 array items
      string email = classRosterArray[i]->GetEmailAddress(); // get the email from the derefed object
      size_t atLocation; // var for storing the location @ is found so you can search for another one after the first
      char charToFind;
      if (string::npos != email.find(" ") || string::npos != email.find("(") || string::npos != email.find("\"") ||
          string::npos != email.find(")") || string::npos != email.find(",") || string::npos != email.find(":") ||
          string::npos != email.find(";") || string::npos != email.find("<") || string::npos != email.find(">") ||
          string::npos != email.find("[") || string::npos != email.find("\\") || string::npos != email.find("]")) { // look for all the chars that are not allowed in emails
         cout << email << "\tis not a valid email. Invalid char found." << endl;
      }

      // could have made this a private function that but not sure if allowed. Would have had to spend more time on is so easyer this way i guess.
      charToFind = '@';
      atLocation = email.find(charToFind); // set the @ location to the first find
      if (string::npos != atLocation) { // make sure the location is not == npos (if it was than nothing was found and its not valid)

          //this is success because one charToFind was found

         if (string::npos != email.find(charToFind, atLocation + 1)) { // check for more @'s after the first 

             //this is Bad because 2 charToFind were found
            cout << email << "\tis not a valid email. 2 " << charToFind << " found" << endl;
         }
      }
      else { // this will trigger is 0 charToFind were found
         cout << email << "\tis not a valid email. no " << charToFind << " found" << endl;
      }

      charToFind = '.';
      atLocation = email.find(charToFind); // set the . location to the first find
      if (string::npos != atLocation) { // make sure the location is not == npos (if it was than nothing was found and its not valid)

          //this is success because one charToFind was found
          /* Commented out because emails can have 2 "."
          if(string::npos != email.find(charToFind,atLocation + 1)){ // check for more @'s after the first

              //this is Bad because 2 charToFind were found
              cout << email << " is not a valid email. 2 " << charToFind << " found" << endl;
          }
          */
      }
      else { // this will trigger is 0 charToFind were found
         cout << email << "\tis not a valid email. no " << charToFind << " found" << endl;
      }

      //FIXME: check for .

   }
}

int Roster::FindEmptyArrayItem() {
   int i = 0;
   while (classRosterArray[i] != nullptr) {
      i++;
   }
   return i;

}

Roster::~Roster() {
   int i = 0;
   while (i < 5) {
      if (classRosterArray[i] != nullptr) { // check to see if there is an object in that slot of the array.			 		
         delete classRosterArray[i];
         classRosterArray[i] = nullptr;
      }
      i++;
   }
}