// the fork is used to create a child process

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
pid_t pid=fork();
// if child process is created successfully, fork() returns 0
//if fork() returns -1, then the child process is not created
//if fork() returns a positive value, then the parent process is created
printf("Using fork() system call %d\n", pid);
return 0;
}
