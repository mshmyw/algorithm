//file name : permutaion.c
//created at: Mon Aug 24 16:13:39 2015
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

#define N 64
char res[N];
bool visited[N];
void str_permutaion_inner(const char *str, int k){
    if(str[k] == '\0'){
        res[k] = '\0';
        printf("-%s-\n", res);
        return;
    }

    int i;
    for(i = 0; str[i] != '\0'; i++)
        if(!visited[i]){
            visited[i] = true;
            res[k] = str[i];
            str_permutaion_inner(str, k + 1);
            visited[i] = false;
        }

        return;
}

void str_permutaion(const char *str){

    str_permutaion_inner(str, 0);
    return;
}

int main(void){

    const char *str = "abcdefg";
    str_permutaion(str);
    return 0;
}
