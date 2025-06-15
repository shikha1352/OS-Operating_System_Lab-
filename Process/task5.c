//Write a C program where parent waits for the child to terminate using waitpid()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    pid_t pid=fork();
    if(pid==0){
        printf("Child process\n");
        exit(42);
    } 
    else{
        int status;
        waitpid(pid, &status, 0);
        printf("Child exited with status %d\n",WEXITSTATUS(status));
    }
}
