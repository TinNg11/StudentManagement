#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>

using namespace std;

class Assignment {
  private:
    string name;
    string due_date;
    double weight;
    string class_name;

  public:
    Assignment(string n, string d, double w, string cn);
    
    string getName() const;
    string getDueDate() const;
    double getWeight() const;
    string getClassName() const;
};

#endif
