#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int id;

    printf("hello world\n");

    id = fork(); // Create a new process

    if (id > 0)
    {
        // This block is executed by the parent process
        printf("The parent process id is %d\n", getpid());
    }
    else if (id == 0)
    {
        // This block is executed by the child process
        printf("The child process id is %d\n", getpid());
        printf("The parent process id of child is %d\n", getppid());
    }
    else
    {
        // This block is executed if fork() fails
        printf("The child process is not created\n");
    }

    return 0;
}
