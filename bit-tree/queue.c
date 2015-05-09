#include "queue.h"


int init_queue(QUEUE *q){
    q->front = q->rear = (PNODE)malloc(sizeof(NODE));
    if(q->front == NULL){
		printf("queue malloc failed...\n");
        return FALSE;
	}
    q->front->next = NULL;

    return TRUE;
}

void destroy_queue(QUEUE *q) {
    assert(q != NULL);
    while(q->front){
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}
 
int is_empty_queue(QUEUE *q){
    assert(q->front != NULL && q->rear != NULL);

    if(q->front == q->rear)
        return TRUE;

	return FALSE;
}

int length_queue(QUEUE *q){
    assert(q->front != NULL);
    PNODE p = q->front;
    int length = 0;
    while (p != q->rear)
    {
        length++;
        p = p->next;
    }

    return length;
}
int get_head_queue(QUEUE *q,  element_type_queue *e){
    assert(q->front != NULL);
    if(is_empty_queue(q))
        return FALSE;
    
    *e = q->front->next->node;
        return TRUE;
}

void traverse_queue(QUEUE *q){
    assert(q->front != NULL);
    PNODE p = q->front->next;
    while(p){
		printf("%c ", p->node->data);
        p = p->next;
    }
}

int en_queue(QUEUE *q, element_type_queue e){
    PNODE temp = (PNODE)malloc(sizeof(NODE));
    if(temp == NULL){
		printf("enter queue: malloc failed...\n");
        return FALSE;
	}
    temp->node  = e;
	temp->next = NULL;

    q->rear->next = temp;
    q->rear = temp;

    return TRUE;
}
int de_queue(QUEUE *q, element_type_queue *e){
    if(q->front == q->rear)
        return FALSE;

  	PNODE temp = q->front->next;
    *e = temp->node;

	q->front->next= temp->next;
	if(q->rear == temp)
        q->rear = q->front;

    free(temp);
   
	return TRUE;
}
