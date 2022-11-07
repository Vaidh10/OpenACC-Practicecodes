# Example Newton fractals 

## Make benchmarks

Configure the build and run commands.
    * Enter the build command. A Makefile that uses the nvc compiler is provided. If you don't have Make or nvc, you can enter the compiler invocation directly. Otherwise :
        * For an OpenACC enabled code: `make acc`
    * And then enter: `make run`

## From original [repo](https://github.com/rdean-udel/CISC372-Project)

Newton fractals are fractals generated by coloring each point in the complex plane based on which root it converges to when using Newton's rootfinding method. The program is set to generate the fractal for the function f(z) = z^3 - 1, and the amount of points that converge to each of the three roots, or do not converge at all are counted. The serial version of the code is based on code by Mitch Richling (https://www.mitchr.me/SS/newton/index.html) and is parallelized using both OpenMP and OpenACC. Code timing is done using timing code provided by Professor Chandrasekaran.