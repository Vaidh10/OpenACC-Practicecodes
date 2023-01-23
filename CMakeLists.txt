cmake_minimum_required(VERSION 3.10)

project(OpenACC_Examples)

# Find OpenACC
find_package(OpenACC REQUIRED)

# Add OpenACC flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -acc -ta=tesla")

# Find all example directories
file(GLOB example_dirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} * )

# Loop through each example directory and build the program
foreach(example_dir ${example_dirs})
    add_executable(${example_dir} ${example_dir}/${example_dir}.c)
    add_custom_target(run_${example_dir}
        COMMAND ${example_dir}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${example_dir}
        )
endforeach()