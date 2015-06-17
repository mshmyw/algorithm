//file name : get-common-item-from-two-set.c
//created at: Wed Jun 17 10:10:25 2015
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

void get_common_item(int *a, int m, int *b, int n){
    int htable[256];
    memset(htable, 0, sizeof(htable));
    int i;
    for(i = 0; i < m; i++)
        htable[a[i]] = 1;
    for(i = 0; i < n; i++)
        if(htable[b[i]])
            printf("%3d", b[i]);

    return;
}
int main(void){

    int a[] = {234, 3, 4, 9, 32, 7, 8, 5};
    int m = sizeof(a) / sizeof(a[0]);
    int b[] = {1, 234, 10, 4, 9, 6, 2, 8, 32};
    int n = sizeof(b) / sizeof(b[0]);

    get_common_item(a, m, b, n);

    return 0;
}
