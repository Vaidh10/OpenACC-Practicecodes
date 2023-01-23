# Example Gas Particle Simulation

## From original [repo]

The above code uses the OpenACC pragmas to indicate which loops should be parallelized. The kernels pragma is used to indicate that the simulate function should be executed on the accelerator, and the parallel pragma is used to indicate that the loops in the main function should be parallelized.

You can run this code on a system with an accelerator (e.g. a GPU) by compiling it with an OpenACC compiler, such as the NVIDIA CUDA compiler (nvc) and run the executable.