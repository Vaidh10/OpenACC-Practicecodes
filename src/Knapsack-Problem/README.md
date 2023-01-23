# Example Knapsack Problem

## From original [repo]

The code uses OpenACC to parallelize the nested loop in the knapsack_solver function, which is where the knapsack problem is solved. The #pragma acc parallel loop directive tells the compiler to parallelize the following loop using the OpenACC standard. The function acc_is_present checks whether the data is present on the device and it prints out "The data is present on the device" if the data is present on the device.the #pragma acc routine directive before the function definition of acc_is_present to provide the compiler with the necessary information to execute the function on an accelerator device