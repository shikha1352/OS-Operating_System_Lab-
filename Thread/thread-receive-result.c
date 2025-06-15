#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include<stdlib.h>

void *thread_function(void *argc);

int num[2] = {3, 5};

int main() {
    pthread_t a_thread;
    void *result;   

    pthread_create(&a_thread, NULL, thread_function, (void *)num);
    pthread_join(a_thread, &result);

    printf("Inside main thread\n");
    printf("Thread returned sum: %d\n", *((int *)result));

    return 0;
}

void *thread_function(void *argc) {
    printf("Inside Child Thread\n");
    int *x = (int *)argc;
    int *sum = (int *)malloc(sizeof(int));
    *sum = x[0] + x[1];
    //printf("Sum is %d\n", sum);
    pthread_exit((void*)sum);
}
