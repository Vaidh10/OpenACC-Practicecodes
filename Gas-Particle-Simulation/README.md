# Example Gas Particle Simulation

## Make benchmarks

Configure the build and run commands.
    * Enter the build command. A Makefile that uses the nvc compiler is provided. If you don't have Make or nvc, you can enter the compiler invocation directly. Otherwise :
        * For an OpenACC enabled code: `make acc`
    * And then enter: `make run`

## From original [repo](https://github.com/spoduminister/372Project)

This project contains the parallelized code of a handwritten gas particle simulation. The simulation generates a frame-by-frame collection of bitmap images as an output.