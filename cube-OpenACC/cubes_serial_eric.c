// serial version created by James Villemarette for CISC 372, Fall 2021
// version 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#define default_solve 51
#define default_report_after 50
#define max_iter 5000

/**
 * I found it took me ~60 seconds for one of my four cores to solve 51.
 */ 

int solve = default_solve;
int report_after = default_report_after;

struct timeval timecheck;

/**
 * https://en.wikipedia.org/wiki/Sums_of_three_cubes#Computational_results
 * 
 * This code solves the sum of three cubes problem.
 *      x^3 + y^3 + z^3 = k
 * or as we'll be using it
 *      a^3 + b^3 + c^3 = solve 
 *      (because it's easier to visually differentiate a & c vs x & y)
 * 
 * k is trivial to solve in some cases.
 * Say k = 8,
 *      x^3 + y^3 + z^3 => 1^3 + (-1)^3 + 2^3 = 8
 * 
 * But for k = 42 and k = 33, they were only solved in 2019 by supercomputers.
 * 
 * Parallelize this code.
 */

/**
 * Check all possible combinations for the solve.
 * 
 * All possible combinations
 * (-a) + b    + c
 * a    + (-b) + c
 * a    + b    + (-c)
 * (-a) + (-b) + c
 * a    + (-b) + (-c)
 * (-a) + (-b) + (-c)
 * 
 * Exits the program when a solution is found.
 */

long gettime() {
    gettimeofday(&timecheck, NULL);
    return (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
}

int check(int a, int b, int c) {
    double da = pow((double)a, 3.0);
    double db = pow((double)b, 3.0);
    double dc = pow((double)c, 3.0);
    return
        da    + db    + dc    == solve ||
        (-da) + db    + dc    == solve ||
        da    + (-db) + dc    == solve ||
        da    + db    + (-dc) == solve ||
        (-da) + (-db) + dc    == solve ||
        da    + (-db) + (-dc) == solve ||
        (-da) + db    + (-dc) == solve ||
        (-da) + (-db) + (-dc) == solve;
}

void printsolution(int a, int b, int c) {
    printf("Solution found for %d\n", solve);
    printf("a=%d, b=%d, c=%d\n", a, b, c);
}

int main(int argc, char *argv[]) {

    // setup
    long tic, toc;

    int a = 0;
    int b = 0;
    int c = 0;

    int report = 1;
    int iter = 0;

    if(argc <= 1) {
        printf("No arguments were passed.  Assuming default solve of 51.\n");
    } else {
        if(argc == 2) {
            solve = atoi(argv[1]);
        } else if(argc == 3) {
            solve = atoi(argv[2]);
            report_after = atoi(argv[3]);
        }
    }

    printf("Solving sum of cubes for %d\n", solve);

    tic = gettime();

    while(iter < max_iter) {

        a += 1;
        for(int t_b = b; t_b > 0; t_b--)
            for(int t_c = c; t_c > 0; t_c--)
                if(check(a, t_b, t_c)) {
                    printsolution(a, t_b, t_c);
                    return 0;
                }

        b += 1;
        for(int t_a = a; t_a > 0; t_a--)
            for(int t_c = c; t_c > 0; t_c--)
                if(check(t_a, b, t_c)) {
                    printsolution(t_a, b, t_c);
                    return 0;
                }
        
        c += 1;
        for(int t_a = a; t_a > 0; t_a--)
            for(int t_b = b; t_b > 0; t_b--)
                if(check(t_a, t_b, c)) {
                    printsolution(t_a, t_b, c);
                    return 0;
                }
        
        toc = gettime();

        iter += 1;
        if( iter % report_after == 0 ) {
            printf(
                "Report #%d: a=%d, b=%d, c=%d, time=%.4f seconds\n", 
                report, a, b, c, (double)(toc - tic) / 1000.0
            );
            report += 1;
        }

    }

    return 0;

}
