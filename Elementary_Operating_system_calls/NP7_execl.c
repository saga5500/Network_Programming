// using execl to run ls program 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
    execl("/bin/ls","ls","-l",(char *)NULL);
    printf("this will  not be printed if exec failed \n");
    return 0;
}