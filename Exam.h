#ifndef EXAM_H
#define EXAM_H

#include <string>
#include <vector>

using namespace std;

class Exam {
private:
  string name;
  vector<int> grades;

public:
  Exam(string name);

  // Setters
  void setName(string name);
  void addGrade(int grade);

  // Getters
  string getName();
  vector<int> getGrades();

  double getAverageGrade();
};

#endif
