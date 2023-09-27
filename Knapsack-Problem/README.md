# Knapsack Problem with OpenACC
## From original [repo](https://github.com/bdelled/Parallel_Project)

This code attempts to parallelize the Knapsack Problem What is the Knapsack Problem? It is an optimazation problem in which you take a set of items, each with a given value and weight, and determine what is the highest value combination of items that can be placed in a knapsack that has a set weight maximum. The two solutions that are attempted to be parallelized are a Brute-Force Solution and a Dynamic Programming Solution and the parallelization software used is OpenACC

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
./exec
```

To clean up and remove the compiled executable, use the following command:

```bash
make clean
```
