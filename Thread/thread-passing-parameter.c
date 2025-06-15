#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *argc);

int num[2] = {3, 5};

int main() {
    pthread_t a_thread;
    void *result;  

    pthread_create(&a_thread, NULL, thread_function, (void *)num);
    pthread_join(a_thread, &result);

    printf("Inside main thread\n");
    printf("Thread returned: %s\n", (char *)result);

    return 0;
}

void *thread_function(void *argc) {
    printf("Inside Child Thread\n");
    int *x = (int *)argc;
    int sum = x[0] + x[1]; 
    printf("Sum is %d\n", sum);
    pthread_exit("sum calculated");
}
