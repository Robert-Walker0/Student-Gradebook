#include <iostream>
#include <unistd.h>
#include "..\include\Student.hpp"
#include "..\include\Gradebook.hpp"

Gradebook schoolGradebook;

// Time Related Variables
unsigned int microseconds = 1000000;
const int SHORT_PAUSE = 1;
const int MEDIUM_PAUSE = 3;
const int LONG_PAUSE = 5;

//Menu Options
const int ADD_STUDENT_OPTION = 1;
const int VIEW_STUDENTS_OPTION = 2;
const int SEARCH_BY_ID_OPTION = 3;
const int SAVE_TO_FILE_OPTION = 4;
const int LOAD_FROM_FILE_OPTION = 5;
const int EXIT_OPTION = 6;

int getMainMenuEntry()
{
  int value;
  std::cout << "1. Add Student" << std::endl;
  std::cout << "2. View All Students" << std::endl;
  std::cout << "3. Search Student by ID" << std::endl;
  std::cout << "4. Save to file" << std::endl;
  std::cout << "5. Load from file" << std::endl;
  std::cout << "6. Exit" << std::endl;

  std::cout << "\n\nSelect an option:\n> ";
  std::cin >> value;
  return value;
}

void clearScreen(int timeInSeconds)
{
  usleep(timeInSeconds * microseconds);
  std::cout << "\033c";
}

void inputHandler(int inputValue)
{
  if(inputValue == ADD_STUDENT_OPTION)
  {
    clearScreen(SHORT_PAUSE);
    std::string name;
    int mathGrade;
    int scienceGrade;
    int englishGrade;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the student's name: \n> ";
    std::getline(std::cin, name);
    
    std::cout << "Enter the student's grade for Math: \n> ";
    std::cin >> mathGrade;
    
    std::cout << "Enter the student's grade for Science: \n> ";
    std::cin >> scienceGrade;
    
    std::cout << "Enter the student's grade for English: \n> ";
    std::cin >> englishGrade;

    Student studentObj(name, {{"Math", mathGrade}, {"Science", scienceGrade}, {"English", englishGrade}});
    schoolGradebook.addStudent(studentObj);
    std::cout << studentObj.getName() << " has been added to the gradebook!" << std::endl;
    clearScreen(MEDIUM_PAUSE);
  } else if (inputValue == VIEW_STUDENTS_OPTION) {
    clearScreen(SHORT_PAUSE);
    schoolGradebook.displayStudents();
    clearScreen(LONG_PAUSE);
  } else if(inputValue == SEARCH_BY_ID_OPTION)
  {
    // Search Student by ID
  } else if(inputValue == SAVE_TO_FILE_OPTION)
  {
    // Save to file 
  } else if(inputValue == LOAD_FROM_FILE_OPTION) {
    // Load from file
  } else if(inputValue == EXIT_OPTION) {
    // Exit
  } else {
    clearScreen(SHORT_PAUSE);
    std::cout << "Invalid value detected. Please enter a valid option (1 - 6)." << std::endl;
    clearScreen(MEDIUM_PAUSE);
  }
}

int main()
{
  int input;
  do {
    input = getMainMenuEntry();
    inputHandler(input);
  } while(input != 6);

  std::cout << "You have exited the program. Goodbye!" << std::endl;
}
