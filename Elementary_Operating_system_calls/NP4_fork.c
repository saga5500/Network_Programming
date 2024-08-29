#include <stdio.h>
#include <unistd.h>    //posix standard hearder file
#include <sys/types.h> //pid types

int main()
{
    int id=fork();
    fork();
    fork();
    // How many times it prints 2^n times
    // it will print 8 times
    // as first fork will create 1 child process
    // as second fork will create 2 child process
    // as third fork will create 4 child process
    printf("Hello World\n");
    printf ("The process id is %d\n",id);
    return 0;
}
