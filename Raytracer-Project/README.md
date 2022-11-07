# Example Raytracer-Project

## Make benchmarks

Configure the build and run commands.
    * Enter the build command. A Makefile that uses the nvc compiler is provided. If you don't have Make or nvc, you can enter the compiler invocation directly. Otherwise :
        * For an OpenACC enabled code: `make acc`
    * And then enter: `make run`

## From original [repo](https://github.com/AKenney31/Raytracer_project)

Raytracing is a basic method to create 3 dimensional graphics. It works by shooting rays out into a scene and if it makes contact with an object in the scene, it calculates what shade the pixel should be based on the position of the lightsource. We made an orthographic raytracer, meaning that it shoots a ray straight out in the z direction from each pixel in the window. This is less efficient than using the camera approach to this problem when you shoot rays out from a camera's point of view. The orthographic approach is better suited for our project because it is effected by the size of the window. So we start with 800 X 800 which performs pretty well, and then we bump the window size to 10000 X 10000 to see how the serial version will perform compared to the parallel version. Keep in mind that on the 10000 X 10000 version, you will not be able to view the ppm file, but it will still run all the way and produce an output so we can still measure it's performance. The parallel version was made using openmp to paralellize over CPUs. We ran the code on the supercomputer Bridges 2 located in Pennsylvania.

## Experimental Steps
Build serial code that renders a couple of spheres on a 800x800 pixel window. Then attempt to parallelize the code to the best of our ability.
We parallelize using openmp
In the code we time the code using time.h, and output this in the console
Once we have recorded the time for the serial and parallel code, and prove that the rendered image is the same, we will bump the window size to 10000x10000 pixels and repeat We will record the times for the parallel version using 2, 4, 8, 16 cores.