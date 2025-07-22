#pragma once
#include "Student.hpp"
#include <string>
#include <vector>

class Gradebook
{
  public:
    void displayStudents() const;
    void addStudent(Student newStudent);
    std::vector<std::string> getStudentID() const;
    Student getStudent(int StudentID);
  private:
    std::vector<Student> Students;
    std::vector<std::string> Student_IDS;
};