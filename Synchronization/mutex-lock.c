#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *func1();
void *func2();
int shared=1;
pthread_mutex_t l;
int main(){
    pthread_mutex_init(&l,NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,func1,NULL);
    pthread_create(&t2,NULL,func2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("final value of shared is: %d\n",shared);
}
void *func1(){
    int x;
    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("Thread1 acquire lock\n");
    x=shared;
    printf("Threa1 reads the value of shared as : %d\n",x);
    x++;
    printf("Local updation by thread1 is :%d\n",x);
    sleep(1);
    shared=x;
    printf("value of shared variable update by thread1 is :%d\n",shared);
    pthread_mutex_unlock(&l);
    printf("thread1 release the lock\n");
}
void *func2(){
    int y;
    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("Thread2 acquire lock\n");
    y=shared;
    printf("Threa2 reads the value of shared as : %d\n",y);
    y--;
    printf("Local updation by thread2 is :%d\n",y);
    sleep(1);
    shared=y;
    printf("value of shared variable update by thread2 is :%d\n",shared);
    pthread_mutex_unlock(&l);
    printf("thread2 release the lock\n");
}