//file name : longest-increase-sub.c
//created at: Thu Aug  6 16:00:34 2015
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

#define N 8
void longest_increase_sub(int *num, int n){
    assert(num && n > 0);
    int i, j;
    int res[N];
    for(i = 0; i < N; i++)
        res[i] = 1;

    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            if(num[i] > num[j])
            res[i] = max(res[i], res[j] + 1);

    print(res, n);
    int lis_len = res[0];
    for(i = 1; i < N; i++)
        lis_len = max(lis_len, res[i]);
    printf("LIS LEN %d\n", lis_len);
    return;
}

int main(void){
    int a[] = {1, -1, 2, -3, 4, -5, 6, -7};
    int n = sizeof(a) / sizeof(a[0]);

    longest_increase_sub(a, n);
    return 0;
}
