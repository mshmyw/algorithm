//file name : scramble-string.c
//created at: Fri Jun 26 09:59:53 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

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

void print(char *a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%c", a[i]);

    printf("\n");

    return;
}

void num_length(int n, int *length){
    assert(n > 0);

    *length = 0;
    while(n){
        n = n / 10;
        *length = *length + 1;
    }


}

int is_repeat_num(int n, int length){

    char *str_n = malloc(sizeof(char) * length);
    memset(str_n, 0, sizeof(char) *length);
    int i;
    int tmp = n;

    for(i = length - 1; i >= 0; i--, tmp = tmp /10)
        str_n[i] = tmp % 10 + '0';

    if((*str_n == '\0') || (*(str_n + 1) == '\0'))
        return -1;

    for(i = 0; i < length - 1; i++)
        if(str_n[i] == str_n[i + 1]){
            free(str_n);
            return i;
        }

    free(str_n);
    return -1;
}

int min_unrepeat_num_inner(int n){
    int i, length;
    num_length(n, &length);

    i = is_repeat_num(n, length);
    if(i == -1){
        printf("--answer   : %d--\n", n);
        return n;
    }

    n = n + (int)pow(10, length - (i + 2));
    return min_unrepeat_num_inner(n);
}

void  min_unrepeat_num(int n){
    int i, length;
    num_length(n, &length);
    printf("--question : %d--\n", n);
    i = is_repeat_num(n, length);
    if(i == -1)
        n = n + 1;
    min_unrepeat_num_inner(n);

    return;
}

int main(void){

    int a[] = {1, 123, 9899, 100100, 54899, 6622, 71988, 8241};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    for(i = 0; i < n; i++)
        min_unrepeat_num(a[i]);

    return 0;
}
