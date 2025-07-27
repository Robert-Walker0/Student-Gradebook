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

void Gradebook::saveAllStudent() const
{
  if(!Students.empty())
  {
    std::ofstream gradebookFile;
    gradebookFile.open("StudentData.txt");

    if(!gradebookFile.is_open())
    {
      std::cerr << "Error: We encountered an error when trying to open file for saving. Unable to save data for gradebook.";

      return;
    }


    for(Student student : Students)
    {
      const std::map<std::string, int> currentStudentGrades = student.getGrades();
      gradebookFile << student.getName() << ", " << student.getID() << ", Math: " << currentStudentGrades.at("Math") << ", Science: " << currentStudentGrades.at("Science") << ", English: " << currentStudentGrades.at("English") << std::endl;
    }

    std::cout << "All of the students in the gradebook were successfully saved!" << std::endl;
    gradebookFile.close();
    return;
  }

  std::cout << "There are no students to save to the system. Closing process." << std::endl;
}

Student Gradebook::getStudent(int StudentID)
{
  return Students.at(StudentID - 1);
}

std::vector<std::string> Gradebook::getStudentID() const 
{
  return Student_IDS;
}
