#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

//This is the parent class that i wanted to create so that the other classes can inherit from

class Person {
  protected:
    string name;
    string email;
  public:
    Person();
    Person(string n, string e);

    // Setters
    string getName() const;
    string getEmail() const;

    //Getters
    void updateName(string n);
    void updateEmail(string e);
};

#endif
