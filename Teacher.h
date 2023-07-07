#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

#include <iostream>
#include <string>
using namespace std;

class Teacher : public Person {
private:
  string subjects_taught;
  string teacher_id;

public:
  Teacher();
  Teacher(string n, string e, string s, string i);

  string getSubjects() const;
  string getId() const;

  void updateSubjects(string s);
  void updateID(string i);
};

#endif
