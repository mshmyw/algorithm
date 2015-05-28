#include "priority-queue.h"

int is_empty( PRIORITY_QUEUE pq){
    return pq->size == 0;
}

int is_full( PRIORITY_QUEUE pq){
    return pq->size == pq->capacity;
}

PRIORITY_QUEUE init(int max_emts){
    PRIORITY_QUEUE pq;
    pq = malloc(sizeof(struct HEAP_STRUCT));
    if(pq == NULL){
        printf("malloc wrong....\n");
        exit(1);
    }

    pq->emts = malloc(sizeof( EMT_TYPE) * (max_emts + 1));
    if(pq->emts == NULL){
        printf("malloc wrong....\n");
        exit(1);
    }

    pq->capacity = max_emts;
    pq->size = 0;
    pq->emts[0] = -1000; //min data;

    return pq;
}
void insert(EMT_TYPE x, PRIORITY_QUEUE pq){  // go up
    int i;

    if(is_full(pq)){
        printf("priority queue is full...\n");
        return;
    }

    for(i = ++(pq->size); pq->emts[i / 2] > x; i = i / 2) //from a nonexist positon start
        pq->emts[i] = pq->emts[i / 2];
    pq->emts[i] = x;

    return;
}

EMT_TYPE delete_min(PRIORITY_QUEUE pq){
    if(is_empty(pq)){
        printf("priority queue is full...\n");
        return pq->emts[0]; //what??
    }
    EMT_TYPE min_emt = pq->emts[1];
    EMT_TYPE last_emt = pq->emts[pq->size--];
    int i, child;
    for(i = 1; 2 * i <= pq->size; i = child){ // from the second positon start
        child = 2 * i;
        if((child != pq->size) && (pq->emts[child] > pq->emts[child + 1]))
            child++;
        if(last_emt > pq->emts[child])
            pq->emts[i] = pq->emts[child];
        else
            break;
    }

    pq->emts[i] = last_emt;

    return min_emt;
}
