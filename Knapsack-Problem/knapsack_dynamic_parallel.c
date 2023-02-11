#include <stdio.h>
#include <math.h>
#include <time.h>
#define getClock() ((double)clock() / CLOCKS_PER_SEC)
//Written using the Psuedocode given from "Different Approaches to Solve the 0/1 Knapsack Problem" by Maya Hristakeva and Dipti Shrestha
//http://www.micsymposium.org/mics_2005/papers/paper102.pdf
int knapsack(int W, int wt[], int val[], int n)
{
   int A[n+1];
   int i;
   long long max = pow(2,n);
   int best_value = 0;

   for (i = 0; i < max; i++)
   {
	int j = n;
	int temp_weight = 0;
	int temp_value = 0;
	while(A[j] !=0 && j>0){
		A[j]=0;
		j--;
	}
	A[j]=1;
        #pragma acc parallel loop reduction(max:best_value)
	for(int k=0; k<n; k++){
		if(A[k]==1){
			temp_weight = temp_weight+wt[k];
			temp_value = temp_value+val[k];
		}
	}
	if((temp_value > best_value) && (temp_weight <= W)){
		best_value = temp_value;
	}
   }

   return best_value;
}

int main()
{
    int val[] = {14,12,7,16,21,3,6,19,4,18}; //Data for 10 items...
    int wt[] = {3,5,2,6,4,9,10,1,3,8};
//  int val[] = {14,12,7,16,21,3,6,19,4,18,4,15,14,9,11,12,17,5,19,20}; //Data for 20 items...
//  int wt[] = {3,5,2,6,4,9,10,1,3,8,5,6,3,8,4,9,5,7,4,2};
    int  W = 25;
    int n = sizeof(val)/sizeof(val[0]); //n can not be greater then 32 or else max will not be able to hold 2^32+

    //Execution
    double time_start = getClock();
    int output = knapsack(W,wt,val,n);
    double time_finish = getClock();
    printf("\nValue = %d\nTime (s)= %.6f\n", output, time_finish - time_start);
    return 0;
}