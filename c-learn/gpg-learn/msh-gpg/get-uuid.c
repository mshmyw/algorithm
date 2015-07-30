//file name : get-uuid.c
//created at: Thu Jul 30 14:57:25 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <uuid/uuid.h>

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

int main(void){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    uuid_t uuid;
    char str[36];
    memset(str, 0, sizeof(str));
    uuid_generate(uuid);
    uuid_unparse(uuid, str);
    printf("%d==%s==\n", strlen(str), str);

    return 0;
}
