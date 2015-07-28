//file name : thread-mutex.c
//created at: Tue Jul 28 19:51:41 2015
//author:  root

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>

void reader_function (void);
void writer_function (void);
int buffer_has_item = 0; //thread share variable
pthread_mutex_t mutex;
int main (void){
    pthread_t reader;

    pthread_mutex_init(&mutex,NULL);
    pthread_create(&reader, NULL, (void *)&reader_function, NULL);
    writer_function();
    return 0;
}

void writer_function(void){
    while (1){
        pthread_mutex_lock(&mutex);
        if (buffer_has_item == 0){
            buffer_has_item = 1;
            printf("^-^--write once--^-^\n");
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void reader_function(void){
    while (1){
        pthread_mutex_lock(&mutex);
        if (buffer_has_item == 1){
            buffer_has_item = 0;
            printf("^-^--read once--^-^\n");
        }
        pthread_mutex_unlock(&mutex);
    }
}
