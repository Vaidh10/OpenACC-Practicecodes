// serial version created by James Villemarette for CISC 372, Fall 2021
// version 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define default_solve 51
#define default_report_after 50
#define iter_max 5000

/**
 * On a GTX1080 NVIDIA GPU I'm seeing 0.01 seconds to solve 51.
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
 * (-a) + b    + (-c)
 * (-a) + (-b) + (-c)
 * 
 * Exits the program when a solution is found.
 */

long gettime() {
    gettimeofday(&timecheck, NULL);
    return (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
}

/* GPU NOTE
 * When you call another function from within a parallel region,
 * that function also needs to be compiled into GPU code.
 * The "routine" directive tells the compiler to do just that.
 * Sometimes the compiler can figure it out without the directive,
 * it's hit or miss. You can also specify parallelism within
 * these functions, but in this function specifically there
 * are no loops I could parallelize, so I tell the compiler
 * that this function should run as "seq".
 *
 * Also, GPUs do not like branching statements in the code.
 * I'm sure there is some super clever way to write this
 * function without any branching, but I can't figure
 * out how to do it.
 * However, originally the code checked every possible
 * combination of +'s and -'s, but that isn't really
 * neccessary. For example if:
 *  A - B - C = -S  then
 * -A + B + C = S
 * So in order to do less computation (and less branching)
 * I am only checking half of the possible combinations and
 * taking the absolute value of everything. A GPU would
 * much rather do an absolute value rather than a branch.
 * (CPUs probably would too, idk)
 */

#pragma acc routine seq
int check(int a, int b, int c, int s) {
    double da = pow((double)a, 3.0);
    double db = pow((double)b, 3.0);
    double dc = pow((double)c, 3.0);

    if(da + db + dc == s) {
        return 1;
    } else if(abs((-da) + db + dc) == s) {
        return 1;
    } else if(abs(da + (-db) + dc) == s) {
        return 1;
    } else if(abs(da + db + (-dc)) == s) {
        return 1;
    } else {
        return 0;
    }
}

void printsolution(int a, int b, int c) {
    printf("Solution found for %d\n", solve);
    printf("a=%d, b=%d, c=%d\n", a, b, c);
}


int main(int argc, char *argv[]) {

    int report = 1; // Keep track of how many reports are printed
    int iter = 0;

    int prev_v = 1; // Avoid rechecking values that were already checked
    int v = 0; // Current max to check up to

    int a_sol, b_sol, c_sol; // Record solution
    int finished = 0; // Check when done

    long tic, toc;

    if(argc <= 1) {
        printf("No arguments were passed.  Assuming default solve of 51.\n");
    } else {
        if(argc == 2) {
            solve = atoi(argv[1]);
        } else if(argc == 3) {
            solve = atoi(argv[2]);
            report_after = atoi(argv[3]);
        }
        solve = abs(solve); // This is to make my check function work on
                            // negative numbers.
    }

    #pragma acc init

    printf("Solving sum of cubes for %d\n", solve);

    tic = gettime();

    while(!finished && iter < iter_max) {

        /* GPU NOTE
	 * The way this was done on the CPU was that each value was only
	 * ever incremented by 1. Meaning that you do a little bit of work,
	 * check if you need to report, do a little bit of work, check if
	 * you need to report, etc etc.
	 * There is an overhead whenever you run code on the GPU. Typically,
	 * this overhead is very small compared to the time the GPU is saving you.
	 * However, if you keep sending work to the GPU in very small increments,
	 * then that overhead will likely be a lot worse. So, instead I decided
	 * to send the work to the GPU in large chunks. This means that I might
	 * end up doing unnecessary computation if the solution is found in the
	 * middle of one of these chunks, but it will still be much faster for the
	 * GPU to do extra work than if it were stopping and starting all of the time.
	 */
        v += report_after;

        /*
	 * The way that the code checked for values was extremely inefficient.
	 * Since you are checking all possible +/- combinations, then the
	 * order that the values appear in does not matter. For example if:
	 * (1,2,3) was not a correct solution, then
	 * (3,1,2) will not be either.
	 *
	 * These loops are written in the very specific way to accomplish that.
	 * Basically:
	 * a: chunk_start -> chunk_end
	 * b: 1 -> a
	 * c: 1 -> b
	 *
	 * Writing a GPU code to do loops like that is actually pretty
	 * finnicky. If you're curious why these loops have to be
	 * written this way, bug Sunita and she'll probably have you
	 * ask me directly.
	 */
        #pragma acc parallel loop gang
        for(int a = prev_v; a <= v; a++) {
            #pragma acc loop worker
            for(int b = 1; b <= a; b++) {
                #pragma acc loop vector
                for(int c = 1; c <= b; c++) {
                    if(check(a,b,c,solve)){
                        /* GPU NOTE
			 * The original code force exitted the code when
			 * a solution was found. You can't do that
			 * in GPU code. So instead, I have to record
			 * my answers and check after the GPU is done
			 * executing. Recording the answers could result
			 * in a race-condition, so I write their values
			 * with atomic operations. I do 4 seperate atomics
			 * here because OpenACC does not support "critical"
			 * like OpenMP does.
			 */
                        #pragma acc atomic write
                            a_sol = a;
                        #pragma acc atomic write
                            b_sol = b;
                        #pragma acc atomic write
                            c_sol = c;		
                        #pragma acc atomic write
                            finished = 1;
                    }
                }				
            }
        }

        prev_v = v+1;

        toc = gettime();

        iter += report_after;
        printf(
            "Report #%d: a=%d, b=%d, c=%d, time=%.4f seconds\n", 
            report, v, v, v, ((double)(toc - tic)) / 1000.0
        );
        report += 1;

    }

    //printsolution(a_sol, b_sol, c_sol);

    return 0;

}

