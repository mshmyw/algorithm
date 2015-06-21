//file name : jump-game.c
//created at: Thu Jun 18 21:00:21 2015
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

bool jump_game(int *a, int  n){

    int i;
    assert(a && n);
    int max_step = a[0];  //local max, greed

    for(i = 1; i < n; i++){
        if(max_step == 0)  //max_step's i max is n - 2
            return false;

            max_step--;
            max_step = max(max_step, a[i]); // i's max == n - 1
    }

    return true;
}

int main(void){

    int a[2][5] = {{2, 3, 1, 1, 4}, {3, 2, 1, 0, 4}};
    int n = 2;
    int m = 5;
    int i = 0;
    bool flag;

    for(i = 0; i < n; i++){
       flag = jump_game(a[i], m);
       if(flag)
           printf("true\n");
       else
           printf("false\n");
    }

    return 0;
}
