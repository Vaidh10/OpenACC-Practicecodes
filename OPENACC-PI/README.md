Example PI: Computing the number PI
===================================

## Objectives

By the end of this exercise you should know how to:

- [X] Open an existing code directory as a project in Parallelware Trainer.
- [X] Identify opportunities for parallelization and generate a parallel version of one loop.
- [X] Run the newly parallelized code and measure the execution time.
- [X] Create and manage files that contain different parallel implementations of the same loop using different parallelization methods.
- [ ] Understand how to use the Parallelware Trainer User Action List.
- [ ] Provide information to Parallelware that cannot be automatically determined to improve parallelization.

(The last two items are covered in the [DOTPRODUCT example](../DOTPRODUCT/README.md) which we recommend completing after working through this example, and before moving onto working on your own code.)

## Steps

1. Launch Parallelware Trainer

2. Open the PI code example from the Parallelware Trainer menus (*File > Open Project*). Select the 'PI' folder in the examples directory. This should open the project in the Parallelware Trainer Project Explorer panel.

3. Double-click 'pi.c' inside the 'src' folder to open it. The code will now be displayed in the main panel - the Code Editor. Note the green circle next to line 29. This identifies a loop parallelization opportunity.

4. Click the green circle and select one of the following configurations:
    - OpenMP: use the default selected options (OpenMP, CPU and loop).
    - OpenACC: select OpenACC standard, GPU device and Offloading paradigm.

5. Click 'Parallelize' and Parallelware will insert correct parallelization pragmas for you based on these requirements. Parallelware Trainer also will create a new version containing the original code in the right-hand panel, the 'Version Manager'. To show the Version Manager, click the ‘<’ arrow located to the right of the source-code window.

6. Save the code as a new version of the parallelized code by clicking the button located to the right of the file name in the Code Editor. A dialog will ask you to name the version: enter 'pi_reduction'. For more information on storing and creating versions of your project code read section 3.7 of the Parallelware Trainer User Manual.

7. Restore the original version by clicking the restore button (located to the left of the version name on top of the Version Manager panel). A dialog will pop up, asking you to confirm that you want to overwrite the code in the editor with that of the version. Confirm by clicking 'OK'.

8. Now generate a different type of parallelization by again clicking the green circle.
    * Retain the same options used in step 4, but in the ‘Atomic protection’ input box enter the name of the variable that is being protected: i.e. ‘sum’.
    * Close the dialogue by clicking ‘Parallelize’ to update your code with an atomic clause.
    * Delete the auto-generated Original 2 version as it contains the same code as Original 1 by hitting the X button next to its name.

9. Create a new version named 'pi_atomic', following the instructions in step 6.

10. Now you should have 3 versions of the 'pi.c' file: original, pi_reduction and pi_atomic. Note that the Version Manager only displays code versions associated with the currently open file displayed in the Code Editor. If a completely different file (from the same project or other projects) is viewed in the Code Editor, the Version Manager will longer display the versions associated with the previously loaded file.

12. Configure the build and run commands.
    * Open the Project Configuration dialogue: select the *Project > Configuration* menu option.
    * In the Build tab enter the build command. A Makefile that uses the gcc compiler is provided. If you don't have Make or gcc, you can enter the compiler invocation directly. Otherwise choose:
        * For an OpenMP enabled code: `make omp`
        * For an OpenACC enabled code: `make acc`
    * In the Run tab enter: `pi 100000000`

13. Now you are ready to experiment and measure runtimes to compare performance between the different versions.
    * To measure the execution time of a particular version restore it from the Version Manager (right hand window) to the Code Editor (left hand window). Whenever you do this, be sure that there is a copy of the code currently open in the Code Editor in the Version Manager before overwriting it.
    * Click ‘Run’ (the play icon located at the bottom) or press F6 to build and run the code.
    * The Execution output console will show the runtime.
    * Compare the runtime for the different versions created.

14. For OpenMP, you can change the number of threads by using the `OMP_NUM_THREADS` environment variable. If not set, in some instances OpenMP defaults to as many threads as CPU cores, in other instances it will just use one thread. Experiment with different values and run the project to compare execution times. You can change the number of threads before running the code by modifying your run command in *Project > Configuration*; for instance to use two threads, enter the following in the Run tab of the Project Configuration dialogue:
    * Linux and MacOS: `env OMP_NUM_THREADS=2 ./pi 100000000`
    * Windows: `cmd /c OMP_NUM_THREADS=2 && pi 100000000`
