#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execle\n");

    // Define custom environment variables
    char *envp[]={"MYENV=Hello", "USER=myuser",NULL};

    // Use execle to run the 'ls' command with custom environment
    execle("/bin/ls", "ls", "-l", (char *)NULL, envp);

    // This line will only execute if execle fails
    printf("This will only print if execle failed\n");

    return 0;
}
