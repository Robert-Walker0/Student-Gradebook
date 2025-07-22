#include "..\include\Gradebook.hpp"

void Gradebook::addStudent(Student newStudent)
{
  Students.push_back(newStudent);
  Student_IDS.push_back(std::to_string(newStudent.getID()));
}

void Gradebook::displayStudents() const
{
  if(Students.empty()) 
  {
    std::cout << "There are no students in the gradebook!" << std::endl;
  } else {
    std::cout << "Here is every single student listed by name: " << std::endl;
    for (Student student : Students)
      {
        std::cout << student.getName() << std::endl;
      }
  }
}

Student Gradebook::getStudent(int StudentID)
{
  return Students.at(StudentID - 1);
}

std::vector<std::string> Gradebook::getStudentID() const 
{
  return Student_IDS;
}
