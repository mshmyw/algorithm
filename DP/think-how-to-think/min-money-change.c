//file name : min-money-change.c
//created at: Wed Jul  1 20:56:23 2015
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

void print1(int *a, int n){
    int i;

    for(i = 0; i < n; i++)
        printf("%d\t", i);
    printf("\n");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\n");

    return;
}

void print(int a[], int n){
    int i;

    for (i = 0; i < n; i++){
        printf("(%3d %3d)  ", i, a[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
    printf("\n");

    return;
}

void min_money_change(int *value, int count, int money){
    assert(value);

    int i, j;
    int cur_min_kinds;
    int *min_kinds = malloc(sizeof(int) * (money + 1));
    memset(min_kinds, 0, sizeof(int) * (money + 1));

    int min_value = value[0];
    for(i = 1; i < min_value; i++)
        min_kinds[i] = -1;  // when money less min_value, but not equal zero, means no way.
    min_kinds[0] = 0; // 0 dollors have zero ways.

    for(i = min_value; i <= money; i++){
        cur_min_kinds = money + 1;
        for(j = 0; (j < count) && (i - value[j] >= 0); j++)
            if(min_kinds[i  - value[j]] != -1)
                cur_min_kinds = min(cur_min_kinds, min_kinds[i - value[j]] + 1);

        if(cur_min_kinds == money + 1) //no solution
            cur_min_kinds = -1;
        min_kinds[i] = cur_min_kinds;
    }

    printf("min_value %d\n", min_value);
    print(min_kinds, money + 1);
    free(min_kinds);
    return;
}
int main(void){
    int value[] = {3, 5, 10, 22, 26}; //before dp, the value must have the right sequence: from small to big.
    /* int value[] = {3, 5}; //before dp, the value must have the right sequence: from small to big. */
    int n = sizeof(value) / sizeof(value[0]);

    int total_money = 63;

    min_money_change(value, n, total_money);

    return 0;
}
