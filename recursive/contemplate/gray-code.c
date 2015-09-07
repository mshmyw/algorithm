//file name : gray-code.c
//created at: Mon Sep  7 09:00:54 2015
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

void gray_code_recur(int n, int i, char **p){ // i bits gray
    if(i == 0){
        return;
    }

    gray_code_recur(n, i - 1, p); // i - 1 bits gray

    int k;
    for(k = 0; k < (1 << ( i - 1)); k++) // from i - 1 got front i - 1 bits gray
        p[k][n - i] = '0';
    for(; k < (1 << i); k++){ // from i - 1 got i bits gray
        memcpy(p[k], p[k - (1 << (i - 1))], (n + 1)); //copy i - 1 bits
        p[k][n - i] = '1'; // got last i - 1 bits
    }

    return;
}

void gray_code(int n){
    char **p = (char **)malloc(sizeof(char *) * (1 << n));
    int i;
    for(i = 0; i < ( 1 << n); i++){
        p[i] = (char *)malloc(sizeof(char) * (n + 1));
        memset(p[i], 0, sizeof(char) * (n + 1));  //NOTE HERE, must here do the memset, not after for
    }
    /* memset(p, 0, sizeof(char) * n * (cnt + 1)); // here memset is wrong, think why???*/

    gray_code_recur(n, n, p);

    for(i = 0; i < (1 << n); i++)
        printf("%s\n", p[i]);
    for(i = 0; i < (1 << n); i++)
        free(p[i]);
    free(p);
    return;
}

int main(void){

    int n = 8;
    gray_code(n);
    return 0;
}
