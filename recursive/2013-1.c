//file name : 2013-1.c
//created at: Mon Jun 15 16:38:10 2015
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

void min_count_2013_1(int n, int *count){
    if(n == 1)
        return;

    *count = *count + 1;

    if(n & 1)
        min_count_2013_1(n - 1, count);
    else
        min_count_2013_1(n / 2, count);

    return;
}

int main(void){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    int num = 2013;
    int count = 0;
    min_count_2013_1(num, &count);
    printf("min_count %d\n", count);

    return 0;
}
