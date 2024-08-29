#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
    for (int i = 0; i < 3; i++)
    {
        if (fork() == 0)
        {
            printf("Child process id is %d\n", getpid());
            printf("Parent process id of child is %d\n", getppid());
            exit(0);
        }
        else
        {
            printf("parent process id is %d\n", getpid());
            wait(NULL);
            printf("Child process is terminated\n");
        }
    }
}