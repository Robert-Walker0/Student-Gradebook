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

void Gradebook::loadStudents()
{
  std::ifstream studentDataFile("StudentData.txt");
  if(!std::filesystem::exists("StudentData.txt"))
  {
    std::cout << "There is no data in the system currently for students!" << std::endl;
    return;
  }

  std::ifstream studentsFile("StudentData.txt");
  if(studentsFile.is_open())
  {
    std::string currentStudentLine;
    while(std::getline(studentsFile, currentStudentLine))
    {
      std::string name, id;
      int start = 0;
      std::string math, science, english;
      name = currentStudentLine.substr(start, currentStudentLine.find(","));
      currentStudentLine.replace(start, name.size() + 1, "");
      id = currentStudentLine.substr(start, currentStudentLine.find(","));
      currentStudentLine.replace(start, id.size() + 1, "");
      math = currentStudentLine.substr(start, currentStudentLine.find(","));
      currentStudentLine.replace(start, math.size() + 1, "");
      science = currentStudentLine.substr(start, currentStudentLine.find(","));
      currentStudentLine.replace(start, science.size() + 1, "");
      english = currentStudentLine.substr(start, currentStudentLine.find(","));
      Student loadedStudent(name, {{"Math", std::stoi(math)}, {"Science", std::stoi(science)}, {"English", std::stoi(english)}});
      this->addStudent(loadedStudent);
      std::cout << name << " has been loaded back into the gradebook!" << std::endl;
    }
  }

  std::cout << "All of the students from the gradebook have been loaded!" << std::endl;
  studentsFile.close();
}

Student Gradebook::getStudent(int StudentID)
{
  return Students.at(StudentID - 1);
}

std::vector<std::string> Gradebook::getStudentID() const 
{
  return Student_IDS;
}
