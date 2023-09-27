# Example Ray-Tracer
## From original [repo](https://github.com/AKenney31/Raytracer_project)

This is our parallel programming project in which we have to use real world serial code and attempt to parallelize it. The project we chose to try is a raytracer. Raytracing is a basic method to create 3 dimensional graphics. It works by shooting rays out into a scene and if it makes contact with an object in the scene, it calculates what shade the pixel should be based on the position of the lightsource. We made an orthographic raytracer, meaning that it shoots a ray straight out in the z direction from each pixel in the window. This is less efficient than using the camera approach to this problem when you shoot rays out from a camera's point of view. The orthographic approach is better suited for our project because it is effected by the size of the window. So we start with 800 X 800 which performs pretty well, and then we bump the window size to 10000 X 10000 to see how the serial version will perform compared to the parallel version. Keep in mind that on the 10000 X 10000 version, you will not be able to view the ppm file, but it will still run all the way and produce an output so we can still measure it's performance. The parallel version was made using openmp to paralellize over CPUs. We ran the code on the supercomputer Bridges 2 located in Pennsylvania.

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