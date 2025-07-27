#include "../include/app.hpp"

int main()
{
  int input;
  do {
    input = getMainMenuEntry();
    inputHandler(input);
  } while(input != 6);

  return 0;
}
