#include <stdio.h>
#include <openacc.h>

#define ITEMS 4
#define KNAPSACK_SIZE 5

int knapsack[ITEMS+1][KNAPSACK_SIZE+1];
int weights[ITEMS+1] = {0, 2, 3, 4, 5};
int values[ITEMS+1] = {0, 3, 4, 5, 6};

int max(int a, int b) {
    return (a > b) ? a : b;
}

#pragma acc routine seq
int acc_is_present(void *ptr, size_t size) {
    return acc_is_present(ptr, size);
}

int knapsack_solver(int n, int w) {
    int i, j;
    for (i = 0; i <= n; i++) {
        #pragma acc parallel loop
        for (j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                knapsack[i][j] = 0;
            } else if (weights[i] <= j) {
                knapsack[i][j] = max(values[i] + knapsack[i-1][j-weights[i]], knapsack[i-1][j]);
            } else {
                knapsack[i][j] = knapsack[i-1][j];
            }
        }
    }
    return knapsack[n][w];
}

int main() {
    int result = knapsack_solver(ITEMS, KNAPSACK_SIZE);
    printf("Optimal value: %d\n", result);
    #pragma acc kernels
    {
    if (acc_is_present(knapsack, sizeof(knapsack)))
        printf("The data is present on the device\n");
    }
    return 0;
}