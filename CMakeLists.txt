cmake_minimum_required(VERSION 3.23)
project (fns)

set(CMAKE_CXX_STANDARD 14)

add_executable(fns main.cpp file_manager/file_manager.cpp file_manager/file_manager.h data/input.txt data/output.txt)
