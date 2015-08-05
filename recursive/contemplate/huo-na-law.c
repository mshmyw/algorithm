//file name : huo-na-law.c
//created at: Wed Aug  5 15:05:51 2015
//author:  root
/* destination: use the huo na law to calcu the poly multi */

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

int huo_na_law_recur(int *factor, int n, int i, int x){
    if(i == (n + 1))
        return 0;

    return huo_na_law_recur(factor, n, i + 1, x) * x + factor[i];
}

void huo_na_law_tail_recur(int *factor, int n, int x, int *res){
    if(n < 0)
        return;

    *res = (*res) * x + factor[n]; //must have this state
    huo_na_law_tail_recur(factor, n - 1, x, res);
    return;
}

void huo_na_law_iter(int *factor, int n, int x, int *res){
    int pn = 0;

    while(n != -1)
        pn = pn * x + factor[n--];

    *res = pn;
    return;
}

void huo_na_law(int *factor, int n, int x, int *res){

    huo_na_law_iter(factor, n - 1, x, res);
    printf("iter RES %d\n", *res);

    *res = huo_na_law_recur(factor, n - 1, 0, x);
    printf("recur RES %d\n", *res);

    int tmp_res = 0; //init value must be zero
    huo_na_law_tail_recur(factor, n - 1, x, &tmp_res);
    *res = tmp_res;
    printf("tail recur RES %d\n", *res);

    return;
}

int main(void){

    int factor[] = {3, 1, 2};
    int n = sizeof(factor) / sizeof(factor[0]);
    int res = -1;
    int x = 2;
    huo_na_law(factor, n, x, &res);

    return 0;
}
