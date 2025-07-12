#pragma once
#include "Student.hpp"
#include <vector>

class Gradebook
{
  public:
    void displayStudents() const;
    void addStudent(Student newStudent);
  private:
    std::vector<Student> Students;
};