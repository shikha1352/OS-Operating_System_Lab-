//Write a C program that uses fork() in a loop to create N child processes
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
int main() {
    int n = 3;
    for(int i=0;i<n;i++){
        pid_t pid=fork();
        if (pid==0){
            printf("Child %d with PID %d\n",i+1,getpid());
            return 0;
        }
    }
    for(int i=0;i<n;i++) 
        wait(NULL);
    return 0;
}
