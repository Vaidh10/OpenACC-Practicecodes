# Example Cubes: This code solves the sum of three cubes problem.
      x^3 + y^3 + z^3 = k

## This code solves the sum of three cubes problem.
 https://en.wikipedia.org/wiki/Sums_of_three_cubes#Computational_results
 
     x^3 + y^3 + z^3 = k
or as we'll be using it
     a^3 + b^3 + c^3 = solve 
     (because it's easier to visually differentiate a & c vs x & y)
 
k is trivial to solve in some cases.
Say k = 8,
    x^3 + y^3 + z^3 => 1^3 + (-1)^3 + 2^3 = 8
 
But for k = 42 and k = 33, they were only solved in 2019 by supercomputers.
 
Parallelize this code.

Check all possible combinations for the solve.
 
All possible combinations
(-a) + b    + c
a    + (-b) + c
a    + b    + (-c)
(-a) + (-b) + c
a    + (-b) + (-c)
(-a) + b    + (-c)
(-a) + (-b) + (-c)
 
Exits the program when a solution is found.


## GPU NOTE
When you call another function from within a parallel region,
that function also needs to be compiled into GPU code.
The "routine" directive tells the compiler to do just that.
Sometimes the compiler can figure it out without the directive,
it's hit or miss. You can also specify parallelism within
these functions, but in this function specifically there
are no loops I could parallelize, so I tell the compiler
that this function should run as "seq".

Also, GPUs do not like branching statements in the code.
I'm sure there is some super clever way to write this
function without any branching, but I can't figure
out how to do it.
However, originally the code checked every possible
combination of +'s and -'s, but that isn't really
neccessary. For example if:
 A - B - C = -S  then
-A + B + C = S
So in order to do less computation (and less branching)
I am only checking half of the possible combinations and
taking the absolute value of everything. A GPU would
much rather do an absolute value rather than a branch.

## OpenACC Compilation and Execution Guide

This guide will show you how to compile and execute OpenACC code individually for different compilers, without using CMake.

###### Prerequisites

- A computer with a GPU
- An OpenACC compiler, such as PGI, NVIDIA, or Cray

###### Compiling with PGI
To compile OpenACC code using the PGI compiler, use the following command:
```bash
pgcc -acc -Minfo=accel file.c -o execfile
```
###### Compiling with NVIDIA
To compile OpenACC code using the NVIDIA compiler, use the following command:
```
nvcc -arch=sm_35 -acc -Xptxas -dlcm=ca -o execfile file.c
```
###### Compiling with Cray
To compile OpenACC code using the Cray compiler, use the following command:

```
cc -h acc -o execfile file.c
```
###### Executing the Code
To execute the compiled code, simply run the executable file:
```
./execfile
```
