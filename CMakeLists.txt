# cmake_minimum_required(VERSION 3.10)
# project(my_project)

# # Set the source directories for the C and C++ files
# set(C_SOURCE_DIR src/)
# set(CXX_SOURCE_DIR src/)

# # Collect the C and C++ source files
# file(GLOB C_SOURCES "${C_SOURCE_DIR}/*.c")
# file(GLOB CXX_SOURCES "${CXX_SOURCE_DIR}/*.cpp")


# if(CMAKE_C_COMPILER MATCHES "gcc")
#   set(CMAKE_C_FLAGS "-fopenacc -fopt-info")
# elseif(CMAKE_C_COMPILER MATCHES "nvc")
#   set(CMAKE_C_FLAGS "-ta=tesla -Minfo=all")
# endif()


# Add the executable target, specifying the C and C++ source files
add_executable(my_project ${C_SOURCES} ${CXX_SOURCES})

cmake_minimum_required(VERSION 3.10)
project(openacc_code_examples)

# set compiler flags based on the compiler
if(CMAKE_C_COMPILER_ID STREQUAL "PGI")
    set(CMAKE_C_FLAGS "-acc -Minfo=accel -ta=tesla:cc35")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Cray")
    set(CMAKE_C_FLAGS "-h acc")
elseif(CMAKE_C_COMPILER_ID STREQUAL "NVIDIA")
    set(CMAKE_C_FLAGS "-Xcompiler -fopenacc")
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "-fopenacc")
endif()

# specify the source files
file(GLOB SOURCES "src/*.c")

# specify the executable
# add_executable(openacc_code_examples ${SOURCES})

# Here's the general process for building and running the OpenACC code examples using the provided CMake file:

# Create a build directory: mkdir build
# Navigate to the build directory: cd build
# Run CMake to generate the build files: cmake ..
# Build the code: cmake --build .
# Run the executable: ./openacc_code_examples