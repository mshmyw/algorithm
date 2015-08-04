//file name : unique-bst.c
//created at: Thu Jun 25 21:33:53 2015
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
        printf("%3d\n", a[i]);

    printf("\n");

    return;
}

#define N 10
int sum[N];

//do you know how to think, slow to fast, simple to complex
void unique_bst(int n){
    sum[0] = 1;
    sum[1] = 1;
    int i, j;

    for(i = 2; i < n; i++){
        int cur_sum = 0;
        for(j = 0; j < i; j++)
            cur_sum += sum[j] * sum[i - (j + 1)];
        sum[i] = cur_sum;
    }

    printf("hello");
    print(sum, N);
}

int main(void){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    unique_bst(N);

    return 0;
}
