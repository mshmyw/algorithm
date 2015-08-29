//file name : unique-sample.c
//created at: Wed Jun 17 20:30:08 2015
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
#define M 5

int s[M];

bool is_exist(int t){
    int i;
    for(i = 0; i < M; i++)
        if(s[i] == t)
            return true;

    return false;
}

int rand_int(double left,  double right){
    int T;
    T = left + (int)(right * rand()/(RAND_MAX+1.0));
    /* printf("T %d--", T); */
    return T;
}

void unique_sample(int n, int m){
    if(m == 0)
        return;
    unique_sample(n - 1, m - 1);
    int t = rand_int(1, n);
    if(is_exist(t))
        s[m - 1] = n;
    else
        s[m - 1] = t;

    return;
}

int main(void){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    srand((int)time(0));
    memset(s, 0, sizeof(s));
    unique_sample(N, M);
    print(s, M);
    return 0;
}
