# OpenACC-Practicecodes

Repository for OpenACC Example Programs 2022.

## Compile and Execute the benchmarks
Configure the build and run commands.

The Makefile supports different types of compilers. Enter the directory containing the program's name to compile it. such as cd Jacobi then use the nvc/gcc compiler to compile the parallel code.

1.To compile with Nvidia compiler
> make acc CC=nvc

To compile with GCC compiler
> make acc CC=gcc

2.And then enter: `make run`

## Authors and Acknowledgment

See Contributors for a list of contributors towards this repository.