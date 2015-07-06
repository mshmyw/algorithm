//file name : fibonacci.c
//created at: Mon Jul  6 16:22:53 2015
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

int fibonacci_org(int n){
    if(n <= 0) return 0;

    if(n == 1) return 1;

    return fibonacci_org(n - 1) + fibonacci_org(n - 2);
}



int *res;
int fibonacci_dp_inner(int n){
    if(n <= 0) return res[0] = 0;

    if(n == 1) return res[n] = 1;

    if(res[n]) return res[n];

    return res[n] = fibonacci_dp_inner(n - 1) + fibonacci_dp_inner(n - 2);;
}

int fibonacci_dp(int n){
    res = malloc(sizeof(int) * (n + 1));
    memset(res, 0, sizeof(int) * (n + 1));

   return  fibonacci_dp_inner(n);
}

int main(void){

    int n = 10;

    int res_org = fibonacci_org(n);
    printf("--%d--\n" , res_org);

    int res_dp = fibonacci_dp(n);
    printf("--%d--\n" , res_dp);

    return 0;
}
