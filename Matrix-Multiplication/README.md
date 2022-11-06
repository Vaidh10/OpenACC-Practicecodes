# Matrix Multiplication Parallelization

Parallelization of multiplying matrices

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Recommended Modules](#recommended-modules)
- [Installation](#installation)
- [Configuration](#configuration)
- [Maintainers](#maintainers)

## Introduction

Matrix multiplication is a mathematical operation that can become quite time consuming as the size of the matrices become larger. And as the matrices become very large, the operations can even become time consuming for computers. This is due to the fact that in order to complete the operation, each row of one matrix has to go through every column of a different matrix, multiply values, sum up those products, and add that value to a new matrix. One way to reduce the amount of time that computers use to produce the product of multiplying 2 matrices is to parallelize the process.

## Requirements

- [OpenMP](https://www.openmp.org/) API
- [OpenACC](https://www.openacc.org/) API
- [NVHPC SDK](https://developer.nvidia.com/hpc-sdk) NVC Compiler
- [GCC](https://gcc.gnu.org/) Compiler
- If you plan to target a GPU, a GPU is required on your system

## Recommended Modules
- [NVIDIA NSight Compute](https://developer.nvidia.com/nsight-compute) and [NVIDIA NSight Systems](https://developer.nvidia.com/nsight-systems) for profiling.

## Installation

- To Run Serial Code
  - At least one of the compilers will need to be installed.
- To Run Parallel Code
  - At least one of the APIs will need to be configured on your system
- To Profile Code
  - The NVIDIA software will need to be downloaded from NVIDIA's website

## Configuration

The only necessary configuration needed is to have a compiler that can handle OpenMP or OpenACC.

## Maintainers

- Brett Wagner - University of Delaware Student
- Dontae Esdaile - University of Delaware Student