#include "Exam.h"

Exam::Exam(string name) { this->name = name; }

void Exam::setName(string name) { this->name = name; }

void Exam::addGrade(int grade) { grades.push_back(grade); }

string Exam::getName() { return name; }

vector<int> Exam::getGrades() { return grades; }

double Exam::getAverageGrade() {
  int total = 0;
  for (int grade : grades) {
    total += grade;
  }
  return (double)total / grades.size();
}
