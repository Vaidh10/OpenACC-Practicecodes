# Example Ray-Tracer

This code is a simple implementation of a ray tracer that renders a sphere and calculates the color of each pixel in an output image. The code is written in C++ and uses the OpenACC framework to enable parallelism on GPUs.

## Code explanation

The code is composed of several structs and functions that are used to define and manipulate the objects in the scene. The main structs are:

- Vec3: a struct that represents a 3D vector.
- Ray: a struct that represents a ray in 3D space.
- Sphere: a struct that represents a sphere in the scene.

The code also includes several helper functions, such as dot, clamp255, and intersect, which are used to perform calculations and manipulate the objects in the scene.The main function main() sets up the scene and uses a nested loop to calculate the color of each pixel in the output image. The outer loop iterates over the rows of the image, and the inner loop iterates over the columns of the image.

## References

Original serial code was found here https://github.com/MarcusMathiassen/BasicRaytracer30min.