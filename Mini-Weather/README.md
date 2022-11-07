# Example Mini Weather


## Make benchmarks

Configure the build and run commands.
    * Enter the build command. A Makefile that uses the nvc compiler is provided. If you don't have Make or nvc, you can enter the compiler invocation directly. Otherwise :
        * For an OpenACC enabled code: `make acc`
    * And then enter: `make run`

## From original [repo](https://github.com/jrreap/miniweather)

A paralleized version of the MiniWeather app for high performance computing. Built off the sample code found here. This program simulates "weather" patterns in an approachable format. Produces viewable netCDF files to visualize the data better.

## Requirements
This requires you to install the required modules. Simply run module load openmpi/4.0.5-nvhpc21.7 parallel-netcdf on bridges