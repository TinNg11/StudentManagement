
#ifndef STUDENT_H
#define STUDENT_H

#include "Assignment.h"
#include "Person.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student : public Person {
private:
  string class_schedule;
  string student_id;
  vector<pair<string, string>> attendance;
  vector<pair<Assignment, int>> assignments;

public:
  Student();
  Student(string n, string e, string s, string i);

  string getSchedule() const;
  string getId() const;

  void updateSchedule(string s);
  void updateID(string i);

  void markAttendance(string date, string status);
  void submitAssignment(Assignment assignment, int grade);
  double calculateClassGrade(string className) const;
};

#endif
