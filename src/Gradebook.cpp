#include "..\include\Gradebook.hpp"

void Gradebook::addStudent(Student newStudent)
{
  Students.push_back(newStudent);
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