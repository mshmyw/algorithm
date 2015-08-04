//file name : odd-even.c
//created at: Mon Jun 15 09:58:30 2015
//author:  msh

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

void odd_even_inner(int *a, int left, int right){

    int last_odd_pos = -1;
    int i;
    for(i = left; i <= right; i++)
        if(a[i] & 1){ //odd
            last_odd_pos++;
            swap(&a[last_odd_pos], &a[i]);
        }

    printf("last odd (%d %d)\n", last_odd_pos, a[last_odd_pos]);

    return;
}

void odd_even(int *a, int n){

    assert(a && (n > 0));
    odd_even_inner(a, 0, n - 1);

    print(a, n);

    return;
}

int main(void){

    int a[] = {1,10,3,4,5,6,7,8,2,9};
    
    int n = sizeof(a) / sizeof(a[0]);

    odd_even(a, n);
    return 0;
}
