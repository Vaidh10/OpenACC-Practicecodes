# Example Matrix multiplication

## Make benchmarks

Configure the build and run commands.
    * Enter the build command. A Makefile that uses the nvc compiler is provided. If you don't have Make or nvc, you can enter the compiler invocation directly. Otherwise :
        * For an OpenACC enabled code: `make acc`
    * And then enter: `make run`

## From original [repo](https://github.com/wagnerb3/MatrixMultiplication)

Matrix multiplication is a mathematical operation that can become quite time consuming as the size of the matrices become larger. And as the matrices become very large, the operations can even become time consuming for computers. This is due to the fact that in order to complete the operation, each row of one matrix has to go through every column of a different matrix, multiply values, sum up those products, and add that value to a new matrix. One way to reduce the amount of time that computers use to produce the product of multiplying 2 matrices is to parallelize the process.

## Installation

- To Run Serial Code
  - At least one of the compilers will need to be installed.
- To Run Parallel Code
  - At least one of the APIs will need to be configured on your system
- To Profile Code
  - The NVIDIA software will need to be downloaded from NVIDIA's website