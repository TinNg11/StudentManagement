#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

#include "Student.h"
#include "Teacher.h"
#include "Class.h"
#include "Exam.h"
#include "Assignment.h"

using namespace std;

int main() {

  string filename;
  cout << "Enter the name of the file to load data from: ";
  cin >> filename;
  ifstream infile(filename);
  if (!infile) {
    cout << "File not found" << endl;
    return 0;
  }
  
  int choice;

  cout << "Welcome to the Student Management System" << endl;
  cout << "Please select an option:" << endl;
  cout << "1. Create a new classroom" << endl;
  cout << "2. Create a new student" << endl;
  cout << "3. Create a new teacher" << endl;
  cin >> choice;

  if (choice == 1) {
    string class_name, class_teacher, class_id;
    vector<string> students;
    getline(infile, class_name);
    getline(infile, class_teacher);
    getline(infile, class_id);
    string line;
    while (getline(infile, line)) {
      string name;
      stringstream ss(line);
      while (getline(ss, name, ',')) {
        students.push_back(name);
      }
    }

    Class userClass(class_name, class_teacher, class_id, students);
    
    ofstream outfile("class-output.txt");

    int classChoice;

    while (true) {
      cout << "What would you like to do with this class? Please select an option:" << endl;
      cout << "1. Get class name" << endl;
      cout << "2. Get class teacher" << endl;
      cout << "3. Get class id" << endl;
      cout << "4. Get class students" << endl;
      cout << "5. Set class name" << endl;
      cout << "6. Set class teacher " << endl;
      cout << "7. Set class id" << endl;
      cout << "8. Set class students" << endl;
      cout << "9. Mark attendance" << endl;
      cout << "10. Get Attendance Report" << endl;
      cout << "11. Enter Exam Grades" << endl;
      cout << "0. Quit" << endl;

      cin >> classChoice;

      if (classChoice == 0) {
        break;
      }

      string newName, newTeacher, newID, newStudentName, date, presentString, presentStudentName, startDate, endDate, gradeString, examName;
      vector<string> newStudentsList, presentStudents;
      


      switch (classChoice) {
          case 1: {
              outfile << "Class Name: " << userClass.getName() << endl;
              break;
          }
          case 2: {
              outfile << "Class Teacher: " << userClass.getTeacher() << endl;
              break;
          }
          case 3: {
              outfile << "Class ID: " << userClass.getID() << endl;
              break;
          }
          case 4: {
              outfile << "Class Students: ";
              for (string name : userClass.getStudents()) {
                outfile << name << ", ";
              }
              outfile << endl;
              break;
          }
          case 5: {
              cout << "Enter new class name: " << endl;
              cin >> newName;
              userClass.setName(newName);
              outfile << "New Class Name: " << userClass.getName() << endl;
              break;
          }
          case 6: {
              cout << "Enter new class Teacher: " << endl;
              cin >> newTeacher;
              userClass.setTeacher(newTeacher);
              outfile << "New Class Teacher: " << userClass.getTeacher() << endl;
              break;
          }
          case 7: {
              cout << "Enter new class ID: " << endl;
              cin >> newID;
              userClass.setID(newID);
              outfile << "New Class ID: " << userClass.getID() << endl;
              break;
          }
          case 8: {
              cout << "Enter new student names (separated by commas):" << endl;
              cin.ignore();
              getline(cin, newStudentName);
              stringstream ss(newStudentName);
              while (getline(ss, newStudentName, ',')) {
                  newStudentsList.push_back(newStudentName);
              }
              userClass.setStudents(newStudentsList);
              outfile << "New Students: ";
              for (string name : userClass.getStudents()) {
                  outfile << name << ", ";
              }
              outfile << endl;
              break;
          }
          case 9: {
              cout << "Enter date (MM/DD/YYYY)" << endl;
              cin >> date;
              cout << "Enter names of present students (separated by commas):" << endl;
              cin.ignore();
              getline(cin, presentString);
              stringstream ss2(presentString);
              while (getline(ss2, presentStudentName, ',')) {
                presentStudents.push_back(presentStudentName);
              }
              userClass.markAttendance(date, presentStudents);
              break;
          }
          case 10: {
              cout << "Enter start date (MM/DD/YYYY): ";
              cin >> startDate;
            
              cout << "Enter end date (MM/DD/YYYY): ";
              cin >> endDate;
              vector<pair<string, vector<string>>> attendance = userClass.getAttendanceReport(startDate, endDate);

              map<string, int> presenceCount;
              for (auto& item : attendance) {
                  for (auto& student : item.second) {
                      presenceCount[student]++;
                  }
              }
          
              outfile << "Attendance report for " << startDate << " to " << endDate << ":" << endl;
              for (auto& item : presenceCount) {
                  outfile << item.first << ": " << item.second << endl;
              }
              break;
          }
          case 11: {
              cout << "Enter exam name: " << endl;
              cin >> examName;
          
              Exam exam(examName);
          
              cout << "Enter grades separated by commas: " << endl;
              cin.ignore();
          
              string gradeString;
              getline(cin, gradeString);
          
              stringstream ss3(gradeString);
              vector<int> grades;
          
              while (getline(ss3, gradeString, ',')) {
                  int grade = stoi(gradeString);
                  exam.addGrade(grade);
              }
          
              userClass.enterExamGrades(&exam, exam.getGrades());
          
              outfile << "Exam Grades for: " << examName << endl;
          
              // Get the grades for the exam and output them
              vector<int> examGrades = exam.getGrades();
              for (int i = 0; i < userClass.getStudents().size(); i++) {
                  outfile << userClass.getStudents()[i] << ": " << examGrades[i] << endl;
              }
              break;
          }

        
      }
      
    }
    outfile.close();
  }

    
  else if (choice == 2) {
    string name, email, schedule, id;
    getline(infile, name);
    getline(infile, email);
    getline(infile, schedule);
    getline(infile, id);
    Student userStudent(name, email, schedule, id);

    ofstream outfile("student-output.txt");

    int studentChoice;

    while (true) {
    
      cout << "What would you like to do with this student? Please select an option:" << endl;
      cout << "1. Get student name" << endl;
      cout << "2. Get student email" << endl;
      cout << "3. Get student schedule" << endl;
      cout << "4. Get student id" << endl;
      cout << "5. Update student name" << endl;
      cout << "6. Update student email" << endl;
      cout << "7. Update student schedule" << endl;
      cout << "8. Update student id" << endl;
      cout << "9. Mark attendence" << endl;
      cout << "10. Calculate class grade" << endl;
      cout << "11. Submit assignment" << endl;
      cout << "0. Quit" << endl;

      cin >> studentChoice;

      if (studentChoice == 0) {
        break;
      }
  
      string newName, newEmail, newSchedule, newID, date, status, assignmentName, assignmentDate, assignmentClass, calName;
      int assignmentGrade;
      double assignmentWeight, classGrade;
  
  
      switch (studentChoice) {
          case 1:
              outfile << "Student Name: " << userStudent.getName() << endl;
              break;
          case 2:
              outfile << "Student Email: " << userStudent.getEmail() << endl;
              break;
          case 3:
              outfile << "Student Schedule: " << userStudent.getSchedule() << endl;
              break;
          case 4:
              outfile << "Student ID: " << userStudent.getId() << endl;
              break;
          case 5:
              cout << "Enter new name:" << endl;
              cin >> newName;
              userStudent.updateName(newName);
              outfile << "Updated Student Name: " << userStudent.getName() << endl;
              break;
          case 6:
              cout << "Enter new email:" << endl;
              cin >> newEmail;
              userStudent.updateEmail(newEmail);
              outfile << "Updated Student Email: " << userStudent.getEmail() << endl;
              break;
          case 7:
              cout << "Enter new schedule:" << endl;
              cin >> newSchedule;
              userStudent.updateSchedule(newSchedule);
              outfile << "Updated Student Schedule: " << userStudent.getSchedule() << endl;
              break;
          case 8:
              cout << "Enter new ID:" << endl;
              cin >> newID;
              userStudent.updateID(newID);
              outfile << "Updated Student ID: " << userStudent.getId() << endl;
              break;
          case 9:
              cout << "Enter date of attendance (YYYY-MM-DD):" << endl;
              cin >> date;
              cout << "Enter the status of that day:" << endl;
              cin >> status;
              userStudent.markAttendance(date, status);
              outfile << "Attendance marked for " << date << ", Status: "<< status << endl;
              break;
          case 10:
              cout << "Enter the name of the class to calculate the class grade:" << endl;
              cin >> calName;
              classGrade = userStudent.calculateClassGrade(calName);
              outfile << "Class grade for " << calName << ": " << classGrade << endl;
              break;
          case 11:
              cout << "Enter name of assignment:" << endl;
              cin >> assignmentName;
              cout << "Enter date of assignment:" << endl;
              cin >> assignmentDate;
              cout << "Enter weight of assignment:" << endl;
              cin >> assignmentWeight;
              cout << "Enter name of class of assignment:" << endl;
              cin >> assignmentClass;
              cout << "Enter grade received for assignment:" << endl;
              cin >> assignmentGrade;
              Assignment a(assignmentName, assignmentDate, assignmentWeight, assignmentClass);
              userStudent.submitAssignment(a, assignmentGrade);
              outfile << "Assignment: " << assignmentName << " received a grade of " << assignmentGrade << endl;
              break;
        } 
    }
    outfile.close();
  }
  
  else if (choice == 3) {
    string teacherName, teacherEmail, teacherSubject, teacherId;
    getline(infile, teacherName);
    getline(infile, teacherEmail);
    getline(infile, teacherSubject);
    getline(infile, teacherId);
    Teacher userTeacher(teacherName, teacherEmail, teacherSubject, teacherId);

    ofstream outfile("teacher-output.txt");

    int teacherChoice;

    while (true) {
      cout << "What would you like to do with this teacher? Please select an option:" << endl;
      cout << "1. Get teacher name" << endl;
      cout << "2. Get teacher email" << endl;
      cout << "3. Get teacher subject" << endl;
      cout << "4. Get teacher id" << endl;
      cout << "5. Update teacher name" << endl;
      cout << "6. Update teacher email" << endl;
      cout << "7. Update teacher subject" << endl;
      cout << "8. Update teacher id" << endl;
      cout << "0. Quit" << endl;

      cin >> teacherChoice;

      if (teacherChoice == 0) {
        break;
      }

      string newName, newEmail, newSubject, newID;

      switch (teacherChoice) {

        case 1: {
          outfile << "Teacher Name: " << userTeacher.getName() << endl;
          break;
        }

        case 2: {
          outfile << "Teacher Email: " << userTeacher.getEmail() << endl;
          break;
        }

        case 3: {
          outfile << "Teacher Subject: " << userTeacher.getSubjects() << endl;
          break;
        }

        case 4: {
          outfile << "Teacher ID: " << userTeacher.getId() << endl;
          break;
        }

        case 5: {
          cout << "Enter new name:" << endl;
          cin >> newName;
          userTeacher.updateName(newName);
          outfile << "Updated Teacher Name: " << userTeacher.getName() << endl;
            break;
        }
          case 6: {
          cout << "Enter new email:" << endl;
          cin >> newEmail;
          userTeacher.updateEmail(newEmail);
          outfile << "Updated Teacher Email: " << userTeacher.getEmail() << endl;
            break;
          }
          case 7: {
          cout << "Enter new subject:" << endl;
          cin >> newSubject;
          userTeacher.updateSubjects(newSubject);
          outfile << "Updated Teacher Schedule: " << userTeacher.getSubjects() << endl;
            break;
          }
          case 8: {
          cout << "Enter new ID:" << endl;
          cin >> newID;
          userTeacher.updateID(newID);
          outfile << "Updated Teacher ID: " << userTeacher.getId() << endl;
            break;
          }

        
      }
    }

    
  } 
  else {
    cout << "Invalid choice" << endl;
    return 0;
  }  

  
  return 0;
}
