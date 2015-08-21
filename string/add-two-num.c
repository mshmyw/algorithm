//file name : add-two-num.c
//created at: Tue Jul 14 13:52:57 2015
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

void add_two_num(int a, int b){

    int c;
    while(1){
       c  = a^b;
       b = (a & b) << 1;
       if(!b)
           break;
       a = c;
    }

    printf("c %d\n", c);
    return;
}
int main(void){
    int a = 213, b = 44;
    add_two_num(a, b);

    return 0;
}
