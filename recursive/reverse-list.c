//file name : reverse-list.c
//created at: Mon Jul 20 15:32:00 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0

int max(int a, int b){
    if(a > b)
        return a;

    return b;
}

int min(int a, int b){
    if(a < b)
        return a;

    return b;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;

    return;
}

void print(int *a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%3d", a[i]);

    printf("\n");

    return;
}

typedef int ETYPE;
typedef struct _NODE{
    struct _NODE *next;
    ETYPE value;
}NODE;


NODE * create_list_inner(ETYPE value){
    if(value == 10)// list end condition
        return NULL;

    NODE * node;
    node = (NODE *)malloc(sizeof(NODE));
    node->value = value;
    node->next = create_list_inner(++value);
    return node;
}

NODE * create_list(){
    NODE * head;
    head = (NODE *)malloc(sizeof(NODE));
    ETYPE value = 1;
    head->next = create_list_inner(value);
    return head;
}

void print_list(NODE * head){
    if(!head){
        printf("\n");
        return;
    }

    printf("-%d-", head->value);
    print_list(head->next);
    return;
}

void reverse_list_inner(NODE *head, NODE *old_node, NODE *new_list){
    if(!old_node){
        head->next = new_list;
       return;
    }

    NODE * p = old_node->next;
    old_node->next = new_list;
    reverse_list_inner(head, p, old_node);
    return;
}

NODE * reverse_list(NODE *head){
    if(!head)
        return NULL;

    reverse_list_inner(head, head->next, NULL);
    return head;
}

int main(void){
    NODE * head = create_list();
    print_list(head->next);

    reverse_list(head);
    print_list(head->next);

    return 0;
}
