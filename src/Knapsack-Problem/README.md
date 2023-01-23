# Knapsack Problem with OpenACC

This is a C program that solves the knapsack problem using OpenACC. The knapsack problem is an optimization problem where the goal is to maximize the value of a collection of items with specific weights and values, subject to a constraint on the total weight.

The code defines two arrays, `weights` and `values`, which contain the weight and value of each item respectively. The `knapsack_solver` function takes in two arguments, `n` and `w`, which represent the number of items and the maximum weight of the knapsack respectively. The function uses a nested loop to fill in the `knapsack` array with the optimal values. The outer loop iterates through the items, and the inner loop iterates through the possible weights. The function then returns the optimal value, which is stored in the last element of the `knapsack` array.

The `main` function calls the `knapsack_solver` function with the number of items and the maximum weight of the knapsack, and then prints the optimal value. The function also uses the OpenACC function `acc_is_present` to check if the data is present on the device.

This code is a simple implementation of the knapsack problem using OpenACC, it uses the parallel loop construct to offload the computation on the device.

