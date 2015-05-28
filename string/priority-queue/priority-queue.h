#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int EMT_TYPE;

typedef struct HEAP_STRUCT{
    int capacity;
    int size;
    EMT_TYPE *emts;
} *PRIORITY_QUEUE;

int is_empty( PRIORITY_QUEUE pq);
int is_full( PRIORITY_QUEUE pq);
PRIORITY_QUEUE init(int max_emts);
void insert(EMT_TYPE x, PRIORITY_QUEUE pq);
EMT_TYPE delete_min(PRIORITY_QUEUE pq);


#endif
