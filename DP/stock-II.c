//file name : stock-II.c
//created at: Thu Jun 25 16:15:02 2015
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

#define N 10
int max_pt[N];
int min_pc[N];

void max_profit(int *a, int n){

    memset(max_pt, 0, sizeof(max_pt));
    memset(min_pc, 0, sizeof(min_pc));

    min_pc[0] = a[0];
    max_pt[0] = 0;
    int i;
    for(i = 1; i < n; i++){
        min_pc[i] = min(min_pc[i - 1], a[i]);
        max_pt[i] = max(max_pt[i - 1], a[i] - min_pc[i]);
    }

    print(min_pc, n);
    print(max_pt, n);
    return;
}
int main(void){

    int a[] = {1, 3, 4, 2, 5, 8, 7, 6};
    int n = sizeof(a) / sizeof(a[0]);

    max_profit(a, n);
    return 0;
}
