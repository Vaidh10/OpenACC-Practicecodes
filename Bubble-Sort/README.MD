# BubbleSort in C

This is an implementation of the bubble sort algorithm in C, parallelized using OpenACC.

The code contains the following functions:

swap() - a function to swap the values of two integers
bubbleSort() - the main sorting function, which takes an array and its size as input and sorts the array using the bubble sort algorithm
printArray() - a function to print the contents of an array
main() - the program's entry point, where the dataset is read from a file, the sorting is performed, and the sorted array and sorting time are printed
The bubbleSort() function is parallelized using OpenACC, with the data clause specifying that the memory location of the array should be copied to the device, and the parallel loop and loop clauses specifying that the nested for loops should be executed in parallel.