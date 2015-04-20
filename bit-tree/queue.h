#ifndef TOPOLOGY_QUEUE_H
#define TOPOLOGY_QUEUE_H
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

#include "define.h"

int init_queue(QUEUE *q);
void destroy_queue(QUEUE *q);
int is_empty_queue(QUEUE *q);
int length_queue(QUEUE *q);
int get_head_queue(QUEUE *q,  element_type_queue *e);
void traverse_queue(QUEUE *q);
int en_queue(QUEUE *q, element_type_queue e);
int de_queue(QUEUE *q, element_type_queue *e);
#endif

