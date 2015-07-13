//file name : last-num-in-circle.c
//created at: Sun Jul 12 17:18:16 2015
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

int last_num_in_circle_recur(int n, int step){
    if(n == 1)
        return 0;

    return (last_num_in_circle_recur(n - 1, step) + step) % n;
}

int last_num_in_circle_iter(int n, int step){
    int i, last_num;
    last_num = 0; // n = 1

    for(i = 2; i <= n; i++)
        last_num = (last_num + step) % i;

        return last_num;
}

void  last_num_in_circle(int n, int step){
    assert(n > 0 && step > 0);

    int last_num;
    last_num = last_num_in_circle_recur(n, step);
    printf("last_num recur %d\n", last_num);

    last_num = last_num_in_circle_iter(n, step);
    printf("last_num iter %d\n", last_num);

    return;
}


int main(void){

    int n = 6;
    int step = 2;
    last_num_in_circle(n, step);

    return 0;
}
