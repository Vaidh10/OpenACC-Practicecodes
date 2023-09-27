# Example Jacobi

This Code provides the jacobi relaxation method to solve the 2D Laplace equation.

## Build Instructions

To compile the code with a specific target, use one of the following commands:

- For GCC with GPU target (OpenACC):
```  
$ export ACC_DEVICE_TYPE=nvidia|radeon

$ make gcc_gpu
```

- For GCC without GPU offloading:
```
$ export ACC_DEVICE_TYPE=host

$ make gcc_serial
```

- For NVC with NVIDIA Tesla GPU target:
```
$ make nvc_gpu
```

- For NVC with multicore CPU target:
```
$ export ACC_NUM_THREADS=4|8|16

$ make nvc_multicore
```

- For NVC targeting the host CPU:
```
make nvc_serial
```

After running one of the above commands, the executable file (e.g., `gcc_gpu`) will be generated in the same directory.


To run the executable with a specified command (e.g., `./nvc_gpu`), use the following command:

```
./nvc_gpu
```

To clean up and remove the compiled executable, use the following command:

```
make clean
```