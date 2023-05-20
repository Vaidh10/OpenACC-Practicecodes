# OpenACC-Practicecodes

This repository contains functional code examples for parallel programming using OpenACC. The repository is intended to help users learn and practice using OpenACC directives to accelerate their own codes.

- A OpenACC Compiler is required:
  - NVIDIA HPC SDK compiler
  - Cray compiler
  - GCC (Configured with OpenACC) 
  - Clacc compiler (OpenACC support for clang/LLVM)
## Build Instructions

OpenACC Practicecodes can be built using CMake as follows:

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

Compiling and executing OpenACC code individually for different compilers, without using CMake.

###### Compiling with GCC
To compile and run code for host:
```
export ACC_DEVICE_TYPE=host

gcc -fopenacc -foffload=disable program.c -o execfile -lm
```
To compile and run code for Nvidia and AMD GPU:
```
export ACC_DEVICE_TYPE=nvidia|radeon

gcc -fopenacc program.c -o execfile -lm
```
###### Compiling with NVIDIA
To compile and run code for host:
```
nvc -acc -ta=host -o execfile file.c
```
To compile and run code for multicores:
```
nvc -acc -⁠ta=multicore -o execfile file.c
```
To compile and run code for Nvidia GPU:
```
nvc -acc -gpu=[options] -o execfile file.c
```

###### Compiling with Clacc
To compile and run code for only host:
```
clang -fopenacc -o execfile file.c
```
To compile and run code for Nvidia and AMD GPU:
```
clang -fopenacc -fopenmp-targets=nvptx64-nvidia-cuda -o execfile file.c

clang -fopenacc -fopenmp-targets=amdgcn-amd-amdhsa -o execfile test.c
```
###### Executing the Code
To execute the compiled code, simply run the executable file:
```
./execfile
```

## Additional Resources

- The OpenACC website (https://www.openacc.org/) provides documentation on using the OpenACC programming model.
- GCC documentation[GCC OpenACC documentation](https://gcc.gnu.org/wiki/OpenACC)
- Nvidia documentation[NVIDIA OpenACC documentation](https://docs.nvidia.com/cuda/cuda-compiler-driver-nvc/index.html)
- Cray documentation[Cray OpenACC documentation](https://docs.cray.com/books/S-2489-51/html-S-2489-51/openacc.html)
- Clacc documentation[Clacc website](https://www.openacc.org/sites/default/files/inline-images/events/F2F20%20presentations/BoF-clacc.pdf)
- Cuda website [CUDA website](https://developer.nvidia.com/cuda-zone)
