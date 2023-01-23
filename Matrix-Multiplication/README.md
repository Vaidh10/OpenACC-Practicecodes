# Example Matrix multiplication

This code multiplies two matrices first and second of dimensions DIM x DIM using OpenMP and OpenACC directives to achieve parallelization. The resulting matrix is stored in multiply. The code also calculates and prints the time taken to perform the multiplication.

The code starts by including the necessary headers stdio.h and omp.h.A macro DIM is defined with the value 3000, which represents the dimensions of the matrices.In the main function, the time at the start of the multiplication is stored in the variable begin using the function omp_get_wtime().Three nested loops are used to perform the matrix multiplication, with each loop parallelized using OpenACC directives #pragma acc parallel loop, #pragma acc loop worker, and #pragma acc loop vector respectively.The resulting matrix is stored in the multiply matrix.The time at the end of the multiplication is stored in the variable end using the function omp_get_wtime().The code then prints the time taken to perform the multiplication by calculating end-begin.

## From original [repo](https://github.com/wagnerb3/MatrixMultiplication)

Matrix multiplication is a mathematical operation that can become quite time consuming as the size of the matrices become larger. And as the matrices become very large, the operations can even become time consuming for computers. This is due to the fact that in order to complete the operation, each row of one matrix has to go through every column of a different matrix, multiply values, sum up those products, and add that value to a new matrix. One way to reduce the amount of time that computers use to produce the product of multiplying 2 matrices is to parallelize the process.

## Installation

- To Run Serial Code
  - At least one of the compilers will need to be installed.
- To Run Parallel Code
  - At least one of the APIs will need to be configured on your system
- To Profile Code
  - The NVIDIA software will need to be downloaded from NVIDIA's website