#include "Assignment.h"

Assignment::Assignment(string n, string d, double w, string cn) {
  name = n;
  due_date = d;
  weight = w;
  class_name = cn;
}

string Assignment::getName() const { return name; }

string Assignment::getDueDate() const { return due_date; }

double Assignment::getWeight() const { return weight; }

string Assignment::getClassName() const { return class_name; }
