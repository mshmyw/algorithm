#include "stack.h"

STATUS init_stack(STACK *s){

    s->base=(element_type_stack *)malloc(STACK_INIT_SIZE * sizeof(element_type_stack));
    if(!s->base){
        printf("init_stack failed...\n");
        exit(0);
    }
    s->top=s->base;
    s->stack_size = STACK_INIT_SIZE;
    return OK;
}

STATUS destroy_stack(STACK *s){
    if(!s){
        printf("destroy stack failed...\n");
        exit(0);
    }
    free(s->base);

    return OK;
}

STATUS clear_stack(STACK *s){

    if(!s)
        return FALSE;
    s->top=s->base;
    return OK;
}

STATUS is_empty_stack(STACK *s){
    if(s->top == s->base)
        return TRUE;

    return FALSE;
}

int length_stack(STACK *s){
    return s->stack_size;
}

STATUS get_top_stack(STACK *s, element_type_stack *e){
    if(s->top == s->base)
        return FALSE;

    *e = *(s->top - 1);
    return OK;
}

STATUS push_stack(STACK *s, element_type_stack e){
    if(s->top-s->base >= s->stack_size){
        s->base=(element_type_stack *)realloc(s->base,(s->stack_size + STACK_INCREMENT)*sizeof(element_type_stack));
        if(!s->base){
            printf("realloc failed.\n");
            exit(0);
        }

        s->top = s->base + s->stack_size;
        s->stack_size += STACK_INCREMENT;
    }

    *s->top++ = e;
    return OK;
}

STATUS pop_stack(STACK *s, element_type_stack *e){

    if(s->top == s->base)
        return ERROR;

    *e = *(--s->top);

    return OK;
}
