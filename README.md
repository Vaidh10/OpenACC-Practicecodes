<!-- ## Compile and Execute the benchmarks -->
<!-- Configure the build and run commands.

The Makefile supports different types of compilers. Enter the directory containing the program's name to compile it. such as cd Jacobi then use the nvc/gcc compiler to compile the parallel code.

1.To compile with Nvidia compiler
> make acc CC=nvc

To compile with GCC compiler
> make acc CC=gcc

2.And then enter: `make run` -->

# OpenACC-Practicecodes

This repository contains a comprehensive list of fully functional code examples for parallel programming on accelerators using OpenACC. The code is intended to help users learn and practice using OpenACC directives to accelerate their own codes and test them on different OpenACC compilers.

## Requirements

- A compatible compiler with OpenACC support. This includes:
  - NVIDIA HPC SDK compiler
  - Cray compiler
  - GCC (through the OpenACC plugin)
  - Clacc compiler (OpenACC support for clang)
- An OpenACC-enabled device, such as a GPU

## Usage

1. Clone the repository: `git clone https://github.com/Vaidh10/OpenACC-Practicecodes`
2. Navigate to the code directory: `cd openacc-code-examples`
3. Each example is in its own subdirectory, navigate to the example you want to run.
4. Compile the code with the appropriate compiler flag for your compiler. For example, with the Nvidia compiler: `nvc -acc -Minfo=accel -ta=tesla -o main main.c`
5. Run the binary: `./main`

## Build Instructions

To build the project, you will need to have CMake installed on your system. Here is an example of how you can use CMake to build the project:

1. Create a new directory for the build files and Change directory to the build directory.

2. Run the cmake command to generate the build files, pointing it to the CMakeLists.txt file.

3. Run the make command to build the project.You can then run the example programs by executing the resulting executables.
    ``` mkdir build && cd build```
    ```cmake -S . -B build/ -DCMAKE_C_COMPILER=nvc```
    ```make```
    ```./<example_program>```

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

## Note

We are providing sample code for different compilers please check with your compiler documentation for the exact command and flag to use, also before running the binary make sure that your device is compatible with the flag you are using in the command.

Please also be aware that all the examples are provided as is, there might be some modification required depending on the environment or the data that you are using.