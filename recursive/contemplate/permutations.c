//file name : permutations.c
//created at: Tue Jul  7 14:54:59 2015
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

int *visited;
char *res;
void permutations_inner(int n, int num, int idx){
    if(idx == n){
        printf("--%s--\n", res);
        return;
    }

    int i;
    for(i = 0; i < num; i++){
        /* if(visited[i]) continue; */ //this can be used to control whether the results is repeat numbers.
        visited[i] = 1;
        res[idx] = i + '0';
        permutations_inner(n, num, idx + 1);
        res[idx] = '\0';
        visited[i] = 0;
    }

    return;
}

void permutations(int n, int num){
    visited = malloc(sizeof(int) * num);
    memset(visited, 0, sizeof(int) * num);
    res = malloc(sizeof(char) * n);
    memset(res, 0, sizeof(char) * n);

    int idx = 0;
    permutations_inner(n, num, idx);

    return;
}

int main(void){
    int n = 5;
    int num = 10;
    permutations(n, num);

    return 0;
}
