cmake_minimum_required(VERSION 3.10)
project(my_project)

# Set the source directories for the C and C++ files
set(C_SOURCE_DIR src/)
set(CXX_SOURCE_DIR src/)

# Collect the C and C++ source files
file(GLOB C_SOURCES "${C_SOURCE_DIR}/*.c")
file(GLOB CXX_SOURCES "${CXX_SOURCE_DIR}/*.cpp")


if(CMAKE_C_COMPILER MATCHES "gcc")
  set(CMAKE_C_FLAGS "-fopenacc -fopt-info")
elseif(CMAKE_C_COMPILER MATCHES "nvc")
  set(CMAKE_C_FLAGS "-ta=tesla -Minfo=all")
endif()


# Add the executable target, specifying the C and C++ source files
add_executable(my_project ${C_SOURCES} ${CXX_SOURCES})