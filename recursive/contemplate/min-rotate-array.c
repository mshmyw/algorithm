//file name : min-rotate-array.c
//created at: Fri Aug 21 15:35:54 2015
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

void inorder_search(int *pleft, int *pright){
    int *p;
    int min_num = *pleft;
    for(p = pleft + 1; p <= pright; p++)
        min_num = min(min_num, *p);

    printf("MIN_VALUE %d\n", min_num);
    return;
}

void min_rotate_array_inner(int *pleft, int *pright){
    if(pleft > pright){
        printf("SEARCH FAILED\n");
        return;
    }

    if(pright - pleft == 1){
        printf("MIN VALUE %d\n", *pright);
        return;
    }

    int *pmid = pleft + (pright - pleft) / 2;
    if(*pleft == *pmid && *pmid == *pright)
        inorder_search(pleft, pright);
    else if(*pmid >= *pleft) //left
        min_rotate_array_inner(pmid, pright);
    else if(*pmid <= *pright) //right
        min_rotate_array_inner(pleft, pmid);
    return;
}
void min_rotate_array(int *a, int n){

    min_rotate_array_inner(a, a + n - 1);
    return;
}
int main(void){

    /* int a[] = {3, 4, 5, 6, 7, 8, 1, 2}; */
    int a[] = {1, 0, 1, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    min_rotate_array(a, n);

    return 0;
}
