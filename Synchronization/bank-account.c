#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
int accountA = 500;
int accountB = 0;
pthread_mutex_t mutex;      
sem_t semaphore;            
void *transfer(void *arg) {
    int amount = *((int *)arg);
    sem_wait(&semaphore);
    pthread_mutex_lock(&mutex);
    if (accountA >= amount) {
        sleep(1); 
        accountA -= amount;
        accountB += amount;
    }
    printf("Transfer %d: A=%d, B=%d (Total: %d)\n",
           amount, accountA, accountB, accountA + accountB);
    pthread_mutex_unlock(&mutex);
    sem_post(&semaphore);
    return NULL;
}
int main() {
    pthread_t thread1, thread2;
    int amount1 = 100, amount2 = 500;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&semaphore, 0, 1);  
    pthread_create(&thread1, NULL, transfer, &amount1);
    pthread_create(&thread2, NULL, transfer, &amount2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final balances: A=%d, B=%d (Total: %d)\n",
           accountA, accountB, accountA + accountB);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&semaphore);

    return 0;
}
