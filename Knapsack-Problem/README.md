# Example Knapsack Problem

## Make benchmarks

Configure the build and run commands.
    * Enter the build command. A Makefile that uses the nvc compiler is provided. If you don't have Make or nvc, you can enter the compiler invocation directly. Otherwise :
        * For an OpenACC enabled code: `make acc`
    * And then enter: `make run`

## From original [repo](https://github.com/bdelled/Parallel_Project)

This code attempts to parallelize the Knapsack Problem What is the Knapsack Problem? It is an optimazation problem in which you take a set of items, each with a given value and weight, and determine what is the highest value combination of items that can be placed in a knapsack that has a set weight maximum. The two solutions that are attempted to be parallelized are a Brute-Force Solution and a Dynamic Programming Solution and the parallelization software used is OpenACC

## REQUIREMENTS

NVIDIA HPC SDK COMPILER 21.7 or Greater
OpenACC
Multicore System with CPU