//file name : pop-stack-ways.c
//created at: Tue Aug  4 08:23:53 2015
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
        printf("%6d", a[i]);

    printf("\n");

    return;
}

//in fact it's a catalan number f(n) = C(2*n, n)/(n + 1)
void pop_stack_ways(int n){
    if(n <= 0)
        return;
    int *ways = malloc(sizeof(int) * (n + 1));
    if(ways == NULL)
        return;
    ways[0] = 1;
    ways[1] = 1;
    int i, j, tmp_ways;
    for(i = 2; i <= n; i++){
        tmp_ways = 0;
        for(j = 0; j < i; j++)
            tmp_ways += ways[j] * ways[i - j - 1];
        ways[i] = tmp_ways;
    }

    print(ways, n + 1);
    return;
}

int main(void){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    pop_stack_ways(n);

    return 0;
}
