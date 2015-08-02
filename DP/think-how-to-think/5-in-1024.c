//file name : 5-in-1024.c
//created at: Tue Jun 30 16:14:12 2015
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

void five_in_1024(int n, int *count){
    if(n == 1)
        return;
    int tmp = n;
    while((tmp % 5) == 0){
        *count = *count + 1;
        tmp = tmp / 5;
    }

    five_in_1024(n - 1, count);
}

int main(void){

    int n = 1024;
    int count = 0;
    five_in_1024(n, &count);

    printf("count %d\n", count);

    return 0;
}
