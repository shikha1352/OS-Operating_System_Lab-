#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define SIZE 5
int buffer[SIZE];
int in=0;
int out=0;
sem_t empty,full;
pthread_mutex_t mutex;

void *producer(void *arg){
    int item=1;
    while(1){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in]=item;
        printf("Producer: %d\n",item);
        in=(in+1)%SIZE;
        item++;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}
void *consumer(void *arg){
    int item;
    while(1){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item=buffer[out];
        printf("Producer: %d\n",item);
        out=(out+1)%SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    return NULL;
}
int main(){
    pthread_t prod,con;

    sem_init(&empty,0,SIZE);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&con,NULL,consumer,NULL);

    pthread_join(prod,NULL);
    pthread_join(con,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}