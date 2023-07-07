#include "Class.h"

Class::Class() {
  name = "";
  teacher = "";
  class_id = "";
}

Class::Class(string name, string teacher, string class_id,
             vector<string> students) {
  this->name = name;
  this->teacher = teacher;
  this->students = students;
  this->class_id = class_id;
}

void Class::setName(string name) { this->name = name; }

void Class::setTeacher(string teacher) { this->teacher = teacher; }

void Class::setID(string class_id) { this->class_id = class_id; }

void Class::setStudents(vector<string> students) { this->students = students; }

string Class::getName() const { return name; }

string Class::getTeacher() const { return teacher; }

string Class::getID() const { return class_id; }

vector<string> Class::getStudents() const { return students; }

void Class::markAttendance(string date, vector<string> status) {
  attendance.push_back({date, status});
}


vector<pair<string, vector<string>>> Class::getAttendanceReport(string startDate, string endDate) {
  vector<pair<string, vector<string>>> report;

  // Loop through each attendance record
  for (auto record : attendance) {
    string date = record.first;
    // Check if the date is within the specified range
    if (date >= startDate && date <= endDate) {
      // Create a vector of attendance statuses for this record
      vector<string> statuses;
      for (auto status : record.second) {
        statuses.push_back(status);
      }
      report.push_back({date, statuses});
    }
  }

  return report;
}

void Class::enterExamGrades(Exam *exam, vector<int> grades) {
  // Get the exam name
  string examName = exam->getName();

  // Loop through each student and their grade
  for (int i = 0; i < students.size(); i++) {
    string studentId = students[i];
    int grade = grades[i];

    // Check if the student has already taken the exam
    bool found = false;
    for (int j = 0; j < exam_grades.size(); j++) {
      Exam *e = exam_grades[j].first;
      if (e->getName() == examName) {
        found = true;
        // Update the student's grade
        exam_grades[j].second[i] = grade;
        break;
      }
    }

    // If the student hasn't taken the exam, add a new entry for them
    if (!found) {
      vector<int> newGrades(students.size());
      newGrades[i] = grade;
      exam_grades.push_back({exam, newGrades});
    }
  }
}
