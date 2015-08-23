//file name : last-traverse-is-binary-search-tree.c
//created at: Sun Aug 23 16:06:39 2015
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

bool last_traverse_is_bst_inner(int *left, int *right){
    if(left > right)
        return true;

    int *pleft, *pright;
    for(pleft = left; pleft < right; pleft++)
        if(*pleft > *right)
            break;

    for(pright = pleft; pright < right; pright++)
        if(*pright < *right)
            return false;

    return last_traverse_is_bst_inner(left, pleft - 1)&&
        last_traverse_is_bst_inner(pleft, right - 1);
}

bool last_traverse_is_bst(int *lts, int n){
    int *left = lts;
    int *right = lts + n - 1;

    return last_traverse_is_bst_inner(left, right);
}

int main(void){

    /* int a[] = {5, 7, 6, 9, 11, 10, 8}; */
    int a[] = {7, 4, 6, 5};
    int n = sizeof(a) / sizeof(a[0]);

    bool flag = last_traverse_is_bst(a, n);
    printf("FLAG %d\n", flag);
    return 0;
}
