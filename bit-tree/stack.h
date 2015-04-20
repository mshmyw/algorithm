#ifndef _STACK_H
#define _STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "define.h"

STATUS init_stack(STACK *s);

STATUS destroy_stack(STACK *s);

STATUS clear_stack(STACK *s);

STATUS is_empty_stack(STACK *s);

int length_stack(STACK *s);

STATUS get_top_stack(STACK *s, element_type_stack *e);

STATUS push_stack(STACK *s, element_type_stack e);

STATUS pop_stack(STACK *s, element_type_stack *e);

STATUS traverse_stack( STACK *s);

#endif
