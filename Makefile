CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/main.cpp src/Student.cpp src/Gradebook.cpp src/app.cpp
OUT = bin/gradebook.exe

all:
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)