#include "..\include\Student.hpp"

int Student::studentCount = 0;

Student::Student(std::string name, std::map<std::string, int> grades)
{
  this->name = name;
  this->grades = grades;
  studentCount++;
  id_number = studentCount;
}

std::string Student::getName() const
{
  return name;
}

std::map<std::string, int> Student::getGrades() const 
{
  return grades;
}

int Student::getID() const 
{
  return id_number;
}

int Student::getStudentCount() const
{
  return studentCount;
}