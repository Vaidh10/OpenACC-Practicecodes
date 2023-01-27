// C program for implementation of Bubble sort
#include <stdio.h>
#include <time.h>
#define getClock() ((double)clock()/CLOCKS_PER_SEC)
#include <omp.h>
double begin,end;
void swap(int *xp, int *yp)
{

    int temp = *xp;

    *xp = *yp;

    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    begin = getClock();
    #pragma acc data copy(arr[0:n])
    {
        #pragma acc parallel loop
        for (i = 0; i < n - 1; i++)
        {
            // Last i elements are already in place
            #pragma acc loop
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    end = getClock();
}

void printArray(int arr[], int size)
{

    int i;

    for (i=0; i < size; i++)

        printf("%d ", arr[i]);

    printf("\n");
}

// Driver program to test above functions

int main()
{


        FILE *myFile;
        myFile = fopen("dataset.txt","r");
        int data[100000];
        int i;
        for (i=0;i<100000;i++){

                fscanf(myFile,"%d",&data[i]);
        }


    int n = sizeof(data)/sizeof(data[0]);

    bubbleSort(data, n);

    printf("Sorted array: \n");

    printArray(data, n);
        printf("The bubblesort took %f seconds to complete\t",end-begin);
    return 0;
}