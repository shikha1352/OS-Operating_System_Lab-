// Write a C program to demonstrate zombie process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
int main() {
    pid_t pid=fork();
    if(pid==0) {
        printf("Child process exiting.\n");
        exit(0);
    }
    else 
    {
        sleep(30); 
        printf("Parent is sleeping, child is now zombie.\n");
    }

    return 0;
}
