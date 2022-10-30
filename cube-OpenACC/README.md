Example Cubes: This code solves the sum of three cubes problem.
 *      x^3 + y^3 + z^3 = k
=================================================

## Objectives

By the end of this exercise you should know how to:

- [X] Open an existing code directory as a project in Parallelware Trainer.
- [X] Identify opportunities for parallelization and generate a parallel version of one loop.
- [X] Run the newly parallelized code and measure the execution time.
- [X] Create and manage files that contain different parallel implementations of the same loop using different parallelization methods.
- [X] Understand how to use the Parallelware Trainer User Action List.
- [X] Provide information to Parallelware that cannot be automatically determined to improve parallelization.


 ## Steps

1. Launch Parallelware Trainer.

2. Open the Cubes code example from the Parallelware Trainer menus (*File > Open Project*). Select the 'Cubes' folder in the examples directory. This should open the project in the Parallelware Trainer Project Explorer panel.

3. Double-click 'Cubes.c' inside the 'src' folder to open it. The code will now be displayed in the main panel - the Code Editor. Note the green circle next to line 6. This identifies a loop parallelization opportunity.

4. Click the green circle and select one of the following configurations:
    - OpenMP: use the default selected options (OpenMP, CPU and loop).
    - OpenACC: select OpenACC standard, GPU device and Offloading paradigm.
Click ‘Parallelize’ and Parallelware will insert parallelization pragmas for you based on these requirements. Parallelware Trainer will also create a copy of the original code in the right hand panel, the 'Version Manager'. To show the Version Manager, click the ‘<’ arrow located to the right of the source-code window.

5. A 'User Action List' panel is shown below the Code Editor. It contains a list of actions that the user must complete to ensure that the parallelization is correct.
    - Prerequisite actions must be completed to ensure correct parallelization.
    - Fill-in actions correspond to missing information that the user must supply.

6. Ensure that the variables listed are no aliased, that is, the same memory is not accessed with a different variable name somewhere else in the parallel region. This would invalidate the parallelization.

7. Some information might not be inserted by Parallelware because as it could not automatically determine the array ranges for correct parallelization. You have two options to provide this information to Parallelware Trainer:
    - Enter the information directly in the code.
    - Restore the previous version from the Version Manager and click the green circle again to parallelize. Select the same options as before but now fill in array ranges: `v[0:n], u[0:n]`. Click Parallelize and notice that the new code inserted now contains the array ranges as required.

Note that his example focuses on introducing you to the user action list and providing parallelization parameters. Using the GPU for this particular algorithm is inefficient due to the data transfer overhead that would is introduced.
