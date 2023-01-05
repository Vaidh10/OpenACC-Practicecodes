#include <stdio.h>
#include <omp.h>
#define DIM 3000 
int main()
{
	double begin, end;
	begin = omp_get_wtime();
  int c, d, k, sum = 0;
  int first[DIM][DIM], second[DIM][DIM], multiply[DIM][DIM];
 
#pragma acc parallel loop gang  
  for ( c = 0 ; c < DIM ; c++ )
    {
#pragma acc loop worker
      for ( d = 0 ; d < DIM ; d++ )
      {
        
#pragma acc loop vector
	      for ( k = 0 ; k < DIM ; k++ )
        {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
    end = omp_get_wtime();
    printf("TIME PASSED = %.2f seconds\n", end-begin);
  return 0;
}