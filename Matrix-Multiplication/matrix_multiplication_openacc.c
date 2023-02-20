#include <stdio.h>
#include <omp.h>
#define DIM 3000 
#include "timer.h"

int main()
{
  StartTimer();
  int c, d, k, sum = 0;
  int first[DIM][DIM], second[DIM][DIM], multiply[DIM][DIM];
 
#pragma acc parallel loop gang  
  for ( c = 0 ; c < DIM-1 ; c++ )
    {
#pragma acc loop worker
      for ( d = 0 ; d < DIM-1 ; d++ )
      {
        
#pragma acc loop vector
	      for ( k = 0 ; k < DIM-1 ; k++ )
        {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
  printf("%d",multiply[0][0]);
  double runtime = GetTimer();
  printf(" total: %f s\n", runtime / 1000);
  return 0;
}