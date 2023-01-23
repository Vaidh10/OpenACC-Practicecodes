# OpenACC-Practicecodes

This repository contains a comprehensive list of fully functional code examples for parallel programming on accelerators using OpenACC. The code is intended to help users learn and practice using OpenACC directives to accelerate their own codes and test them on different OpenACC compilers.

## Requirements

- A compatible compiler with OpenACC support. This includes:
  - NVIDIA HPC SDK compiler
  - Cray compiler
  - GCC (through the OpenACC plugin)
  - Clacc compiler (OpenACC support for clang)
- An OpenACC-enabled device, such as a GPU

## Build Instructions

To build the project, you will need to have CMake installed on your system. Here is an example of how you can use CMake to build the project:

1. Create a new directory for the build files and Change directory to the build directory.

2. Run the cmake command to generate the build files, pointing it to the CMakeLists.txt file.

3. Run the make command to build the project.You can then run the example programs by executing the resulting executables.
```
    $ mkdir build && cd build
    $ cmake -S . -B build/ -DCMAKE_C_COMPILER=nvc
    $ make
    $ ./<example_program>
```    

## Examples

The repository contains a variety of examples, including:

- Jacobi
- Matrix multiplication
- Mini-Weather
- Dijkstra-Algorithm
- And more

## Additional Resources

- The OpenACC website (https://www.openacc.org/) provides documentation and tutorials on using the OpenACC programming model.
- Many of the compilers listed above also provide their own documentation and resources for using OpenACC.
