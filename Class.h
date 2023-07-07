#ifndef CLASS_H
#define CLASS_H

#include "Exam.h"
#include "Student.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Attendance {
  string date;
  vector<pair<string, string>>
      attendance_list; // pair of student_id and attendance status
};

class Class {
private:
  string name;
  string teacher;
  string class_id;
  vector<string> students;
  vector<pair<string, vector<string>>> attendance;
  vector<pair<Exam *, vector<int>>> exam_grades;

public:
  Class();
  Class(string name, string teacher, string class_id, vector<string> students);

  void setName(string name);
  void setTeacher(string teacher);
  void setID(string class_id);
  void setStudents(vector<string> students);

  string getName() const;
  string getTeacher() const;
  string getID() const;
  vector<string> getStudents() const;

  void markAttendance(string date, vector<string> status);
  vector<pair<string, vector<string>>> getAttendanceReport(string startDate, string endDate);
  void enterExamGrades(Exam *exam, vector<int> grades);
};

#endif
