#ifndef _DEFINE_H
#define _DEFINE_H

#define OK          1
#define ERROR       0
#define TRUE        1
#define FALSE       0
#define OVERFLOW    -1

#define STACK_INIT_SIZE     100
#define STACK_INCREMENT      10
#define IPADDR_LEN           16
typedef int STATUS;

typedef char element_type;

typedef struct _BIT_NODE{
    char data;
    struct _BIT_NODE *lchild;
    struct _BIT_NODE *rchild;
}BIT_NODE, *BIT_TREE;

typedef BIT_TREE element_type_stack;
typedef BIT_TREE element_type_queue;

typedef struct _STACK{
    element_type_stack *base;
    element_type_stack *top;
    int stack_size;
}STACK;

typedef struct _NODE{
    element_type_queue node;
    struct _NODE *next;          // 链式队列中结点元素的指针
}NODE, *PNODE;

typedef struct _QUEUE{
    PNODE front;             // 队列头指针
    PNODE rear;              // 队列尾指针
}QUEUE;

#endif
