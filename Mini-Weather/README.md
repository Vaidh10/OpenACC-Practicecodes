# Example Newton Mini Weather
## From original [repo](https://github.com/mrnorman/miniWeather/)

A mini app simulating weather-like flows for training in parallelizing accelerated HPC architectures. Currently includes:
* MPI (C, Fortran, and C++)
* OpenACC Offload (C and Fortran)
* OpenMP Threading (C and Fortran)
* OpenMP Offload (C and Fortran)
* C++ Portability
  * CUDA-like approach
  * https://github.com/mrnorman/YAKL/wiki/CPlusPlus-Performance-Portability-For-OpenACC-and-OpenMP-Folks
  * C++ code works on CPU, Nvidia GPUs (CUDA), and AMD GPUs (HIP)

Author: Matt Norman, Oak Ridge National Laboratory, https://mrnorman.github.io

Contributors:
* Matt Norman (ORNL)
* Jeff Larkin (Nvidia)
* Isaac Lyngaas (ORNL)

## Build Instructions

To compile the code with a specific target, use one of the following commands:

    - For GCC with GPU target (OpenACC):
        ```bash
        export ACC_DEVICE_TYPE=nvidia|radeon
        make gcc_gpu
        ```

    - For GCC without GPU offloading:
        ```bash
        export ACC_DEVICE_TYPE=host
        make gcc_serial
        ```

    - For NVC with NVIDIA Tesla GPU target:
        ```bash
        make nvc_gpu
        ```

    - For NVC with multicore CPU target:
        ```bash
        export ACC_NUM_THREADS=4|8|16
        make nvc_multicore
        ```

    - For NVC targeting the host CPU:
        ```bash
        make nvc_serial
        ```

After running one of the above commands, the executable file (e.g., `gcc_gpu`) will be generated in the same directory.


To run the executable with a specified command (e.g., `./nvc_gpu`), use the following command:

```bash
./nvc_gpu
```

To clean up and remove the compiled executable, use the following command:

```bash
make clean
```
