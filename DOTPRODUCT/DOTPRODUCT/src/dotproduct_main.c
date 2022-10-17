#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

double dotproduct(double* v, double* u, int n);

// --- Basic timer function ---------------------------------------------------

#ifdef _OPENMP
#include <omp.h>
#define getClock() omp_get_wtime()
#else
#include <time.h>
#define getClock() ((double)clock() / CLOCKS_PER_SEC)
#endif

// --- Launcher function ------------------------------------------------------

int main(int argc, char* argv[])
{

    // Reads the test parameters from the command line
    double arg_n = 0.0;
    int param_iters = 1;
    if (argc >= 2)
        sscanf(argv[1], "%lf", &arg_n);
    if (argc >= 3)
        param_iters = atoi(argv[2]);

    if (arg_n < 1 || arg_n >= INT_MAX || param_iters < 1) {
        printf("This test performs the vector operation 'D=V[i]*U[i]'\n");
        printf("  The first parameter <n> is the desired test size.\n");
        printf("  The optional parameter [iters] is used to repeat the test several times.\n");
        printf("Usage: %s <n> [iters] \n", argv[0]);
        exit(0);
    }

    // Allocates input  resources
    int param_n = (int)arg_n;
    Vector* inV_vec = Vector_new(param_n);
    Vector* inU_vec = Vector_new(param_n);
    if (!inV_vec || !inU_vec) {
        printf("Error: Not enough memory to run the test using n = %i\n", param_n);
        exit(0);
    }

    // Initializes data
    Vector_rand(inV_vec);
    Vector_rand(inU_vec);
    double outD = 0;

    // Calls the function that performs the actual computation
    printf("- Executing test...\n");
    double time_start = getClock();
    // ================================================

    for (int iters = 0; iters < param_iters; iters++) {
        outD = dotproduct(
            Vector_getData(inV_vec),
            Vector_getData(inU_vec),
            param_n);
    }

    // ================================================
    double time_finish = getClock();

    // Prints an execution report
    printf("time (s)= %.6f\n", time_finish - time_start);
    printf("size\t= %i\n", param_n);
    if (param_iters > 1)
        printf("iters\t= %i\n", param_iters);

    if (param_n < 7) { // Show example for small problems
        printf("\n- Input vector X:\n");
        Vector_print(inV_vec);
        printf("\n- Input vector Y:\n");
        Vector_print(inU_vec);
        printf("\n- Output scalar D:\n");
        printf("%f\n", outD);
    }

    // Release allocated resources
    Vector_delete(inV_vec);
    Vector_delete(inU_vec);

    return 0;
}
