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
    $ cmake -S ../ -B . -DCMAKE_C_COMPILER=nvc
    $ make
    $ ./<example_program>
```    

## OpenACC Practicecodes Compilation and Execution Guide

This section will show you how to compile and execute OpenACC code individually for different compilers, without using CMake.

###### Prerequisites

- A computer with a GPU
- An OpenACC compiler, such as GCC, NVIDIA, Cray, Or Clacc

###### Compiling with GCC
To compile OpenACC code using the GCC compiler, use the following command:
```
gcc -fopenacc -fopt-info file.c -o execfile
```
To utilize multi-cores while compiling with OpenACC, you can use the OpenMP API with the GCC compiler. Here's an example command:
```
gcc -fopenmp -fopenacc -o execfile file.c
```
To utilize GPUs while compiling with OpenACC, you can use the following command:
```
gcc -fopenacc --target=nvptx-none -o execfile file.c
```
To utilize both multi-cores and GPUs while compiling with OpenACC, you can use the following command:
```
gcc -fopenmp -fopenacc -o execfile file.c****
```
###### Compiling with NVIDIA
To compile OpenACC code using the NVIDIA compiler, use the following command:
```
nvc -acc -o execfile file.c
```
To utilize multi-cores while compiling with OpenACC, you can use the OpenMP API with the NVIDIA HPC SDK compiler. Here's an example command:
```
nvc -⁠ta=multicore -o execfile file.c
```
To utilize GPUs while compiling with OpenACC, you can use the following command:
```
nvc -⁠ta=tesla -o execfile file.c
```
To utilize both multi-cores and GPUs while compiling with OpenACC, you can use the following command:
```
nvc -o execfile file.c****
```
<!-- 
###### Compiling with Cray
To compile OpenACC code using the Cray compiler, use the following command:
```
-o execfile file.c****
```
To utilize multi-cores while compiling with OpenACC, you can use the OpenMP API with the Cray compiler. Here's an example command:
```
 -o execfile file.c****
```
To utilize GPUs while compiling with OpenACC, you can use the following command:
```
-o execfile file.c****
```
To utilize both multi-cores and GPUs while compiling with OpenACC, you can use the following command:
```
-o execfile file.c****
``` -->
###### Compiling with Clacc
To compile OpenACC code using the Clacc compiler, use the following command:
```
clang -fopenacc -o execfile file.c
```
To utilize GPUs while compiling with OpenACC, you can use the following command:
```
clang -fopenacc -fopenmp-targets=nvptx64-nvidia-cuda -o execfile file.c
```
###### Executing the Code
To execute the compiled code, simply run the executable file:
```
./execfile
```

## Additional Resources

- The OpenACC website (https://www.openacc.org/) provides documentation and tutorials on using the OpenACC programming model.
- Many of the compilers listed above also provide their own documentation and resources for using OpenACC.
- [GCC OpenACC documentation](https://gcc.gnu.org/wiki/OpenACC)
- [NVIDIA OpenACC documentation](https://docs.nvidia.com/cuda/cuda-compiler-driver-nvc/index.html)
- [Cray OpenACC documentation](https://docs.cray.com/books/S-2489-51/html-S-2489-51/openacc.html)
- [Clacc website](https://www.openacc.org/sites/default/files/inline-images/events/F2F20%20presentations/BoF-clacc.pdf)
- [CUDA website](https://developer.nvidia.com/cuda-zone)
