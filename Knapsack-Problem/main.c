#include <stdio.h>
#include <time.h>
#include <omp.h>
#define getClock() ((double)clock() / CLOCKS_PER_SEC)
//Code base from "Sanfoundry Global Education & Learning Series" https://www.sanfoundry.com/c-program-solve-knapsack-problem-using-dynamic-programming/

int max(int a, int b) { return (a > b)? a : b; }
// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)//To avoid race conditions, I can't parallize the outer for loop due to the need to check the row above when calculating the current row
   {
	#pragma acc parallel loop
      	for (w = 0; w <= W; w++)//Can parallelize this for loop as each element in the current row can be calculated independently, don't need a modifier as each iteration only changes its own array location
      	{
        	if (i==0 || w==0)
               		K[i][w] = 0;
           	else if (wt[i-1] <= w)
                	K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           	else
                	K[i][w] = K[i-1][w];
	}
   }


   return K[n][W];
}

int main()
{
//    int val[] = {14,12,7,16,21,3,6,19,4,18}; //Data for 10 items
//    int wt[] = {3,5,2,6,4,9,10,1,3,8};
//  int val[] = {14,12,7,16,21,3,6,19,4,18,4,15,14,9,11,12,17,5,19,20} //Data for 20 items
//  int wt[] = {3,5,2,6,4,9,10,1,3,8,5,6,3,8,4,9,5,7,4,2}
//  int val[] = {26,2,5,17,48,47,38,21,32,48,37,8,43,12,34,18,36,35,13,9,23,19,1,13,34,47,37,32,35,42,22,16,23,47,2,28,7,24,18,25,39,1,19,46,1,12,44,9,15,42,47,10,33,12,32,38,26,34,21,32,40,37,49,22,50,40,24,17,37,3,1,27,39,5,12,8,34,26,11,13,16,1,10,13,15,6,27,48,42,29,17,24,24,11,25,6,27,44,19,9}; //100 value (1-50
//  int wt[] = {2,8,12,19,11,2,10,20,1,16,1,6,17,15,10,12,3,3,8,16,10,4,13,16,1,12,13,15,19,15,17,1,14,2,19,8,3,12,19,14,15,3,10,9,19,2,16,15,9,17,4,6,2,10,15,11,11,15,20,1,15,20,4,15,15,2,6,5,8,18,13,7,17,13,11,9,17,1,18,12,18,15,20,8,10,13,20,14,9,7,15,1,14,2,16,19,20,14,9,2}; //100 Weights (1-20)
  int val[] = {26,2,5,17,48,47,38,21,32,48,37,8,43,12,34,18,36,35,13,9,23,19,1,13,34,47,37,32,35,42,22,16,23,47,2,28,7,24,18,25,39,1,19,46,1,12,44,9,15,42,47,10,33,12,32,38,26,34,21,32,40,37,49,22,50,40,24,17,37,3,1,27,39,5,12,8,34,26,11,13,16,1,10,13,15,6,27,48,42,29,17,24,24,11,25,6,27,44,19,9,
               12,49,23,37,31,19,4,41,20,50,46,30,41,47,47,45,1,43,1,15,9,40,3,14,30,7,50,22,30,48,26,28,13,22,35,32,39,29,16,4,27,42,29,36,14,44,49,39,47,22,34,31,1,27,45,15,27,41,13,40,33,28,28,37,43,20,42,9,50,28,16,48,44,39,28,16,49,15,14,1,40,42,30,47,29,47,21,24,35,41,26,39,41,47,11,39,26,8,18,44};//200 values $   
  int wt[] = {2,8,12,19,11,2,10,20,1,16,1,6,17,15,10,12,3,3,8,16,10,4,13,16,1,12,13,15,19,15,17,1,14,2,19,8,3,12,19,14,15,3,10,9,19,2,16,15,9,17,4,6,2,10,15,11,11,15,20,1,15,20,4,15,15,2,6,5,8,18,13,7,17,13,11,9,17,1,18,12,18,15,20,8,10,13,20,14,9,7,15,1,14,2,16,19,20,14,9,2,
             15,13,18,19,19,15,18,14,14,2,15,8,1,5,20,16,6,10,8,16,5,15,3,9,9,11,1,10,16,17,4,7,16,12,8,2,4,3,8,19,9,18,1,1,14,19,5,18,16,9,2,14,4,4,15,7,18,11,12,6,17,16,4,15,13,13,11,16,2,18,17,3,3,18,7,7,16,19,4,14,11,3,8,1,18,5,5,17,3,19,4,11,12,19,13,8,11,7,5,6}; //200 Weights (1-20)
    int  W = 100000;
    int n = sizeof(val)/sizeof(val[0]);

    //Execution
    double time_start = getClock();
    int output = knapsack(W, wt, val, n);
    double time_finish = getClock();
    printf("\nValue = %d\nTime (s) = %.6f\n", output, time_finish - time_start);
    return 0;
}