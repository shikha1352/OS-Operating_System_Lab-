#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t s;
void *func(void *arg) {
    int n = *((int *)arg);
    sem_wait(&s);
    printf("Thread[%d] acquired the resource.\n", n);
    sleep(1);
    sem_post(&s);
    printf("Thread[%d] finish\n", n);
    free(arg);
    return NULL;
}
int main() {
    sem_init(&s, 0, 1);
    int n;
    printf("Enter the number of threads:\n");
    scanf("%d", &n);
    pthread_t thread[n];
    for (int i = 0; i < n; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&thread[i], NULL, func, arg);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(thread[i], NULL);
    }
    sem_destroy(&s);
    return 0;
}
