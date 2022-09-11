cmake_minimum_required(VERSION 3.23)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1 main.cpp Models/BidList.cpp Models/BidList.h Menu/MyMenu.cpp Menu/MyMenu.h Menu/MyMenuItem.cpp Menu/MyMenuItem.h StartProgram.h)
