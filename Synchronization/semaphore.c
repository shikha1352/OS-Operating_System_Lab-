#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
void *func1();
void *func2();
int shared=1;
sem_t s;
int main(){
    sem_init(&s,0,1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,func1,NULL);
    pthread_create(&t2,NULL,func2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("final value of shared is: %d\n",shared);
}
void *func1(){
    int x;
    sem_wait(&s);
    x=shared;
    printf("Threa1 reads the value of shared as : %d\n",x);
    x++;
    printf("Local updation by thread1 is :%d\n",x);
    sleep(1);
    shared=x;
    printf("value of shared variable update by thread1 is :%d\n",shared);
    sem_post(&s);
}
void *func2(){
    int y;
    sem_wait(&s);
    y=shared;
    printf("Threa2 reads the value of shared as : %d\n",y);
    y--;
    printf("Local updation by thread2 is :%d\n",y);
    sleep(1);
    shared=y;
    printf("value of shared variable update by thread2 is :%d\n",shared);
    sem_post(&s);
}