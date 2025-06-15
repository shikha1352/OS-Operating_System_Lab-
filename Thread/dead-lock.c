#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *func1();
void *func2();
pthread_mutex_t first_mutex,second_mutex;
int main(){
    pthread_mutex_init(&first_mutex,NULL);
    pthread_mutex_init(&second_mutex,NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,func1,NULL);
    pthread_create(&t2,NULL,func2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("thread joined\n");
}
void *func1(){
    printf("Thread1 trying to acquire first mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("Thread1 acquire first_mutex\n");
    sleep(1);
    printf("Thread1 trying to acquire second mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("Thread1 acquire second mutex\n");
    pthread_mutex_unlock(&first_mutex);

}
void *func2(){
     printf("Thread2 trying to acquire second mutex\n");
    pthread_mutex_lock(&second_mutex);
    printf("Thread2 acquire second mutex\n");
    sleep(1);
    printf("Thread2 trying to acquire first mutex\n");
    pthread_mutex_lock(&first_mutex);
    printf("Thread2 acquire first mutex\n");
    pthread_mutex_unlock(&second_mutex);

}