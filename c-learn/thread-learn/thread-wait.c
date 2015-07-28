//file name : thread-wait.c
//created at: Tue Jul 28 20:41:31 2015
//author:  root
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t count_lock;
pthread_cond_t count_nonzero;
unsigned count = 0;
void * decrement_count(void *arg){
    pthread_mutex_lock(&count_lock);
    printf("decrement_count get count_lock ^-^-%d-^-^\n", count);
    while (count == 0){
        printf("decrement_count count == 0 ^-^-%d-^-^\n", count);
        printf("decrement_count before cond_wait ^-^-%d-^-^\n", count);
        pthread_cond_wait( &count_nonzero, &count_lock);
        printf("decrement_count after cond_wait ^-^-%d-^-^\n", count);
    }
    count = count -1;
    pthread_mutex_unlock (&count_lock);

    return NULL;
}

void * increment_count(void *arg){
    pthread_mutex_lock(&count_lock);
    printf("increment_count get count_lock ^-^-%d-^-^\n", count);
    if(count == 0){
        printf("increment_count before cond_signal ^-^-%d-^-^\n", count);
        pthread_cond_signal(&count_nonzero);
        printf("increment_count after cond_signal ^-^-%d-^-^\n", count);
    }
    count = count + 1;
    pthread_mutex_unlock(&count_lock);

    return NULL;
}

int main(void){
    pthread_t tid1, tid2;
    pthread_mutex_init(&count_lock, NULL);
    pthread_cond_init(&count_nonzero, NULL);
    pthread_create(&tid1, NULL, decrement_count, NULL);
    sleep(1);
    pthread_create(&tid2, NULL, increment_count, NULL);
    sleep(2);

    getchar();
    pthread_exit(0);

    return 0;
}
