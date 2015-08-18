//file name : add-sub.c
//created at: Mon Aug 17 22:09:00 2015
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

char sym[] = {'+', '-', ' '};
int op[10];
int count = 0;
int sum = 0;
void compute_inner(int num, int idx, int lastidx, int last_sum, int *out_sum){
    if(num == 9){
        if(op[lastidx] == 0)
            *out_sum = *out_sum + last_sum;
        else if(op[lastidx] == 1)
            *out_sum = *out_sum - last_sum;

        return;
    }

    if(op[idx] == 2){ //current op is ' '
        last_sum = last_sum * 10 + num + 1;
        compute_inner(num + 1, idx + 1, lastidx, last_sum, out_sum);
        return;
    }

    //current op is '+' or '-'
    if(op[lastidx] == 0)
        *out_sum = *out_sum + last_sum;
    else if(op[lastidx] == 1)
        *out_sum = *out_sum - last_sum;
    lastidx = idx;
    last_sum = num + 1;
    compute_inner(num + 1, idx + 1, lastidx, last_sum, out_sum);
    return;
}

void compute(int sym_idx, int *out_sum){
    int num, idx, lastidx, last_sum;
    num = 1; idx = 1; lastidx = 0; last_sum = num;
    *out_sum = 0;
    compute_inner(num, idx, lastidx, last_sum, out_sum);
    return;
}

void add_sub_sum_inner(int num, int sym_idx, int x){
    if(num == 9){
        int sum = -1;
        compute(sym_idx, &sum);
        if(sum == x){
            print(op, sym_idx);
            count++;
        }

        return;
    }

    int k;
    for(k = 0; k < 3; k++){
        op[sym_idx] = k;
        add_sub_sum_inner(num + 1, sym_idx + 1, x); //add
    }
    return;
}

void add_sub_sum(int n, int x){
    int num, sym_idx;
    num = 1; sym_idx = 1;
    op[0] = 0;
    add_sub_sum_inner(num, sym_idx, x);
    return;
}

int main(void){
    int n, x;
    n = 9;
    x = 5;
    add_sub_sum(n, x);
    printf("-COUNT-%d-\n", count);
    return 0;
}
