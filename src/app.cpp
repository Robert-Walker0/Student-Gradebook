#include "..\include\app.hpp"

Gradebook schoolGradebook;
unsigned int microseconds = 1000000;
const int SHORT_PAUSE = 1;
const int MEDIUM_PAUSE = 3;
const int LONG_PAUSE = 5;

const int ADD_STUDENT_OPTION = 1;
const int VIEW_STUDENTS_OPTION = 2;
const int SEARCH_BY_ID_OPTION = 3;
const int SAVE_TO_FILE_OPTION = 4;
const int LOAD_FROM_FILE_OPTION = 5;
const int EXIT_OPTION = 6;

// OS related functions

void clearScreen(int timeInSeconds)
{
  usleep(timeInSeconds * microseconds);
  #if defined _WIN32
    std::system("cls");
  #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || (__APPLE__)
    std::system("clear");
  #endif
}

//Gradebook Functions

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

void addStudent()
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
}

void viewStudent()
{
  clearScreen(SHORT_PAUSE);
  schoolGradebook.displayStudents();
  clearScreen(LONG_PAUSE);
}

void searchByID()
{
  if(!schoolGradebook.getStudentID().empty())
  {
    clearScreen(SHORT_PAUSE);
    int studentIDToFind;
    std::cout << "Enter the ID of the student to search for: \n> ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if(!(std::cin >> studentIDToFind))
    {
        std::cout << "Please enter a number into system to find a student!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clearScreen(MEDIUM_PAUSE);
        return;
    }

    auto studentEntry = std::find(schoolGradebook.getStudentID().begin(), schoolGradebook.getStudentID().end(), std::to_string(studentIDToFind));

    if(studentEntry == schoolGradebook.getStudentID().end())
    {
      std::cout << "There is no student with that student ID in our systems." << std::endl;
      clearScreen(SHORT_PAUSE);
      return;
    }

    Student currentStudent = schoolGradebook.getStudent(studentIDToFind);
    std::cout << currentStudent.getName() << std::endl; 
    clearScreen(LONG_PAUSE);
    
    return;
  }

  std::cout << "There are no students currently in the Gradebook! Please add a student before trying to do this again!" << std::endl;
}

void inputHandler(int inputValue)
{
  if(inputValue == ADD_STUDENT_OPTION)
  {
   addStudent();
  } else if (inputValue == VIEW_STUDENTS_OPTION) {
    viewStudent();
  } else if(inputValue == SEARCH_BY_ID_OPTION)
  {
    searchByID();
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
