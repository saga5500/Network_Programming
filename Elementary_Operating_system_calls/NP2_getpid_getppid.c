#include <stdio.h>
#include <unistd.h>// posix standard hearder file 
#include <sys/types.h> // the pid types 

int main()
{
    /* The data types of pid_t*/pid_t pid = getpid();
    int ppid = getppid();
    int  pid1= getpid();
    printf("print the process id %d\n", pid1);
    printf("The parent process id is %d\n", ppid);
    return 0;
}