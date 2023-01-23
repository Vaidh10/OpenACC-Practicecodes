cmake_minimum_required(VERSION 3.0)

# Set the project name
project(OpenACC_Examples)
# Add the OpenACC compiler flags for each compiler
if (CMAKE_C_COMPILER_ID MATCHES "gcc")
    set(OpenACC_FLAGS "-fopenacc -fopt-info")
elseif (CMAKE_C_COMPILER_ID MATCHES "nvc")
    set(OpenACC_FLAGS "-Minfo=accel")
#elseif (CMAKE_C_COMPILER_ID MATCHES "Cray")
#    set(OpenACC_FLAGS "-acc")
elseif (CMAKE_C_COMPILER_ID MATCHES "clang")
    set(OpenACC_FLAGS "-fopenacc")
endif()

# Add the OpenACC libraries for each compiler
if (CMAKE_C_COMPILER_ID MATCHES "gcc")
    set(OpenACC_LIBS "-lm")
elseif (CMAKE_C_COMPILER_ID MATCHES "nvc")
    set(OpenACC_LIBS "-acc")
#elseif (CMAKE_C_COMPILER_ID MATCHES "Cray")
#    set(OpenACC_LIBS "-lm")
elseif (CMAKE_C_COMPILER_ID MATCHES "clang")
    set(OpenACC_LIBS "-lm")
endif()

# Define the list of directories containing the example programs
set(EXAMPLE_DIRECTORIES Dijkstra-Algorithm Gas-Particle-Simulation Jacobi Knapsack-Problem Matrix-Multiplication Newton-fractals cube-OpenACC)

# Use a foreach loop to iterate over the directories and build the example programs
foreach(example_dir ${EXAMPLE_DIRECTORIES})
    file(GLOB example_sources ${example_dir}/*.c)
    add_executable(${example_dir} ${example_sources})
    target_compile_options(${example_dir} PUBLIC ${OpenACC_FLAGS})
    target_link_libraries(${example_dir} PUBLIC ${OpenACC_LIBS})
endforeach()