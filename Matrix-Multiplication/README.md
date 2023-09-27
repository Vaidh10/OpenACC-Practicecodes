# Example Matrix multiplication
## From original [repo](https://github.com/wagnerb3/MatrixMultiplication)

Matrix multiplication is a mathematical operation that can become quite time consuming as the size of the matrices become larger. And as the matrices become very large, the operations can even become time consuming for computers. This is due to the fact that in order to complete the operation, each row of one matrix has to go through every column of a different matrix, multiply values, sum up those products, and add that value to a new matrix. One way to reduce the amount of time that computers use to produce the product of multiplying 2 matrices is to parallelize the process.

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