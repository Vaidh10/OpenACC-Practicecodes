cmake_minimum_required(VERSION 3.10)
project(my_project)

# Set the source directories for the C and C++ files
set(C_SOURCE_DIR src/)
set(CXX_SOURCE_DIR src/)

# Collect the C and C++ source files
file(GLOB C_SOURCES "${C_SOURCE_DIR}/*.c")
file(GLOB CXX_SOURCES "${CXX_SOURCE_DIR}/*.cpp")

# Set the compiler and flags
set(CMAKE_C_COMPILER nvc)
set(CMAKE_C_FLAGS "-ta=tesla -Minfo=all")
set(CMAKE_CXX_COMPILER gcc)
set(CMAKE_CXX_FLAGS "-fopenacc -fopt-info")

# Add the executable target, specifying the C and C++ source files
add_executable(my_project ${C_SOURCES} ${CXX_SOURCES})