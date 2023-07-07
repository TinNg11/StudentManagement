#include "Teacher.h"

Teacher::Teacher() {
    subjects_taught = "";
    teacher_id = "";
}

Teacher::Teacher(string n, string e, string s, string i) : Person(n, e) {
    subjects_taught = s;
    teacher_id = i;
}

string Teacher::getSubjects() const {
    return subjects_taught;
}

string Teacher::getId() const {
    return teacher_id;
}

void Teacher::updateSubjects(string s) {
    subjects_taught = s;
}

void Teacher::updateID(string i) {
    teacher_id = i;
}
