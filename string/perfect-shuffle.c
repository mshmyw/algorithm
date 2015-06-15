//file name : perfect-shuffle.c
//created at: Mon Jun 15 14:07:09 2015
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

void perfect_shuffle1(int *a, int n){
    int length = n * 2;
    int i;
    int *b = (int *)malloc(sizeof(int) * (length + 1));
    memset(b, 0, sizeof(int) * (length + 1));

    print(a, 2 * n + 1);
    for(i = 1; i <= length; i++)
        b[(2 * i) % (length + 1)] = a[i];

for(i = 1; i <= length; i++)
    a[i] = b[i];

 print(a, 2 * n + 1);

 free(b);
 b = NULL;
 return;
}

int main(void){
    int a[] = {0, 2, 4, 6, 8, 1, 3, 5, 7};
    int n = sizeof(a) / sizeof(a[0]);

    perfect_shuffle1(a, n / 2);

    return 0;
}
