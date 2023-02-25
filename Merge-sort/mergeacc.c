/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define getClock() ((double)clock()/CLOCKS_PER_SEC)
double begin,end;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]

void merge(int arr[], int l, int m, int r)
{

    int i, j, k;

    int n1 = m - l + 1;

    int n2 = r - m;



    /* create temp arrays */

    int L[n1], R[n2];



    /* Copy data to temp arrays L[] and R[] */

    #pragma acc kernels num_gangs(8)
    for (i = 0; i < n1; i++)

        L[i] = arr[l + i];

    #pragma acc kernels num_gangs(8)
    for (j = 0; j < n2; j++)

        R[j] = arr[m + 1 + j];



    /* Merge the temp arrays back into arr[l..r]*/

    i = 0; // Initial index of first subarray

    j = 0; // Initial index of second subarray

    k = l; // Initial index of merged subarray
   #pragma acc kernels num_gangs(8)
    for(i,j; i<n1 && j <n2;){
    //while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {

            arr[k] = L[i];

            i++;

        }

        else {

            arr[k] = R[j];

            j++;

        }

        k++;

    }



    /* Copy the remaining elements of L[], if there

    are any */
   #pragma acc kernels num_gangs(8)
    for (i;i<n1;i++){


    //while (i < n1) {

        arr[k] = L[i];

       // i++;

        k++;

    }



    /* Copy the remaining elements of R[], if there

    are any */
   #pragma acc kernels num_gangs(8)
    for(j;j < n2;j++) {

        arr[k] = R[j];

        //j++;

        k++;

    }
}


/* l is for left index and r is right index of the
sub-array of arr to be sorted */

void mergeSort(int arr[], int l, int r)
{

    if (l < r) {

        // Same as (l+r)/2, but avoids overflow for

        // large l and h

        int m = l + (r - l) / 2;



        // Sort first and second halves

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);



        merge(arr, l, m, r);

    }
}


/* UTILITY FUNCTIONS */
/* Function to print an array */

void printArray(int A[], int size)
{

    int i;

    for (i = 0; i < size; i++)

        printf("%d ", A[i]);

    printf("\n");
}


/* Driver code */

int main()
{
int data[100000];
    int i;
    for (i = 0; i < 100000; i++) {
        data[i] = rand() % 100; // replace with your own data input code
    }


    int data_size = sizeof(data) / sizeof(data[0]);
    begin = getClock();
        mergeSort(data, 0, data_size - 1);
        end = getClock();


    //printf("\nSorted array is \n");

    //printArray(data, data_size);
    printf("The mergesort took %f seconds to complete\t",end-begin);

    return 0;
}