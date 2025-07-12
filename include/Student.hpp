#pragma once
#include <iostream>
#include <string>
#include <bits/stdc++.h>

class Student
{
public:
  Student(std::string name, std::map<std::string, int> grades);
  std::string getName() const;
  std::map<std::string, int> getGrades() const;
  int getID() const;
  int getStudentCount() const;
private:
  int id_number;
  std::string name;
  std::map<std::string, int> grades; 
  static int studentCount;
};
