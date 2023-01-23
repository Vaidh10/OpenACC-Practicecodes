# Example Raytracer-Project
## From original [repo]

This program creates a ray that starts at the origin and goes in the positive z-direction, and a light that is positioned at the origin and has a white color. It then calculates the intensity of the light on the ray by taking the dot product of the normalized direction of the light and the normalized direction of the ray, and scales the color of the light by this intensity. Finally, it prints the resulting color.

In this example, I have added OpenACC data directive to copy the color array to the device and #pragma acc parallel loop directive before the nested for loops that iterate over the pixels. This tells the OpenACC compiler to parallelize the execution of these loops across multiple threads or processing units. This would allow the program to take advantage of the parallelism provided by the GPU or other accelerator, resulting in a faster execution.