#include "Student.h"

// Constructor

Student::Student() : Person("", "") {
  class_schedule = "";
  student_id = "";
}

Student::Student(string n, string e, string s, string i) : Person(n, e) {
  class_schedule = s;
  student_id = i;
}

string Student::getSchedule() const { 
  return class_schedule; 
}

string Student::getId() const { return student_id; }

void Student::updateSchedule(string s) { 
  class_schedule = s; 
}

void Student::updateID(string i) { 
  student_id = i;
}

void Student::markAttendance(string date, string status) {
  // Create a new pair object to store the date and attendance status
  pair<string, string> attendanceRecord(date, status);

  // Add the attendance record to the vector
  attendance.push_back(attendanceRecord);

  // Print out the attendance record for verification (remove this in final
  // version)
  cout << name << " was marked " << status << " on " << date << endl;
}

void Student::submitAssignment(Assignment assignment, int grade) {
  pair<Assignment, int> assignmentRecord(assignment, grade);
  assignments.push_back(assignmentRecord);
}

double Student::calculateClassGrade(string className) const {
  double totalScore = 0;
  double totalWeight = 0;

  // Loop through all assignments
  for (auto const &assignment : assignments) {
    if (assignment.first.getClassName() == className) {
      totalScore += assignment.second * assignment.first.getWeight();
      totalWeight += assignment.first.getWeight();
    }
  }

  if (totalWeight == 0) {
    return 0;
  }

  return totalScore / totalWeight;
}
