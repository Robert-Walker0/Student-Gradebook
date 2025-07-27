#include "../include/app.hpp"

int main()
{
  int input;
  do {
    input = getMainMenuEntry();
    inputHandler(input);
  } while(input != 6);

  std::cout << "You have exited the program. Goodbye!" << std::endl;
}
