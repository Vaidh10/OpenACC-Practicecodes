cmake_minimum_required(VERSION 3.0)

# project name
project(OpenACC_Practicecodes)

# Add the OpenACC compiler flags for each compiler
if (CMAKE_C_COMPILER_ID MATCHES "gcc")
    set(OpenACC_FLAGS "-fopenacc -fopt-info")
elseif (CMAKE_C_COMPILER_ID MATCHES "nvc")
    set(OpenACC_FLAGS "-Minfo=accel")
endif()

# Add the OpenACC libraries for each compiler
if (CMAKE_C_COMPILER_ID MATCHES "gcc")
    set(OpenACC_LIBS "-lm")
elseif (CMAKE_C_COMPILER_ID MATCHES "nvc")
    set(OpenACC_LIBS "-acc -ta=tesla")
endif()

# Define the list of directories containing the example programs
set(PRACTICECODE_DIRECTORIES Cube-OpenACC Jacobi Knapsack-Problem Matrix-Multiplication Newton-fractals Ray-Tracer)

# Use a foreach loop to iterate over the directories and build the example programs
foreach(example_dir ${PRACTICECODE_DIRECTORIES})
    file(GLOB example_sources ${example_dir}/*.c)
    add_executable(${example_dir} ${example_sources})
    target_compile_options(${example_dir} PUBLIC ${OpenACC_FLAGS})
    target_link_libraries(${example_dir} PUBLIC ${OpenACC_LIBS})
endforeach()