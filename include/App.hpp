#pragma once
#include <iostream>
#include <unistd.h>
#include <conio.h>
#include "..\include\Gradebook.hpp"

int getMainMenuEntry();
void clearScreen(int timeInSeconds);
void addStudent();
void viewStudent();
void searchByID();
void inputHandler(int inputValue);
