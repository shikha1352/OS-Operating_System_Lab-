//Write a C program to create a child process using fork() and display both parent and child PIDs.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
int main() {
    pid_t pid = fork();
    if(pid == 0){
        printf("Child process. PID = %d\n", getpid());
    } 
    else if(pid > 0){
        printf("Parent process. PID = %d, Child PID = %d\n", getppid(), pid);
    } 
    else{
        perror("fork failed");
    }

    return 0;
}
