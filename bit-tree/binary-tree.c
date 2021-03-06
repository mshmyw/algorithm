#include "stack.h"
#include "queue.h"

int max(int a, int b){
    if(a <= b)
        return b;

    return a;
}

BIT_TREE create_bit_tree(BIT_TREE t){
    char ch;

    scanf("%c",&ch);
    if(ch == '0') return NULL;

    if(!(t = (BIT_NODE *)malloc(sizeof(BIT_NODE))))
        exit(OVERFLOW);

    t->data = ch;
    t->lchild = create_bit_tree(t->lchild);
    t->rchild = create_bit_tree(t->rchild);
    return t;
}

int deep_tree(BIT_TREE t){
    if(t == NULL)return 0;

    int left_deep = deep_tree(t->lchild);
    int right_deep = deep_tree(t->rchild);

    return max(left_deep, right_deep) + 1;
}

void pre_ord_recur_traverse(BIT_TREE t){
    if(t == NULL)
        return;
    printf("%c  ", t->data);
    pre_ord_recur_traverse(t->lchild);
    pre_ord_recur_traverse(t->rchild);
    return;
}

STATUS pre_order_no_recur_traverse(BIT_TREE t){
    STACK s;
    STACK *sp;
    element_type_stack p;

    sp = &s;
    init_stack(sp);
    push_stack(sp, t);

    while(!is_empty_stack(sp)){
        pop_stack(sp, &p);

        printf("visit: %c ", p->data);

        if (p->rchild)
            push_stack(sp, p->rchild);
        if(p->lchild)
            push_stack(sp, p->lchild);
    }//while

    destroy_stack(sp);

    return OK;
}

void level_recur_traverse(BIT_TREE t, QUEUE *qarray, int level){
    if(!t) return;

    en_queue(&qarray[level], t); //record the current,and use the qarray to keep the value

    if(t->lchild)
        level_recur_traverse(t->lchild, qarray, level + 1);
    if(t->rchild)
        level_recur_traverse(t->rchild, qarray, level + 1);

    return;
}

STATUS level_traverse(BIT_TREE t){
    QUEUE q;
    QUEUE *qp;
    element_type_queue bit_node, flag_node;
    int level = 0;
    qp = &q;
    init_queue(qp);
    flag_node = malloc(sizeof(BIT_NODE));
    flag_node->data = -9;
    flag_node->lchild = flag_node->rchild = NULL;
    en_queue(qp, t);
    en_queue(qp, flag_node); //as flag of every level

   while(is_empty_queue(qp) == FALSE){
        de_queue(qp, &bit_node);
        if(bit_node != flag_node){
            printf("%c ", bit_node->data);
            if(bit_node->lchild)en_queue(qp, bit_node->lchild);
            if(bit_node->rchild)en_queue(qp, bit_node->rchild);
        }else{
            level++;
            if(is_empty_queue(qp) == FALSE)en_queue(qp, flag_node);
        }
}
   printf("\nlevel %d\n", level);
   return OK;
}

STATUS level_traverse_2(BIT_TREE t){
    QUEUE q;
    QUEUE *qp;
    element_type_queue bit_node;
    int level = 0;

    qp = &q;
    init_queue(qp);

    en_queue(qp, t);

   while(is_empty_queue(qp) == FALSE){
       int current_level_count = length_queue(qp);
       int i;
       for(i = 0; i < current_level_count; i++){
           de_queue(qp, &bit_node);
           printf("%c ", bit_node->data);
           if(bit_node->lchild)en_queue(qp, bit_node->lchild);
           if(bit_node->rchild)en_queue(qp, bit_node->rchild);
       }

       level++;
}
   printf("\nlevel_2 %d\n", level);

   return OK;
}

int main(void){
    BIT_TREE t = NULL;

    t = create_bit_tree(t);
    pre_ord_recur_traverse(t);
    printf("\n--pre traverse----\n");
    pre_order_no_recur_traverse(t);
    printf("\n------\n");
    int deep = deep_tree(t);
    printf("deep %d\n", deep);
    printf("\n--level traverse----\n");
    level_traverse(t);
    printf("\n");

    QUEUE qarray[8];

    int i;
    for(i = 0; i < 8; i++)
        init_queue(&qarray[i]);

    level_recur_traverse(t, qarray, 0);
    for(i = 0; i < 8; i++){
        traverse_queue(&qarray[i]);
        printf("\n");
    }

    printf("------\n");
    level_traverse_2(t);
   return 0;
}
