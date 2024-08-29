#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
int pipefd[2]; // two arrays two read file descriptors and write file descriptors
char buffer[100];

// cerate a pipe 
    pipe(pipefd);

    // child process writing from the file
    if (fork==0){
        close(pipefd[0]);
        write(pipefd[1], "My name is sagar", 25 );
        close(pipefd[1]);
    }else{
        //parent process reading from the file 
        close(pipefd[1]);
        read(pipefd[0],buffer, sizeof(buffer));
        printf("The print is %s\n",buffer );
        close(pipefd[0]);
    }

    return 0 ;
}