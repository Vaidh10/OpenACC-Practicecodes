# Example Dijkstra's Algorithm

This code implements the Dijkstra algorithm for finding the shortest path between a start node and all other nodes in a weighted graph represented as an adjacency matrix G. The graph has n vertices and the start node is specified by the variable startnode. The code uses OpenACC to parallelize the computation and the timer.h header file to measure the execution time.

## Code explanation

1. The code starts by including the necessary headers stdio.h, timer.h, stdlib.h, and openacc.h.
2. The function dijkstra(int G[MAX][MAX], int n, int startnode) is defined to find the shortest path from the startnode to all other nodes in the graph G with n vertices.
3. In the main function, an adjacency matrix G of dimensions MAX x MAX is created and filled with random values.
4. The variable n is set to 15000 and the variable startnode is set to 0.
5. The dijkstra() function is called with the G, n and startnode as arguments.
6. The execution time for the Dijkstra algorithm is measured using the StartTimer() and GetTimer() functions from the timer.h header file, and the result is printed using printf(" total: %f s\n", runtime / 1000);.
7. The code uses the OpenACC data directive to copy the G matrix to the accelerator and create the cost, distance, pred, and visited arrays on the accelerator.
8. The code uses the OpenACC kernels directive to specify the computation that will be done by the GPU.

Note: Make sure to check the OpenACC version compatability with your system before running the code. Also make sure that the timer.h is included in the path where the code is located.

## From original [repo](https://github.com/Yongye12/CISC372-Project)

Modified by : Vaidhy