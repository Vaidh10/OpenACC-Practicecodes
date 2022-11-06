#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "openacc.h"

#define pi 3.14159265359

int main(void) {
	int   MaxCount = 1000;
	int   xMin = -2;
	int   xMax = 2;
	int   yMin = -2;
	int   yMax = 2;
	int   steps = 5000; //NOTE: Runs steps^2 steps, represents steps done in real and imaginary axes

	float Tol = .0001;
	double complex  r1 = 1 + 0*I;
	double complex  r2 = -0.5 + sin(2 * pi / 3)*I;
	double complex  r3 = -0.5 - sin(2 * pi / 3)*I;
	int root1 = 0, root2 = 0, root3 = 0, noRoot = 0;
	StartTimer();
	
	#pragma acc data copy(root1, root2, root3, noRoot)
	{
	#pragma acc parallel
	{
	#pragma acc loop reduction(+:root1, root2, root3, noRoot)
	for (int y = 0; y < steps; y++) {
		for (int x = 0; x < steps; x++) {
			double complex z = (xMin + (xMax - xMin) * 1.0 * x / (steps - 1)) + (yMin + (yMax - yMin) * 1.0 * y / (steps - 1)) * I;
			int  count = 0;
			while ((count < MaxCount) && cabs(z - r1) >= Tol && cabs(z - r2) >= Tol && cabs(z - r3) >= Tol) {
				if (cabs(z) > 0) {
					z = z - (z*z*z - 1.0) / (z*z*3.0); //change fraction to desired function divided by its derivative to change fractal function
				}
				count++;
			}

			if (cabs(z - r1) < Tol && abs(cimag(z)) < Tol) {
				root1++;
			}
			else if (cabs(z - r2) <= Tol && cimag(z) > -Tol) {
				root2++;
			}
			else if (cabs(z - r3) <= Tol && cimag(z) < Tol) {
				root3++;
			}
			else {
				noRoot++;
			}
		}
	}
	} 
	}
	double runtime = GetTimer();

	printf("Newton Fractal for %d points:\n", steps * steps);
	printf("Points that converged to no roots : %d (%.2f%%)\n", noRoot, 100.0 * noRoot / (steps * steps));
	printf("Points that converged to root %.2f + %.2fi: %d (%.2f%%)\n", creal(r1), cimag(r1), root1, 100.0 * root1 / (steps * steps));
	printf("Points that converged to root %.2f + %.2fi: %d (%.2f%%)\n", creal(r2), cimag(r2), root2, 100.0 * root2 / (steps * steps));
	printf("Points that converged to root %.2f + %.2fi: %d (%.2f%%)\n", creal(r3), cimag(r3), root3, 100.0 * root3 / (steps * steps));
	printf("Time taken: %f s\n", runtime / 1000);
}