#include<stdio.h>
#include<unistd.h>//posix standard hearder file
#include<stdlib.h>//exit function 
#include<fcntl.h>//open function and file discrptor flags

int Openfile(char *filename){
    int ft=open(filename,O_RDONLY);
    if(ft==-1){
        perror("error in opening file ");
    }
}

int main(){
    int fd= Openfile("Np1.txt");
    close(fd);
    return 0;
}