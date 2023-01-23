cmake_minimum_required(VERSION 3.0)

# Set the project name
project(OpenACC_Examples)
# Add the OpenACC compiler flags for each compiler
if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenACC_FLAGS "-fopenacc")
elseif (CMAKE_C_COMPILER_ID MATCHES "nvc")
    set(OpenACC_FLAGS "-acc -Minfo=accel")
elseif (CMAKE_C_COMPILER_ID MATCHES "Cray")
    set(OpenACC_FLAGS "-h acc")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenACC_FLAGS "-qsmp=omp -qoffload")
endif()

# Add the OpenACC libraries for each compiler
if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenACC_LIBS "-lm")
elseif (CMAKE_C_COMPILER_ID MATCHES "nvc")
    set(OpenACC_LIBS "-lm -lcudart")
elseif (CMAKE_C_COMPILER_ID MATCHES "Cray")
    set(OpenACC_LIBS "-lm -lcudart")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenACC_LIBS "-lm -lcudart")
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