//file name : print-1-to-n.c
//created at: Sun Aug 23 15:29:32 2015
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

char *res;
void print_1_to_n_inner(int n, int i){
    if(i == n + 1){
        printf("--%s--\n", res + 1);
        return;
    }

    int j;
    for(j = 0; j <= 9; j++){
        res[i] = j + '0';
        print_1_to_n_inner(n, i + 1);
    }

    return;
}

void print_1_to_n(int n){
    res = (char *)malloc(sizeof(char) * (n + 1));
    memset(res, 0, sizeof(char) * (n + 1));
    print_1_to_n_inner(n, 1);

    free(res);
    res = NULL;
    return;
}

int main(void){
    int n = 4;
    print_1_to_n(n);
    return 0;
}
