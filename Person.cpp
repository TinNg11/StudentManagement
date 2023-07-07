#include "Person.h"

Person::Person() {
    name = "";
    email = "";
}

Person::Person(string n, string e) {
    name = n;
    email = e;
}

string Person::getName() const {
    return name;
}

string Person::getEmail() const {
    return email;
}

void Person::updateName(string n) {
    name = n;
}

void Person::updateEmail(string e) {
    email = e;
}
