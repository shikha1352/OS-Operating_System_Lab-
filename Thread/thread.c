#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *argc);
int main(){
    pthread_t a_thread;
    pthread_create(&a_thread,NULL,thread_function,NULL);
    pthread_join(a_thread,NULL);
    printf("Inside main Thread\n");
    for(int i=25;i<30;i++){
        printf("%d\n",i);
        sleep(1);
    }
}
void *thread_function(void *argc){
    printf("Inside child Thread\n");
    for(int i=0;i<5;i++){
        printf("%d\n",i);
        sleep(1);
    }
}