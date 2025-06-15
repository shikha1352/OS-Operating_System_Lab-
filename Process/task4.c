//Write a C program to create a process hierarchy: parent → child → grandchild
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid=fork();
    if(pid==0) {
        // Child
        printf("Child PID: %d\n",getpid());
        pid_t gpid=fork();
        if (gpid==0){
            // Grandchild
            printf("Grandchild PID: %d\n",getpid());
        }
    } 
    else 
    {
        // Parent
        wait(NULL);
    }

    return 0;
}
