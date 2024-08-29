#include <stdio.h>     // Standard I/O library for printf
#include <stdlib.h>    // Standard library for exit
#include <unistd.h>    // For fork(), getpid(), and sleep()
#include <sys/wait.h>  // For waitpid() and macros like WIFEXITED()
#include <sys/types.h> // For PID type definitions

int main() {
    pid_t pid1;        // Variable to store the PID of the child process
    int status;        // Variable to store the status of the terminated child process

    // Step 1: Create a child process
    // fork() creates a new process. It returns the child's PID in the parent and 0 in the child.
    if ((pid1 = fork()) == 0) {
        // This block is executed by the child process
        printf("Child (PID: %d) executing\n", getpid()); // Print child's PID
        sleep(2); // Sleep for 2 seconds to simulate work
        printf("Child (PID: %d) exiting\n", getpid()); // Print child's PID before exiting
        exit(5); // Exit with status 5
    }

    // Step 2: The following block is executed by the parent process

    // Print a message indicating that the parent is waiting for the specific child process with PID `pid1`
    printf("Parent (PID: %d) waiting for child with PID: %d\n", getpid(), pid1);

    // waitpid() suspends the parent process until the specific child process `pid1` exits
    // &status is a pointer where the status information of the child process will be stored
    waitpid(pid1, &status, 0);

    // Step 3: Check the status of the terminated child process
    // WIFEXITED() checks if the child terminated normally
    if (WIFEXITED(status)) {
        // Print the exit status of the child process
        printf("Parent (PID: %d) child with PID %d exited with status %d\n", getpid(), pid1, WEXITSTATUS(status));
    }

    return 0; // End of the program
}
