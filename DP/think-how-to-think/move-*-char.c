//file name : move-*-char.c
//created at: Thu Jul  2 15:00:35 2015
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

void move_asterisk_char(char *str){
    assert(str);

    int left = -1;
    int i = 0;

    for(i = 0; str[i] != '\0'; i++)
        if(str[i] == '*'){
            left++;
            /* swap(&str[left], &str[i]); */
            char tmp = str[left]; str[left] = str[i]; str[i] = tmp;
    }

    printf("--%s--\n", str);
    return;
}
void print(int *a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%3d", a[i]);

    printf("\n");

    return;
}

int main(void){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    char str[] = "*abc*mn*pq";
    move_asterisk_char(str);

    return 0;
}
