# Gas Particle Simulation

This code is a simple simulation that updates the position and velocity of N particles. The program uses OpenACC to parallelize the computation and accelerate the execution of the simulation.

## Functionality

The `simulate` function updates the position and velocity of each particle by iterating over an array of size `n` with a for loop. The loop is parallelized using the OpenACC `kernels` directive and the `loop independent` clause. This tells the compiler to generate code that can be executed concurrently on multiple threads or accelerators, such as a GPU.

The `main` function initializes the position and velocity arrays, calls the `simulate` function to update the particle state, and then prints the final position and velocity of each particle. The initialization and printing are also parallelized using the OpenACC `parallel` directive and the `loop independent` clause.

## Requirements

- The `stdio.h` and `openacc.h` headers are included to provide the standard input/output and OpenACC functions used in the code.
- To run this code, you need a system with OpenACC support and a compatible compiler.