//file name : sub-max-multi.c
//created at: Mon Aug 10 20:24:35 2015
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

//get the max multi of n - 1 nums in n
void sub_max_multi(int *num, int n){
    int *forward = malloc(sizeof(int) * n);
    int *reverse = malloc(sizeof(int) * n);
    int res;
    memset(forward, 0, sizeof(int) * n);
    memset(reverse, 0, sizeof(int) * n);

    int i;
    forward[0] = num[0];
    for(i = 1; i < n; i++)
        forward[i] = forward[i - 1] * num[i]; //forward traverse
    reverse[n - 1] = num[n - 1];
    for(i = n - 2; i >= 0; i--)
        reverse[i] = reverse[i + 1] * num[i]; // reverse traverse
    res = reverse[1];
    for(i = 1; i < n - 1; i++)
        res = max(res, forward[i - 1] * reverse[i + 1]);
    res = max(res, forward[i]);

    printf("RES -%d-\n", res);

    free(forward);
    forward = NULL;
    free(reverse);
    reverse = NULL;

    return;
}
int main(void){

    int a[] = {1, 2, 3, -3, 5, 4, 0, -7};
    int n = sizeof(a) / sizeof(a[0]);

    sub_max_multi(a, n);
   return 0;
}
