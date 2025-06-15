//Write a C program to prevent zombie using wait()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid=fork();
    if(pid==0) {
        printf("Child exiting.\n");
        exit(0);
    } 
    else{
        wait(NULL);
        printf("Parent collected child process.\n");
    }
}
